### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(int *a,int *b){
   char s[100],s1[100];
   sprintf(s,"%d%d",*a,*b);
   sprintf(s1,"%d%d",*b,*a);
   return strcmp(s1,s);
}
char * largestNumber(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    if(nums[0]==0) return "0";
    char *s,*p;
    s=(char*)malloc(sizeof(char)*1000);
    p=s;
    for(int i=0;i<numsSize;i++){
        sprintf(p,"%d",nums[i]);
        p+=strlen(p);
    }
    return s;
}
```