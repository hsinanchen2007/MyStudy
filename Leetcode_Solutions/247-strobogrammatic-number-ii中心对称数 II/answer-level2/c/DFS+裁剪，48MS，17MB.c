**DFS递归，只需要递归一半的数就可以，另外一半根据前面一半推出（即6换9,9换6，其他一样）。有效的的数字只有0, 1, 6, 8, 9。
注：
1.区分奇偶数，奇数的中间那位数字，只能是0, 1, 8
2.除了1位数，其他均不能以0开头，比如“00”，“001”**


```
char g_Nums[6] = "01689";
 char g_Nums2[4] = "018";

 void CopyNums(char *nums, int len) {
     int start = len/2 + 1;

     if (len % 2 == 0) {
         start = len / 2;
     }

     for (int i = len/2 - 1; i >= 0; i--) {
         nums[start] = nums[i];
         if (nums[i] == '9') {
             nums[start] = '6';
         }
         if (nums[i] == '6') {
             nums[start] = '9';
         }
         start++;
     }

     return;
 }

 void dfs(char *nums, int n, int first, char **r, int* returnSize) {
    if (first == n/2) {
        if (n % 2 != 0) {
            for (int j = 0; j < 3; j++) {
                nums[n/2] = g_Nums2[j];
                CopyNums(nums, n);
                r[*returnSize] = (char *)malloc(sizeof(char) * (n+1));
                memcpy(r[*returnSize], nums, sizeof(char) * (n+1));
                r[*returnSize][n] = '\0';
                (*returnSize)++;
            }
        } else {
            CopyNums(nums, n);
            r[*returnSize] = (char *)malloc(sizeof(char) * (n+1));
            memcpy(r[*returnSize], nums, sizeof(char) * (n+1));
            r[*returnSize][n] = '\0';
            (*returnSize)++;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (first == 0 && i == 0 && n != 1) {
            continue;
        }

        nums[first] = g_Nums[i];
        if (n % 2 != 0) {
            if ((first == n/2) && (g_Nums[i] != '1' && g_Nums[i] != '8' && g_Nums[i] != '0')) {
                continue;
            }
        }

        dfs(nums, n , first + 1, r, returnSize);
    }
 }
char ** findStrobogrammatic(int n, int* returnSize){
    char **r = NULL;
    char *nums = (char *)malloc(sizeof(char) * (n+1));

    nums[n] = '\0';
    *returnSize = 0;
    r = (char **)malloc(sizeof(char *) * 100000);

    dfs(nums, n, 0, r, returnSize);

    return r;
}
```
