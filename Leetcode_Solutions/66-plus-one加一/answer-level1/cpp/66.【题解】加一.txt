### 解题思路
首先，最后一位加一，当最后一位结果不大于9时，直接就是结果；
若最后一位结果大于9，为10，将该位的数字置0，然后往前进行循环判断是否进位；
最后，如果第一位为9，得到的首位为0，使用reverse函数将其倒置，然后在末尾push_back(1)，再reverse即可。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n;
        n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            digits[i]++;
            if(digits[i]<=9) break;
            else
            {
                digits[i]=0;
            }
        }
        if(digits[0]==0)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};
```