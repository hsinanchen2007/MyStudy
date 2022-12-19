### 解题思路
这道题其实就是斐波那契数列的求解，我们可以将这个问题转化为
fib(n)=fib(n-1)+fib(n-2);
如上式所示，爬到第n阶方法数其实可以转化为第(n-1)阶的方法数和第(n-2)阶方法数之和。
这样就成了一个自上而下的递归问题。
![QQ截图20200313204104.png](https://pic.leetcode-cn.com/6f2457dd836291cd1629e3d8ea0490e06ca9432ebe5c30f584990d5aaec11c42-QQ%E6%88%AA%E5%9B%BE20200313204104.png)
由上图，我们改完自下而上的思考方式。
初始化：f表示第0阶的方法数为0，g表示第1阶的方法数为1。
然后上至二楼，此时g=g+f(也就是fib(2)=fib(0)+fib(1)),f=g-f(fib(1)=fib(2)-fib(0))
将以上两个式子归纳一下：fib(n)=fib(n-2)+fib(n-1);fib(n-1)=fib(n)-fib(n-2);
即g为fib（n-1），f为fib(n-2)，所以代码完成了从{(n-2)=0,(n-1)=1}这一初始条件的自下而上迭代过程。
由于参数g，f的更新与n无关，所以虽然while中是n--，其实与for(i=0;i<n;i++)实则无异，此处只是追求代码更简。


### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f=0,g=1;
        while(0<n--)
        {
            g=g+f;
            f=g-f;
        }
        return g;
    }

};
```