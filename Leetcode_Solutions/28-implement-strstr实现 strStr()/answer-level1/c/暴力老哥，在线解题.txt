### 解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int i , count=0 ;
    int lenhaystack = strlen(haystack);
    int lenneedle = strlen(needle); 
    
    if(!lenneedle && !lenhaystack)return 0;
    if(!lenneedle)return 0;
    if(!lenhaystack)return -1;
    if(lenneedle > lenhaystack)return -1;
    for(i =0 ; i <= lenhaystack-lenneedle ; i++){
        count=0;
        if(*(haystack+i) ==  *(needle+count)){
            while(*(haystack+i+count) == *(needle+count) ){
                if(*(needle+count+1)=='\0')return i;
                count++;
            }
        }
    }
    return -1;
}
```