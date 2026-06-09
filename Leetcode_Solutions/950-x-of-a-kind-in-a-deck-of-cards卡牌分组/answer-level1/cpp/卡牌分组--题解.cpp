### 解题思路
1、用哈希表统计每个数字出现的次数
2、求出出现最小的次数
3、从2开始遍历，如果都能整除，则返回true,如果找不到则返回false

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1){
            return false;
        }

        bool flag = true;
        unordered_map<int, int> deckmap;
        unordered_map<int, int>::iterator it;
        for(int c : deck){
            deckmap[c]++;
        }
        int min = 20000;
        for(it = deckmap.begin();it != deckmap.end();it++){
            if(it->second < min){
                min = it->second;
            }
        }
        if(min <=1){
            return false;
        }
        for(int i = 2;i<=min;i++){
            flag = true;
            for(it = deckmap.begin();it != deckmap.end();it++){
                if(it->second % i != 0){
                   flag = false;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        

        return flag;

    }
};
```