### 解题思路
这题属于简单题，不需要用到复杂的数据结构与算法。利用罗马数字计数时抓住一个核心：只需要将所有罗马字符代表的数字大小相加即得到最终结果，不需要按照十进制计数的逻辑进行换算。于是马上想到，或许用一个for循环，做累加求和即可，自然会想到用map完成字符到整数的映射。
```
for(int i=0;i<len;i++){
    sum += 'RomanChar'
}
map<char,int> mp;
mp['I'] = 1,...,mp['M']=1000;
```
但是罗马字符计数时又有一些特殊规则，于是需要一些变化，暴力求解的角度，我们在for循环中碰到的每个字符，都进行一个判断，判断其是否构成了特殊规则的一种，这样就不难得到下面的代码。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        // set up a map from string to int
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        // 
        int len = s.length();
        int temp = 0;
        for(int i=0;i<len;i++){
            if(i<len-1){
                if(s[i]=='I' && s[i+1]=='V'){
                    temp += 4;
                    i++;
                }else if(s[i]=='I' && s[i+1]=='X'){
                    temp += 9;
                    i++;
                }else if(s[i]=='X' && s[i+1]=='L'){
                    temp += 40;
                    i++;
                }else if(s[i]=='X' && s[i+1]=='C'){
                    temp += 90;
                    i++;
                }else if(s[i]=='C' && s[i+1]=='D'){
                    temp += 400;
                    i++;
                }else if(s[i]=='C' && s[i+1]=='M'){
                    temp += 900;
                    i++;
                }else{
                    temp += mp[s[i]];
                }
            }else{
                temp += mp[s[i]];
            }

        }
        return temp;
    }
};
```