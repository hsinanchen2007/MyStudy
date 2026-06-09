### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        for(long i=1;i<=target/2;i++){
            long delta=4*i*i-4*i+1+8*target;
            if(delta>0){
                long sq=(long)sqrt((float)delta);
                if(sq*sq==delta && (sq+1)%2==0){
                    vector<int> tmp;
                    for(int j=i;j<(sq+1)/2;j++)
                        tmp.push_back(j);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
```