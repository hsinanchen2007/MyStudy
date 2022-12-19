# 思路
- 生成格雷码序列，见 [维基百科](https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81)


**二进制转换成格雷码**
（假设以二进制为0的值做为格雷码的0）
G：格雷码 B：二进制码 n：正在计算的位
根据格雷码的定义可得：
G(n) = B(n+1) XOR B(n)
即
G(n) = B(n+1) + B(n)
自低位至高位运算即可，无需考虑进位，例略。

```
十进制　格雷码 二进制
0  　　 000    000
1  　　 001    001
2   　　011    010
3   　　010    011
4   　　110    100
5   　　111    101
6   　　101    110
7   　　100    111
```

- 通过三次反转进行旋转数组

# 复杂度分析
时间复杂度：O(n)
空间复杂度：O(n)

```
class Solution {
public:
    vector<int> circularPermutation(int width, int start) {
        vector<int> ans;
        int n = pow(2, width), p = 0;
        for(int i = 0; i < n; ++i) {
            ans.push_back(i ^ (i >> 1));
            if ((i ^ (i >> 1)) == start) p = i;
        }
        reverse(ans.begin(), ans.begin() + p);
        reverse(ans.begin(), ans.end());
        reverse(ans.begin(), ans.begin() + n - p);
        return ans;
    }
};
```