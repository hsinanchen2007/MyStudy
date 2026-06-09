就是简单的反转函数然后用在bool函数里边，但是我把new-num定义为int，当测试用例是0的时候，会提示我内存溢出，但是我在vs里不会出现这个情况，求大佬解答


### 代码

```c
bool isPalindrome(int x)
{
    int n;
    int s;
    s=x;
    double new_num;
    new_num=0;
    while(s!=0)
    {   
        n=s%10;
        new_num=n+new_num*10;
        s=s/10;
    }
 if(new_num==x && x>0 ||x==0)
    return true;
 else
    return false;
}
```