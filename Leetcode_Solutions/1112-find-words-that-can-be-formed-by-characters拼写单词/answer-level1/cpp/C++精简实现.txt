### C++精简实现

C++精简实现

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m;
        for(auto c : chars) {
            m[c]++;
        }
        int res = 0;
        for(auto elem : words) {
            int sz =  elem.size();
            int i = 0;
            unordered_map<char,int> um = m;
            while(i<sz) {
                if(um.count(elem[i])>0 && um[elem[i]]>0) {
                    um[elem[i]]--;
                } else {
                    break;
                }
                i++;
            }
            if(i==sz) {
                res += elem.size();
            }
        }
        return res;
    }
};
```