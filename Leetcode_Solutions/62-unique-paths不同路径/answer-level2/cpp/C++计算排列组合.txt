题目主要是**排列组合**，机器人总共需要向下走m-1步，向右n-1步，转化为数学问题就是在m+n-2个空格中寻找m-1个向下走，次数就是求`C(m+n-2)(m-1)`的结果。
接下来的问题，就是如何求。如果直接求`(m+n-2)!`的结果，很容易超出`int`限制，所以使用double来储存，最后再将其转化为`int`输出。
    ![image.png](https://pic.leetcode-cn.com/cb6c70680c6ce94f3ce9d75e2c61c7c8aa032f741956c2b75dd78ddcdbaefbe5-image.png)



```
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num=1;
        for(int i=1;i<m;i++){
            num *= (i+n-1);
            num /= i;
        }
        int ans=int(num);
        return(ans);
    }
};
```
