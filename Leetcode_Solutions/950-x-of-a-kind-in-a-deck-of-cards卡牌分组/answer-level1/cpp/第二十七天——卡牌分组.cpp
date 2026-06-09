### 解题思路
常规思路，找到不同元素个数的最大公约数，如为1，返回false，否则返回true

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        stack<int> card;

        for(auto num:deck){
            if(0 == mp[num]) card.push(num);
            mp[num]++;
        }
        int res = mp[card.top()];
        card.pop();
        while(!card.empty()){
            int tmp = mp[card.top()];
            res = gcd(res, tmp);
            card.pop();
        }
        if(res == 1) return false;
        else return true;    
    }
    int gcd(int a, int b){
        if(a%b == 0) return b;
        else return gcd(b, a%b);
    }
};
```