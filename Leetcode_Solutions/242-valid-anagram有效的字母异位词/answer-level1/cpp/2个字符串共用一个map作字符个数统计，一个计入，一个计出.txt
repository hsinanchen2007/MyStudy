### 解题思路
遍历字符串s,累加各字符的个数到map,
再遍历t,从map中累减，过程中遇到map中不存在的字符，直接判false;
最后map为空则true，否则false


### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map1;

        for(auto it: s){
            map1[it]++;
        }

        for(auto it :t){
            if(map1.find(it)== map1.end() ){
                return false;
            }

            map1[it]--;
            if(0 == map1[it]){
                map1.erase(it);
            }
        }

        if( map1.empty() ){
            return true;
        }

        return false;
    }
};
```