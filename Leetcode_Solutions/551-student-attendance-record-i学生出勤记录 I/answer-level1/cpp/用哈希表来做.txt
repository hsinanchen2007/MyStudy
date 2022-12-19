用哈希n表来判断“A”和"LLL"的数量

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<string,int> hash;
        if(s == "A"){
            return true;
        }
        for(int i =0;i<s.size();i++){
            string str = s.substr(i,3);
            string str1 = s.substr(i,1);
            hash[str1]++;
            hash[str]++;
        }
        if(hash["A"] <=1 && hash["LLL"]==0){
            return true;
        }
        return false;
    }
};
```