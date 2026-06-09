思路

罗马数字不考虑组合的情况下是从左向右以此递增，如果一个小的出现在大的右面，一定是大减小。
所以从右向左，记录最大值，遇见大于等于最大值的加，遇见小于的减。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size()-1;
        int res=0,MAX=INT_MIN;
        map<string,int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        for(n;n>=0;n--){
            string tmp = s.substr(n,1);
            if(m[tmp]>=MAX){
                res+=m[tmp];
                MAX=m[tmp];
            }else{
                res-=m[tmp];
            }
        }
        return res;
    }
};
```