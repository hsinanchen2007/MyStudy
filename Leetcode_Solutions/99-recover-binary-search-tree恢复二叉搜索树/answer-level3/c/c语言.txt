		void recur(struct TreeNode* root, unsigned int* retAttr, unsigned int* returnSize) 
		{
			if (root == NULL) {
				return;
			}
		
			recur(root->left, retAttr, returnSize);
			retAttr[(*returnSize)++] = root->val;
			recur(root->right, retAttr, returnSize);
			return;
		}
		
		void newcur(int* retAttr, struct TreeNode* root, int retA, int retB, int* returnSize) 
		{
			if (root == NULL) {
				return;
			}
		
			newcur(retAttr, root->left, retA, retB, returnSize);
			if (*returnSize == retA) {
				(*returnSize)++;
				root->val = retAttr[retA];
			} else if (*returnSize == retB) {
				(*returnSize)++;
				root->val = retAttr[retB];
			} else {
				(*returnSize)++;
			}
		
			newcur(retAttr,root->right, retA, retB, returnSize);
			return;
		}
		
		void findNode(int *retAttr, int* retA, int* retB, int returnSize) {
			unsigned int tmpAttr[returnSize];
		
			int i;
			for (i = 0; i < returnSize; i++) {
				tmpAttr[i] = retAttr[i];
			}
		
			for (i = 0; i < returnSize; i++){
				int j;
				int temp = 0;
				for (j = 0; j < returnSize - i; j++) {
					if (j + 1 == returnSize) {
						continue;
					}
					if (retAttr[j] > retAttr[j+1]) {               
						temp = retAttr[j];
						retAttr[j] = retAttr[j+1];
						retAttr[j+1] = temp; 
					}
				}
			}
		
			int flag = 0;
			for (i = 0; i < returnSize; i++) {
				if (retAttr[i] != tmpAttr[i]) {
					if (flag == 0) {
						*retA = i;
						flag = 1;
					} else {
						*retB = i;
					}
				}
			}
		}
		
		void recoverTree(struct TreeNode* root){
			unsigned int* retAttr = (unsigned int *)malloc(sizeof(int) * 10000);
			unsigned int* returnSize = (unsigned int *)malloc(sizeof(int));
			*returnSize = 0;
			recur(root, retAttr, returnSize);
		
			int* retA = (int *)malloc(sizeof(int));
			int* retB = (int *)malloc(sizeof(int));
			*retA = -1;
			*retB = -1;
			findNode(retAttr, retA, retB, *returnSize);
		
			*returnSize = 0;
			newcur(retAttr, root, *retA, *retB, returnSize);
		
			free(returnSize);
			free(retAttr);
			free(retA);
			free(retB);
		}