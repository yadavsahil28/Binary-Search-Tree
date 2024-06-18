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
    class Info{
        public:
        int mini;
        int maxi;
        int sum;
        bool isBST;
        
        Info(){
            
        }
        
        Info(int a, int b, int c, bool d){
            mini = a;
            maxi = b;
            sum = c;
            isBST = d;
        }
        
    };

    Info solve(TreeNode* root, int& ans){
        if(root == NULL){
            return Info(INT_MAX,INT_MIN,0,true);
        }

        Info leftAns = solve(root->left,ans);
        Info rightAns = solve(root->right,ans);

        Info curr;
        curr.sum = leftAns.sum + rightAns.sum + root->val;
        curr.mini = min(root->val,leftAns.mini);
        curr.maxi = max(root->val,rightAns.maxi);

        if(leftAns.isBST && rightAns.isBST && (root->val > leftAns.maxi && root->val < rightAns.mini)){
            curr.isBST = true;
        }
        else{
            curr.isBST = false;
        }

        if(curr.isBST){
            ans = max(ans, curr.sum);
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;    
    }
};
