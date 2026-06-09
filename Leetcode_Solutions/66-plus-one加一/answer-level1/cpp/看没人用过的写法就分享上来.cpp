### 解题思路
就是简单的末位加1，等于10就进一位，看了几个题解好像没有这种写法就分享上来，大家随便看看。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) {
            return std::vector<int>();
        }
        vector<int> vec;
        int tmpIndex = digits.size() - 1;
        digits[tmpIndex]++;
        while (digits[tmpIndex] == 10) {
            digits[tmpIndex] = 0;
            tmpIndex--;
            if (tmpIndex >= 0) {
                digits[tmpIndex]++;
            }
            else {
                vec.push_back(1);
                break;
            }
        }
        vec.insert(vec.end(), digits.begin(), digits.end());
        return vec;
    }
};
```