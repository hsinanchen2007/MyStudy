### 解题思路

### 代码

```c
char str[100]={0},tmp[6];
char * itoa(int x);
char * optimalDivision(int* nums, int n){
    str[0]='\0';
    int i;
    char *p;
    if(n==1) return itoa(nums[0]);
    else if(n==2){
        p=itoa(nums[0]);
        strcat(str,p);
        strcat(str,"/");
        p=itoa(nums[1]);
        strcat(str,p);
        return str;
    }
    for(i=0;i<n;i++){
        p=itoa(nums[i]);
        strcat(str,p);
        if(i==0) strcat(str,"/(");
        else if(i==n-1) strcat(str,")");
        else strcat(str,"/");
    }
    return str;
}
char* itoa(int x){
    tmp[5]='\0';
    int i=4,t;
    while(x>0){
        t=x%10;
        tmp[i--]=t+'0';
        x/=10;
    }
    return tmp+i+1;
}
```