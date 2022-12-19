### 解题思路
首先分类讨论，负数的回文数一定不等于其本身，0的回文数就是其本身，剩下所有情况就通过“整数反转”后再判断。
最后有一点很重要，输入的x是int型，因此count必须是大于int取值范围的类型，否则数据会溢出，因此选long作为count类型。

### 代码

```c
bool isPalindrome(int x){
    long count=0;
    int pre=x;
    if(x<0){
        return false;
    }
    else if(x==0){
        return true;
    }
    else{
        while(x!=0){
            count=count*10+x%10;
            x=x/10;
        }
        if(count==pre){
            return true;
        }
        else{
            return false;
        }
    }
}
```