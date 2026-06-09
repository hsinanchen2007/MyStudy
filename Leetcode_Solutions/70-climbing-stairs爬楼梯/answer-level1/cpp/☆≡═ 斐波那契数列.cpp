1. 爬楼梯第一层有 1 种方法，第二层有 2 种方法。
2. 第三层可以从第 1 层跳两层到达，或者从第 2 层走一层到达。
3. 第 k 层可以从 第 k-1 层跳两层到达，或者从第 k-2 层走一层到达。
4. method[k] = method[k - 1] + method[k - 2] 形成了斐波那契数列。
5. 斐波那契数列解析解
![gif.latex.gif](https://pic.leetcode-cn.com/fd69312e18f1a9e86033d692e637be93376738e8e834833d9a9c8c1afb81b614-gif.latex.gif)
6. 可以使用浮点数计算解析解，然后四舍五入得到整数解。
7. 第二项很小可以忽略。
```
class Solution {
public:
    int climbStairs(int n) {
        const double s = sqrt(5);
        return floor(pow((1+s)/2,n+1)/s + 0.5);
    }
};
```
