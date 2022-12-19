### 解题思路
首先区分出两个string，一个长string一个短string分别记做maxString和minString。

我们将计算结果存储到maxString中。

先反向遍历，从低位开始计算，计算maxString和minString重合的部分。

然后只遍历maxString多出来的部分，此时只需要计算maxString和flag的和。

最后考虑最高位有没有进位。如果遍历完maxString之`后flag > 0`说明还需要进位。这时候只需要在maxString前面加"1"

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size();
        int bLen = b.size();
        int flag = 0;

        // 用来存储较长的string
        string maxString;
        // 用来存储较短的string
        string minString;
        int maxLen;
        int minLen;

        if(aLen > bLen){
            maxString = a;
            maxLen = aLen;
            minString = b;
            minLen = bLen;
        }
        else{
            minString = a;
            minLen = aLen;
            maxString = b;
            maxLen = bLen;

        // 反向遍历，先计算后minLen位
        for(int i = 0; i < minLen; ++i){
            // 长的maxString加短的String加flag，因为ASCII码存储，所以-'0'
            maxString[maxLen - 1 - i] += (minString[minLen - 1 - i] - '0' + flag);
            // 整除2记录flag，表示是否进位
            flag = (maxString[maxLen - 1 - i] - '0') / 2;
            // 对2取模
            maxString[maxLen - 1 - i] = ((maxString[maxLen - 1 - i] - '0') % 2 + '0');
        }
        // 这时候只剩下较长的String
        for(int i = minLen; i < maxLen; ++i){
            maxString[maxLen - 1 - i] += flag;
            
            flag = (maxString[maxLen - 1 - i] - '0') / 2;
            maxString[maxLen - 1 - i] = ((maxString[maxLen - 1 - i] - '0') % 2 + '0');
        }
        // 如果最后flag > 0,说明还需要进位，那么要在String开头增加一个'1'
        if(flag > 0) maxString = '1' + maxString;

        return maxString;
    }
};
```