### 解题思路
重点：
1、对数字的按位平方和计算。 
2、读题：关键在于最后和为1即是happy number，如果不存在则会陷入循环———检测到以前出现过的数字则算失败，所以记录历史并能查询是关键。。

### 代码

```cpp
class Solution {
public:
    bool isHappy(int n) {
        vector<int> history = {n} ;
        while(n != 1){
            n = count(n);
            if(find(history.begin(), history.end(), n) != history.end())return false;
            history.push_back(n);
        }
        return true;
    }
    int count(int x){
        int sum = 0;
        while(x){
            sum += pow(x % 10,2);
            x = x / 10 ;
        }
        return sum;
    }
};
```