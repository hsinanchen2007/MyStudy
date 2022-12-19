### 解题思路
查询当前字母最后位，大于则将边界扩展，当边界与i相等时及该字段，注意第一段是i-0所以最后加1

### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int xu1=0;
        int xu0=0;
        vector<int> res;
        for(int i=0;i<S.size();i++){
            int tmp=S.find_last_of(S[i]);
            if(tmp>xu1) xu1=tmp;
            if(i==xu1) {
                res.push_back(xu1-xu0);
                xu0=xu1;
            }
        }
        res[0]++;
        return res;
    }
};
```