### 解题思路
    罗马数字中4、9、40、90等特殊数字只会有一个位置的字符值小于后面的那个字符值，所以可以由左向右开始，若当前位置代表的值大于后一位置代表的值则减去当前值，其他情况累加字符值即可。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mymap;
        mymap['I']=1;
        mymap['V']=5;
        mymap['X']=10;
        mymap['L']=50;
        mymap['C']=100;
        mymap['D']=500;
        mymap['M']=1000;
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(i+1 < s.size()){
                if(mymap[s[i]] < mymap[s[i+1]]){
                    res -= mymap[s[i]];
                    continue;
                }
            }
            res += mymap[s[i]];
        }
        return res;
    }
};
```