
### 代码

```cpp
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> counter;
        for(char c : T){
            if(counter.find(c) != counter.end()){
                counter[c] ++;
            }else
                counter[c] = 1;
        }
        string res = "";
        auto it = res.begin();
        for(char c : S){
            if(counter[c])
                it = res.insert(it,counter[c],c);
                it += counter[c];
                counter.erase(c);
        }
        for(auto [c,n] : counter){
            it = res.insert(it,n,c);
            it += n;
        }
        return res;
    }
};
```