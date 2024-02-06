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
    
    void findInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }

    TreeNode* inorderToBST(vector<int>& inorder, int s, int e){
        if(s > e){
            return NULL;
        }

        int m = s + (e-s)/2;
        TreeNode* root = new TreeNode(inorder[m]);
        root->left = inorderToBST(inorder,s,m-1);
        root->right = inorderToBST(inorder,m+1,e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root,inorder);
        int n = inorder.size();
        return inorderToBST(inorder,0,n-1);
    }
};
