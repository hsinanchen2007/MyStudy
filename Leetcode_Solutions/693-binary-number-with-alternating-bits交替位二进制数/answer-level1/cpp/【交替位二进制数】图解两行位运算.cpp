### 思路
1. 一开始没读懂题，不明白什么叫交替位数，菜哭了
2. 正如题目所说，就是他的二进制数相邻的两个位数永不相等
3. 参考前辈们的 [【c++ 位运算 两行解法】](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/solution/c-wei-yun-suan-liang-xing-jie-fa-by-bo-luo-miao-w/) [【两行解法】](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/solution/c-by-hong-hu/)

### 图解
<![图片.png](https://pic.leetcode-cn.com/f5a4675dbc04af0df31854c13f2c9006ebc4826e96af364f20b5ebf5cb825e2f-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/53b690ec1b2537ef557bdcd33e36298169ff960411c6cb711f8ebc1234e8a86e-%E5%9B%BE%E7%89%87.png)>

### 答题
```C++ []
class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        n = (n ^ (n >> 1));
        return (n & ((long)n + 1)) == 0;
    }
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

