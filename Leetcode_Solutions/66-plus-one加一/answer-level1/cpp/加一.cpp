## 题解
### 算法分析
1. 公式：output[i] = (input[i] + flag) % 10, flag = input[i] / 10
2. 假设flag表示是否进位，1为进位，0为不进位
3. 倒序遍历数组，使用上述公式计算output，并计算flag
### 复杂度分析
- 时间复杂度：O(n)，n为Input长度
- 空间复杂度：O(1)，额外消耗：flag
### 源码
```C++ []
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output(digits.size(), 0);
        int flag = 1;

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int temp = digits[i] + flag;
            output[i] = temp % 10;
            flag = temp / 10;
        }

        if (flag != 0)
        {
            output.insert(output.begin(), flag);
        }

        return output;
    }
};
```