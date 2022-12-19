### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int k=0;
        for(auto c:seq){
            if(c=='('){
                k++;
                if(k%2==0) res.push_back(0);
                else res.push_back(1);
            }
            else {
                if(k%2>0) res.push_back(1);
                else res.push_back(0);
                k--;
            }
        }
        return res;
    }
};
```