### 解题思路
1. 从左往右扫描`bills`
2. 若扫描到5美元，没什么好说的，不用找零
3. 若扫描到10美元，判断下是否有五美元的可以找零，若没有，返回`false`
4. 若扫到20美元的，优先找出（假如有）一张10美元的零钱(**贪心思想**)，之后剩下的找零用5美元补足，最后判断是否有足够的5美元钞票可以找零！若没有返回`false`
5. 若扫描完`bills`之后都没有返回`false`，则返回`true`
### 代码

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.empty()) return true;
        unordered_map<int, int> mp;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) mp[5] ++;
            else if(bills[i] == 10){
                mp[5] --;
                mp[10] ++;
                if(mp[5] < 0) return false;
            }
            else if(bills[i] == 20){
                int tmp = 15;
                if(mp[10] > 0){
                    tmp -= 10;
                    mp[10] --;
                }
                while(tmp > 0){
                    tmp -= 5;
                    mp[5] --;
                }
                if(mp[5] < 0) return false;
            }
        }
        return true;
    }
};
```