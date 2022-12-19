
## 数位dp

考虑1出现在第i位的次数

以2出现的次数进行分析，换成1同样的思路

![计数问题解题思路](https://pic.leetcode-cn.com/422510f7bb9872b15f65d732d56b0546ae71e141e70b47fd7e8010cad373a628.png)

## 代码实现

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        string num = to_string(n);
        int ans = 0;
        int k = getW(n);
        for (int i = 0; i< k; i++){
            int m = num[i] - '0';
            int p = i, q = k - i -1;
            if (m > 1) { // 当前位大于1 时
                int back = pow(10, q); // 后半段可能性 
                int front = 1 + n / pow(10, q+1); // 前半段可能性 [0,前半段的值)
                ans += front * back;
            } else if (m == 1){
                ans += n % (int)pow(10, q) + 1; // 前半部分相等，求后半部分的可能性
                int front = n / pow(10, q + 1); // 前半部分 小于当前数时，前半段取值的可能性
                int back = pow(10, q); // 前半部分 小于当前数时，后半段取值的可能性
                ans += front * back;
            } else {// 当前位小于1 时
                int front = n / pow(10, q+1); // 前半段取值 [0,前半段的值)
                int back = pow(10, q);// 后半段的可能性
                ans += front * back;
            }
        }
        return ans;
    }

    int getW(int x){
        if (x== 0) return 0;
        if (x <10) return 1;
        return getW(x/10) + 1;
    }
};
```

[从零开始学算法](https://muyids.github.io/simple-algorithm/)