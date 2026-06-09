		void recur(struct TreeNode* root, int sum, int** retArr, int* returnSize, int** returnColumnSizes, int* tmpArr, int index){
			if (root == NULL) {
				return;
			}
		
			tmpArr[index] = root->val;
			index++;
			if (sum == root->val && root->left == NULL && root->right == NULL) {
				retArr[*returnSize] = (int*)malloc(sizeof(int) * index);
				returnColumnSizes[0][*returnSize] = index;
				int i;
				for (i = 0; i < index; i++) {
					retArr[*returnSize][i] = tmpArr[i];
				}
				(*returnSize)++;
				return;
			}
		
		recur(root->left, sum - root->val, retArr, returnSize, returnColumnSizes, tmpArr, index);
		recur(root->right, sum - root->val, retArr, returnSize, returnColumnSizes, tmpArr, index);
		return;
		}
		int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
			int MAXLEN = 1000;
			int** retArr = (int**)malloc(sizeof(int*) * MAXLEN);
			*returnSize = 0;
			returnColumnSizes[0] = (int*)malloc(sizeof(int) * MAXLEN);
			memset(returnColumnSizes[0], 0, sizeof(int) * MAXLEN); 
			int columnSizes = 0;
			int tmpArr[MAXLEN];
			int index = 0;
			recur(root, sum, retArr, returnSize, returnColumnSizes, tmpArr, index);
		
			return retArr;
		}