

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d=0;
        for(char n:seq){
            if(n=='('){
                d++;
                ans.push_back(d%2);
            }
            else{
                ans.push_back(d%2);
                d--;
            }
        }
        return ans;
    }
};
```