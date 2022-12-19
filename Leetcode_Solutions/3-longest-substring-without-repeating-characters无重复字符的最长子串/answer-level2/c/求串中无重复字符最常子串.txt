//思路，暴力解法，使用含128个元素的一维数组记录串中字母出现的次数，
//出现大于一次则重复，重复则回溯指针，输出最长串
```
void clear(int a[]){
    for(int i = 0;i<128;i++)a[i] = 0;
}
int lengthOfLongestSubstring(char * s){
    int arr[128] = {0};
    int len = 0;        //当前长度
    int maxLen = 0;     //最大长度
    while(*s!='\0'){
        if(++arr[*s]>1){
            if(maxLen<len)maxLen = len;
            s-=len;
            clear(arr);
            len = 0;
        }else{
            len++;
        }
        s++;
    }
    if(maxLen<len)maxLen = len;
    return maxLen;
}
```
