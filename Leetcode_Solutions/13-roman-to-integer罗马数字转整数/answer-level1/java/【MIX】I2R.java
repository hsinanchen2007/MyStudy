### 解题思路
建立映射表转换

### 代码

```java []
class Solution {
    public int romanToInt(String s) {
        int res = 0;
        for(int i=0; i<s.length(); ++i){
            res += R2N(s.charAt(i));
            if(i>0 && R2N(s.charAt(i)) > R2N(s.charAt(i-1)))
                res -= 2*R2N(s.charAt(i-1));
        }

        return res;
    }

    private int R2N(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default: return 0;
        }
    }
}
```
```python []
class Solution:
    def romanToInt(self, s: str) -> int:
        # 建立映射表
        rec = {
            'I': 1,
            'IV':4,
            'V': 5,
            'IX':9,
            'X':10,
            'XL':40,
            'L':50,
            'XC':90,
            'C':100,
            'CD':400,
            'D':500,
            'CM':900,
            'M':1000
        }

        res = 0
        i = 0
        while i < len(s):
            if i+1<len(s) and s[i:i+2] in rec.keys():
                res += rec[s[i:i+2]]
                i+=2
            else:
                res += rec[s[i]]
                i+=1

        return res
```
```c++ []
class Solution {
public:
    int romanToInt(string s) {
        map<string, int> REC;
        REC["I"] = 1;
        REC["IV"] = 4;
        REC["V"] = 5;
        REC["IX"] = 9;
        REC["X"] = 10;
        REC["XL"] = 40;
        REC["L"] = 50;
        REC["XC"] = 90;
        REC["C"] = 100;
        REC["CD"] = 400;
        REC["D"] = 500;
        REC["CM"] = 900;
        REC["M"] = 1000;

        int i=0;
        int res = 0;
        string str;
        int N = s.size();
        while(i < N){
            if(i < N-1){
                str = string(1, s[i])+string(1, s[i+1]);
            }
            if(REC.count(str)!=0){
                res += REC[str];
                i+=2;
                str = "";
            }else{
                // char -> string
                res += REC[string(1, s[i])];
                i++;
            }
        }
        return res;
    }
};
```