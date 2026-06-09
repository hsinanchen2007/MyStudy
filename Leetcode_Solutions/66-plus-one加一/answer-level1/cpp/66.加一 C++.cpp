### 解题思路
1.遵行十进制，逢十进一。
2.现在个位加一并模10，取余，若不为0则没有进位，可以直接返回数组，若为0则表示有进位，需要向前一位在做同样的步骤2。
3.若循环到底均全为0则表示需要在最高位进一则新建一个长度比原先数组长1位的数组，在数组首位数字设为1,最后再返回此数组。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i = len - 1; i >=0;i--){
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0){
                return digits;
            }
        }
        
        vector<int> result(len + 1);
        result[0] = 1;
        return result;
    }
};
```