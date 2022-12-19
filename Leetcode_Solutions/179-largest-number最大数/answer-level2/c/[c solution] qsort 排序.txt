### 解题思路

思路都一致，实现参考了这个
[https://leetcode-cn.com/problems/largest-number/solution/pai-xu-by-yuan-fei-yu-yue/](https://leetcode-cn.com/problems/largest-number/solution/pai-xu-by-yuan-fei-yu-yue/)
### 代码

```c
int cmp(int* a , int* b){
    char s1[1024] , s2[1024];
    sprintf(s1,"%d%d" , *a , *b);
    sprintf(s2,"%d%d" , *b, *a);
    return strcmp(s2 , s1);
}


char * largestNumber(int* nums, int numsSize){
    if(numsSize <= 0){
        return "";
    }
    qsort(nums , numsSize,sizeof(int) , cmp);
    if(nums[0] == 0){
        return "0";
    }
    char* ch , *s;
    ch = (char*)malloc(sizeof(char)*(1024));
    s = ch;
    int idx = 0;
    for(int i = 0 ; i < numsSize ; i++){
        sprintf(s , "%d" , nums[i]);
        s += strlen(s);
    }
    return ch;
}
```