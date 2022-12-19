```
 void helper(struct TreeNode* root, double* sum, double* count, int index, int* head){
     if(root==NULL){
        return;
    }
    sum[index] += root->val;
    count[index]++;
    (*head) = fmax(*head, index);
    helper(root->left, sum, count, index+1, head);
    helper(root->right, sum, count, index+1, head);
 }
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int NUM = 10000;
    double* sum = (double*)calloc(NUM, sizeof(double));
    double* count = (double*)calloc(NUM, sizeof(double));

    int head = 0;
    helper(root, sum, count, 0, &head);
    double* ret = (double*)malloc((head+1)*sizeof(double));
    for(int i=0; i<head+1; i++) {
        ret[i] = sum[i]/count[i];
    }
    *returnSize = head+1;
    return ret;
}
```
