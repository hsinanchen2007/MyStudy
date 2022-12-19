### 解题思路

从末位向前逐位模拟十进制加法器，首位进行单独判断

ps:末位为9产生进位的情况其实概率应该是较低的，采用一个if循环，若末位没进位直接return 结果

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i=digits.size()-1;i>=0;i--)
        {
            ++digits[i];

            if(digits[i]!=10)        //如果该位没有继续产生进位,则直接return 结果
                return digits;
            else
                digits[i]=0;        //进位
        }
        digits.insert(digits.begin(), 1);       //如果首位也产生进位,才会执行到这条语句，否则循环中已经return了
        return digits;
    }
};
```