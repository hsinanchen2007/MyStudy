竖式乘法

两个一位数字相乘最多为两位，对10求模得低位，对10求商得高位

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        string ret(m + n, '0');  // 所有的进位初始化为 '0'
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // 进位和乘积的和，当前要加上上一步计算的进位
                int sum = (ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                ret[i + j + 1] = (sum % 10) + '0';  // 保存当前计算的数字(低位)
                ret[i + j] += sum / 10;  // 更新当前进位(高位)
            }
        }

        // 从第一个不为 '0' 的字符开始是有效结果或者结果是个位数
        for (int i = 0; i < ret.length(); i++) {
            if (ret[i] != '0' || i == ret.length() - 1)
                return ret.substr(i);  // 从 i 到最后的子字符串
        }
        return "0";
    }
};
```

- 时间复杂度: $O(m*n)$
- 空间复杂度 : $O(m + n)$