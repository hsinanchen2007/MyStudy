### 解题思路
从最低位开始,4 9 分别讨论, 然后反转字符串.

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        char RomanC[7] = {'I','V','X','L','C','D','M'};
        int i = 0;
        string res;
        while(num){
            int target = num%10;
            if(target == 4){
                res.push_back(RomanC[i+1]);
                res.push_back(RomanC[i]);
            } else if (target == 9){
                res.push_back(RomanC[i+2]);
                res.push_back(RomanC[i]);
            } else {
                int k = target%5;
                while(k--)res.push_back(RomanC[i]);
                if(target/5)res.push_back(RomanC[i+1]);
            }
            i += 2;
            num /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```