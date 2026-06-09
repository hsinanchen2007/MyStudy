### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> m1(128,0);
        vector<int> m2(128,0);
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            m2[s2[i]]++;
        }
        for(int i=0;i<128;i++){
            if(m1[i]!=m2[i]){
                return false;
            }
        }
        return true;
    }
};
```