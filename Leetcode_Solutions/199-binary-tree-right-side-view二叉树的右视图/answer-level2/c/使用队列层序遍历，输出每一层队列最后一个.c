        int* rightSideView(struct TreeNode* root, int* returnSize){
            int max = 50000;
            *returnSize = 0;
            int* retArr = (int*)malloc(sizeof(int) * max);
            if (root == NULL) {
                return retArr;
            }
            struct TreeNode* Queue[max]; //层序遍历，选取每一层的最后一个
            int begin = 0, end = 0;
            Queue[end++] = root;
            while (end > begin) {
                int tmpEnd = end, j;
                for (j = begin; j < tmpEnd; j++) {
                    if (j + 1 == tmpEnd) {
                        retArr[(*returnSize)++] = Queue[j]->val;
                    }
                    if (Queue[j]->left != NULL) {
                        Queue[end++] = Queue[j]->left;
                    }
                    if (Queue[j]->right != NULL) {
                        Queue[end++] = Queue[j]->right;
                    }
                }
                begin = tmpEnd;
            }
            return retArr;
        }