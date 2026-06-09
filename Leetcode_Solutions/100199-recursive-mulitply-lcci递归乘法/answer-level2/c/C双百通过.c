  乘法的实质就是加法，例如 2*3等价于2+2+2.
![QQ图片20200325170751.png](https://pic.leetcode-cn.com/2b7b8bb61649d24c72c3bb133d1229ae3ad799bbde2ebbdf3913da585215bd2a-QQ%E5%9B%BE%E7%89%8720200325170751.png)
**代码：**
```
C
int multiply(int A, int B){
    int result;
    
    if (B > 1)
    result = multiply(A, B - 1) + A;
    else
    result = A;

    return result;
}
```




