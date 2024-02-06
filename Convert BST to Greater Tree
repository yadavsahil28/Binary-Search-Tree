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
    void solve(TreeNode* root, int& data){
        if(root == NULL){
            return;
        }
        solve(root->right,data);
        root->val += data;
        data = root->val;
        solve(root->left,data);
    }
    TreeNode* convertBST(TreeNode* root) {
        int data = 0;
        solve(root,data);
        return root;
    }
};
