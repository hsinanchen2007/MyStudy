题解：
1.找到字符串中的运算符，将字符串S分割成A和B；
2.递归求解A和B的所有可能结果，遍历求得A和B的所有结果根据运算符计算后的结果；
3.递归终止条件：字符串中已经没有运算符，将字符串转换成数字输出；
![image.png](https://pic.leetcode-cn.com/ca68ff6e6551015843694966fc0eebe5c668a17420fde72f3b12bbb8b2554a1a-image.png)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* diffWaysToCompute(char * input, int* returnSize){
    if(input == NULL){
        *returnSize = 0;
        return NULL;
    }
    
    int len = strlen(input);
    char *lstr = (char *)calloc(len, sizeof(char));
    char *rstr = (char *)calloc(len, sizeof(char));

    int mid = 0;
    int retcnt = 0;
    int calflag = 0;
    int *ret = (int *)calloc(1, sizeof(int));
    while(mid < len){
        if(input[mid] >= '0' && input[mid] <= '9'){
            mid++;
            continue;
        }

        calflag = 1;
        memcpy(lstr, input, mid);
        lstr[mid] = '\0';
        memcpy(rstr, input+mid+1, len-mid-1);
        rstr[len-mid-1] = '\0';

        int lsize = 0;
        int rsize = 0;
        int *lret = diffWaysToCompute(lstr, &lsize);
        int *rret = diffWaysToCompute(rstr, &rsize);

        int *retmp = (int *)realloc(ret, (retcnt+lsize*rsize)*sizeof(int));
        if(retmp == NULL){
            return NULL;
        }
        ret = retmp;
        for(int i = 0; i < lsize; i++){
            for(int j = 0; j < rsize; j++){
                switch(input[mid]){
                    case '+':
                        ret[retcnt++] = lret[i]+rret[j];
                        break;
                    case '-':
                        ret[retcnt++] = lret[i]-rret[j];
                        break;
                    case '*':
                        ret[retcnt++] = lret[i]*rret[j];
                        break;
                    default:
                        break;
                }
            }
        }
        mid++;       
    }

    if(calflag == 0){
        *returnSize = 1;
        ret[0] = atoi(input);
        return ret;
    }

    *returnSize = retcnt;
    return ret;
}