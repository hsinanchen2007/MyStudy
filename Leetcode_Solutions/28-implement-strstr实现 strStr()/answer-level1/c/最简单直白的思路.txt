### 解题思路
此处撰写解题思路

### 代码

```c
// 首先，需要记录合适的索引作为返回值。
// 其次，需要遍历子串1中是否有和2完全匹配的子串，那这就需要遍历2的每一位
// 假设遍历2的每一位时,1字符串的索引也需要同步增长；
// 不匹配时，还需要退回1刚才那个索引处；所以此处需要保留一个值记录1此次开始比较的位置
// 所以需要两个for循环，其次可以剪枝，当1剩余的长度已经小于2了，就不用匹配了

int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    // 异常情况的处理
    if(haystack==NULL || needle==NULL || (len1<len2)) {
        return -1;
    }
    if(len2==0) {
       return 0; 
    }

    int ret = -1; // 最终返回的索引，初始值赋予-1
    int p = 0; // 用于1递增的去遍历自身
    int flag = -1; // 作为是否包含的标志。
    for(int i = 0; i< (len1 - len2 + 1); i++) { // 剪枝，子串1只用遍历到 len1-len2即可
        p = i;
        for(int j = 0;j<len2;j++) { // 每次都要完整的遍历一遍2，才知道是否完全匹配
            if(haystack[p] != needle[j]) {
                flag = -1;
                break;
            } else {
                flag = 0;
                p++;
            }
        }
        if(flag==0) {
            ret = i;
            break; // 这里不要忘了break
        }

    }
    return ret;
}
```