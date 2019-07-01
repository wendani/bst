/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool __isValidBST(struct TreeNode* root, int *lower, int *upper) {
	if (!root)
		return true;

	if ((lower) && (root->val <= *lower))
		return false;

	if ((upper) && (root->val >= *upper))
		return false;

	if (__isValidBST(root->left, lower, &root->val))
		return __isValidBST(root->right, &root->val, upper);
	else
		return false;
}

bool isValidBST(struct TreeNode* root) {
	return __isValidBST(root, NULL, NULL);
}
