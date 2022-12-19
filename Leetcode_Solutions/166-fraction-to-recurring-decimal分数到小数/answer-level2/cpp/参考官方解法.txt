### 解题思路

### 代码

```cpp
class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        int flag1=1,flag2=1;
        if(numerator<0)flag1=-1;
        if(denominator<0)flag2=-1;
        if(!numerator)return "0";
        numerator = abs(numerator);
        denominator = abs(denominator);
        long y = numerator%denominator;
        long s = numerator/denominator;
        string res=to_string(s);
        if(flag1*flag2==-1)res = '-'+res;
        if(!y)return res;
        res+='.';
        int index = res.size();
        unordered_map<int,int>hash;
        while(y){
            if(hash.count(y)){
                res.insert(hash[y],"(");
                res.append(")");
                break;
            }
            res.append(to_string(10*y/denominator));
            hash[y]=index++;
            y*=10;
            y = y%denominator;
        }
        return res;
    }
};
```