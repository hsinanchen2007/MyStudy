### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>res;
        int depth = 1;
        for(int i = 0; i < seq.length(); i++){
            if(seq[i] == '('){
                depth++;
                res.push_back(depth % 2);
            }else{
                res.push_back(depth % 2);
                depth--;
            }
        }
        return res;
    }
};
```