### 解题思路
Sunday算法
refer：https://leetcode-cn.com/problems/implement-strstr/solution/python3-sundayjie-fa-9996-by-tes/

### 代码

```c

int strStr(char * haystack, char * needle){
    int needleLen = strlen(needle);
    int sLen = strlen(haystack);

    if(needleLen==0) return 0;
    if(needleLen>sLen) return -1;

//    int *idxarr = (int *)malloc(sizeof(int)*130);
	int idxarr[130] = {0};
//    memset(idxarr,-1,sizeof(int)*130);
    int i=0;
    for(i=needleLen-1;i>-1;i--){
        int k = needle[i];
        if(*(idxarr+k) == 0){
            *(idxarr+k) = needleLen - i;
        }
    }
    
    int idx =0;
    while((idx+needleLen)<= sLen){
        for(i=0;i<needleLen;i++){
            
            if(needle[i]!=haystack[idx+i]){
                
                if((idx+needleLen)>= sLen){
                    return -1;
                }
                int cur = haystack[idx+needleLen];
                if(idxarr[cur] != 0){
                    idx += idxarr[cur];
                }else{
                    idx += (needleLen + 1);
                }
                break;
            } 
            if(i==(needleLen-1)){
                return idx;
            }     
        }
    }
    if((idx+needleLen)>= sLen){
        return -1;
    }else{
        return idx;
    }
}

```