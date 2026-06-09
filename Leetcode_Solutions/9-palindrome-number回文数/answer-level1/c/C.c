### 解题思路
存数组里比直接算更慢
![捕获.PNG](https://pic.leetcode-cn.com/b99f3b3988ded3f4b681a38d1afc6437d27ad8f7384c1ea8fd7046180ff59c6f-%E6%8D%95%E8%8E%B7.PNG)
直接算是8ms+5.4MB

### 代码

```c
bool isPalindrome(int x){
    if(x<0) return false;
    int a[1024]={0},flag=1,i=0,j=0;
    while(x>0){
        a[i]=x%10;
        i++;
        x/=10;
    }
    for(;j<i;j++){
        if(a[j]!=a[i-1-j]){
            flag=0;
        }
    }
    return flag?true:false;
}
```