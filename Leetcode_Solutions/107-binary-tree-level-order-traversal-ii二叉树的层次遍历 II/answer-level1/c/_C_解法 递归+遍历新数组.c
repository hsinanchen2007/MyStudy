# **代码思路：**
（1）运用递归按顺序把结点的数字和数字所对应的层数拿出放入预先已经准备好的两个数组
（2）创建用于返回的新数组

# **代码：**
```
int  getting_the_numbers_out(struct TreeNode* root,  int** numbers,int**level, int currentlevel, int* count, int* defaultlen);

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

        int defaultlen = 1,
        *numbers = malloc(sizeof(int)*defaultlen), 
        *levelarra = malloc(sizeof(int)*defaultlen),
        count = 0, 
        max;

    max = getting_the_numbers_out(root, &numbers,&levelarra,0,&count,&defaultlen);
  
    int *eachlevel, currentlevelnumber,
        *returnColumn = (int*)malloc(sizeof(int) * (max+1)),
        **returnarra = (int**)malloc(sizeof(int*) * (max+1));
    
    for(int i = max; i >= 0; i--){
        
        defaultlen = 5;
        currentlevelnumber = 0;
        eachlevel = (int*)malloc(sizeof(int) * defaultlen);
        
        for(int j = 0; j < count;j++){
            
            if(currentlevelnumber + 1 >= defaultlen){
                defaultlen=defaultlen * 2;
                eachlevel = realloc(eachlevel, sizeof(int)*defaultlen);
            }
            if(levelarra[j] == i){
                eachlevel[currentlevelnumber++] = numbers[j];
            }
        }
        returnColumn[max-i] = currentlevelnumber;
        returnarra[max-i] = eachlevel;
    }

    *returnColumnSizes = returnColumn;
    *returnSize = max + 1;
    return returnarra;
}

int  getting_the_numbers_out(struct TreeNode* root,  int** numbers,int**level, int currentlevel, int* count, int* defaultlen){
    
    if(root == NULL){
        return currentlevel - 1;
    }

    int left,
        right;

    left = getting_the_numbers_out(root->left, numbers,level, currentlevel+1, count, defaultlen);

    if(*count + 1 >= *defaultlen){
        *defaultlen = (*defaultlen) * 2;
        *numbers= realloc(*numbers,sizeof(int) * (*defaultlen));
        *level = realloc(*level,sizeof(int) * (*defaultlen));
    }

    *(*numbers + (*count)) = root->val;
    *(*level + (*count)++) = currentlevel;

    right = getting_the_numbers_out(root->right, numbers, level, currentlevel + 1, count, defaultlen);

    return (right > left? right:left);
}
}
```
