### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x){
    int a[10]={0},i=0,j=0;
    if(x<0) return false; 
    if(x==0) return true;
    while(x){   //将x的每一位放入a数组
        a[i]=x%10;
        x/=10;
        i++;
    }
    i--;
    while(i!=j){
        if(a[i]==a[j]) ;
        else return false;
        if(i--==++j) break; //判断下一个j是否和当前i相等，相等则结束循环
    }
    return true;
}
```