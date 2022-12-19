### 解题思路
求汉明距离，即求两数不同位的数量。那么将两数做异或运算，即可得到两数不同位的位置。

例：9与7的汉明距离：
![1.png](https://pic.leetcode-cn.com/10b213b8a0a3e2cbda220006dfde5af624702cb6def4d4aed4b7ea0a56d565cc-1.png)

可知求9与7的汉明距离其实可以等同于求(9^7)的汉明权重。

代码如下。

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y, ans=0;
        while(temp!=0){
            ans++;
            temp&=temp-1;
        }
        return ans;
    }
};
```