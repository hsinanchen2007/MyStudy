### 解题思路
其实代码写得蛮清楚的，先重写低位值，然后按照加法算法去进位
特殊的就是使用了insert，本身具备O(n)的复杂度

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
            * 遍历方式
            * 时间复杂度  O(n)
        */
        
        // 先让最后一个数字+1
        int size = digits.size();
        digits[size-1] += 1;
        int carry = 0;

        // 进行进位
        for(int i=size-1; i>=0; i--)
        {
            // 加低位的进位
            digits[i] += carry;

            // 算进位
            carry = digits[i]/10;

            // 暂存进位前的值
            int temp = digits[i];

            // 算本位的值
            digits[i] = digits[i]%10;

            if(i == 0 && temp >= 10)
            {
                digits.insert(digits.begin(), carry);
            }
        }

        return digits;

    }
};
```