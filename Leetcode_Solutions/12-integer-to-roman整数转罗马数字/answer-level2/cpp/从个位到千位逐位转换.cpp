### 解题思路
首先分别存储1,4,5,9在各个位数的字符串
然后从个位开始转换数字。

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        if(num > 0){
            string s1[4] = {"I", "X", "C", "M"};
            string s5[4] = {"V", "L", "D"};
            string s4[3] = {"IV", "XL", "CD"};
            string s9[3] = {"IX", "XC", "CM"};
            
            int tmp = num, i = 0;
            while(tmp != 0){
                int a = tmp % 10;
                string b = "";
                if(a==4){
                    b = s4[i];
                }else if(a==9){
                    b = s9[i];
                }else if(a>=1 && a<5){
                    for(int j=0; j<a; ++j)
                        b += s1[i];
                }else if(a>=5){
                    b = s5[i];
                    for(int j=0; j<a-5; ++j)
                        b += s1[i];
                }
                result = b + result;
                ++i;
                tmp /= 10;
            }
        }
        return result;
    }
};
```