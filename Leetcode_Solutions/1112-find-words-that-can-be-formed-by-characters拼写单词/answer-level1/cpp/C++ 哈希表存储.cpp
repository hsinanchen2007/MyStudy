### 解题思路


### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> map,tmp;
        for(int i = 0;i < chars.size();i++){
            ++map[chars[i]];
        }
        int res = 0;
        for(auto str : words){
            bool flag = true;
            tmp = map;
            for(auto x : str){
                if(!tmp[x]) {
                    flag = false;
                    break;
                }
                --tmp[x];
            }
            if(flag) res += str.size();
        }
        return res;
    }
};
```