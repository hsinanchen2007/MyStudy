### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string records[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int nlist[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s = "";
        int i;
        
            for(i = 0; i < sizeof(nlist); )
            {
                //计算(num - nlist[i]) > 0 时，不着急i++，对当前nlist[i]继续减， 大于0 则 i++;
                //例如：    58 - 1000 < 0  则 i++， 到了 58 - 50 > 0 时记录 s = “L”
                //         8 - 40 < 0    ...   8 - 5 > 0 记录s = "LV"
                //         3 - 4 < 0     ...   3 - 1 > 0     s = "LVI"  【continue】  
                //         s = "LVIII"
                if((num - nlist[i]) > 0)       
                {
                    s += records[i];
                    num -= nlist[i];
                    continue;
                }
                else if((num - nlist[i]) == 0)
                {
                    num = 0;
                    s += records[i];
                    break;
                }
                i++;
            }
            return s;
        
    }
};
```