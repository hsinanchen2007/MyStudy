看了答案没怎么看懂，于是把自己结合其他题解的思路跟大家分享一下，这个应该比较好理解
![图片1.png](https://pic.leetcode-cn.com/b3a0eb7654dc87dbccac35c122275d418b39b17e2c01ce125c486d136b2bdd77-%E5%9B%BE%E7%89%871.png)
```
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;// 最后一轮(第n轮)，重新编号后最后剩余的编号
        for(int i=2;i<=n;i++){// 不断映射上一轮对应的编号
            ans = (ans+m)%i;
        }
        return ans;
    }
};
```


