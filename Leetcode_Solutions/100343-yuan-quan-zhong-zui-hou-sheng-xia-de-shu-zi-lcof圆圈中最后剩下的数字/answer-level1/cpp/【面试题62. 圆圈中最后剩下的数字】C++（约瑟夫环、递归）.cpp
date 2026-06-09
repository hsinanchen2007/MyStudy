### 解题思路
约瑟夫环--参考题解：[Java解决约瑟夫环问题，告诉你为什么模拟会超时！](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/)

思路：递归倒推最后所剩数字的原下标`res = (res+m)%i;`。
原因：`res`前有m个数字，当前剩`i`个数字，就可以推出来`res`的位置了。

### 代码

```cpp
class Solution {
    // 数学，递归，约瑟夫环
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2; i<=n; i++){
            res = (res+m)%i;
        }
        return res;
    }
};
```