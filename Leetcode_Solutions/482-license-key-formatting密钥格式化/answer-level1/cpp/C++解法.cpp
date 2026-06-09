### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // num 作为每个部分的字符个数标记， 比如第一个部分，当string 中字符 %4 ！=0 ， 第一个num 就可以使得第一部分至少为1且不为K 
        int num = K - (S.size()-count(S.begin(), S.end(), '-')%K);
        string res = "";
        for(auto ch:S){
            if(ch == '-') continue;
            if(num == 0 && res!="") res+= '-';

            res += toupper(ch);
            num = (num+1)%K;
        }
        return res;
    }
};
```