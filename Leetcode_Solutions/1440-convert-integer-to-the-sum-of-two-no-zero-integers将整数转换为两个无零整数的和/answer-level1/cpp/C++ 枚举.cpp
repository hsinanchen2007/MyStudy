### 解题思路


### 代码

```cpp
class Solution {
public:
    bool noZeroInt(int num) 
    {
        while (num > 9) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> res;
        int left = 1;
        int right = n - 1;
        while (left <= right) {
            int leftNoZero = noZeroInt(left);
            int rightNoZero = noZeroInt(right);
            if (leftNoZero && rightNoZero) {
                res.push_back(left);
                res.push_back(right);
                break;
            } else {
                right--;
                left++;
            }
        }
        return res;
    }
};
```