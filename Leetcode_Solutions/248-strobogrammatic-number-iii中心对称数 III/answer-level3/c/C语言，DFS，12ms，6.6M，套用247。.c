**执行用时12ms，内存6.6M。
套用中心对称数2(递归只用递归出一半，另外一半通过前面一半翻转180°得到，这样可以少很多运算。另外如果位数是基数，则正中间必须是0, 1, 8)，主要是排除范围外的分支。这里只考虑比最高位，只递归比最小的最高位大且比最大的最高位小的数。比较大小使用了strcmp。
注：
1.可能出现输入LOW比HIGH大的情况，返回0
2.范围内包括边界，比如[69,80]，69也属于结果**


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

 void dfs(char *nums, int n, int first, int* returnSize, char * low, char * high) {
    if (first == n/2) {
        if (n % 2 != 0) {
            for (int j = 0; j < 3; j++) {
                nums[n/2] = g_Nums2[j];
                
                CopyNums(nums, n);
                if (n == strlen(low) && n == strlen(high)) {
                    if (strcmp(nums, low) >=0 && strcmp(nums, high) <= 0) {
                        (*returnSize)++;
                    }
                } else if (n == strlen(low) && n < strlen(high)) {
                    if (strcmp(nums, low) >=0) {
                        (*returnSize)++;
                    }
                } else if (n > strlen(low) && n == strlen(high)) {
                if (strcmp(nums, high) <= 0) {
                    (*returnSize)++;
                }
                } else {
                    (*returnSize)++;
                }
            }
        } else {
            CopyNums(nums, n);
            
            if (n == strlen(low) && n == strlen(high)) {
                if (strcmp(nums, low) >=0 && strcmp(nums, high) <= 0) {
                    (*returnSize)++;
                }
            } else if (n == strlen(low) && n < strlen(high)) {
                if (strcmp(nums, low) >=0) {
                    (*returnSize)++;
                }
            } else if (n > strlen(low) && n == strlen(high)) {
                if (strcmp(nums, high) <= 0) {
                    (*returnSize)++;
                }
            } else {
                (*returnSize)++;
            }
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (first == 0 && i == 0 && n != 1) {
            continue;
        }

        nums[first] = g_Nums[i];
        
        /* 裁剪分支，比最高位大小 */
        if (first == 0 && n == strlen(low)) {
            if (low[0] > nums[first]) {
                continue;
            }
        }

        if (first == 0 && n == strlen(high)) {
            if (high[0] < nums[first]) {
                continue;
            }
        }

        if (n % 2 != 0) {
            if ((first == n/2) && (g_Nums[i] != '1' && g_Nums[i] != '8' && g_Nums[i] != '0')) {
                continue;
            }
        }

        dfs(nums, n , first + 1, returnSize, low, high);
    }
 }
int strobogrammaticInRange(char * low, char * high){
    int lowlen = strlen(low);
    int highlen = strlen(high);
    int returnSize = 0;

    if (highlen < lowlen) {
        return 0;
    }

    if (highlen == lowlen) {
        if (strcmp(low, high) > 0) {
            return 0;
        }
    }

    char *nums = (char *)malloc(sizeof(char) * (highlen+1));
    
    nums[lowlen] = '\0';
    nums[highlen] = '\0';

    for (int i = lowlen; i <= highlen; i++) {
        dfs(nums, i, 0, &returnSize, low, high);
    }
    
    return returnSize;

}
```
