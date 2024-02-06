/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int& preOrderIndex, int mini, int maxi){
        if(preOrderIndex >= preorder.size()){
            return NULL;
        }

        if(preorder[preOrderIndex] < mini || preorder[preOrderIndex] > maxi){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preOrderIndex++]);
        root->left = solve(preorder,preOrderIndex,mini,root->val);
        root->right = solve(preorder,preOrderIndex,root->val,maxi);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int preOrderIndex = 0;
        return solve(preorder,preOrderIndex,mini,maxi);
    }
};
