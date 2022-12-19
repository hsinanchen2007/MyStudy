### 解题思路
此处撰写解题思路
使用数组计数，再遍历数组，如果为偶数，则计数变量cnt加上这个数，如果为奇数，则标志flag=1,计数变量cnt加上这个数再减一；最后通过判断flag的值得知是否有奇数存在，如有， cnt++;
### 代码

```c
int longestPalindrome(char * s){
    int a[150]={0}, i, cnt=0, flag=0;
    for(i=0;s[i]!='\0';i++){
        a[s[i]]++;
    }
    for(i=0;i<150;i++){
        if(a[i]>0 && a[i]%2==0) {
            cnt+=a[i];
            a[i]=0;
        }
        if(a[i]%2!=0)
        {
            flag=1;
            cnt+=a[i]-1;
        }
    }
   if(flag==1) cnt++;
    return cnt;
}
```