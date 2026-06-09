### 解题思路
gcd求解所有数的最大公约数

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b){
        int c = a%b;
        while(c != 0){
            a = b;
            b = c;
            c = a % b;
        }
        return b;
    }


    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(int val : deck){
            if(mp.find(val) == mp.end()){
                mp[val] = 1;
            }else{
                mp[val]++;
            }
        }
        int res = mp.begin()->second;
        for(auto it : mp){
            res = gcd(res, it.second);
        }
        return res >= 2;
    }
};
```