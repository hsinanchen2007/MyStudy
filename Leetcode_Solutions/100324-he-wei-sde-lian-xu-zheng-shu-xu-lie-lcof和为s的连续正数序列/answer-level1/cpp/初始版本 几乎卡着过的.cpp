### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > ans;
        int lim=(target-1)/2;
        for(int i=0;i<=lim;i++){
            int sum=0,f=i+1;
            vector<int> v;
            while(true){
                sum+=f;
                v.push_back(f);
                ++f;
                if(sum==target) {
                    if(v.size()>=2) ans.push_back(v);
                    break;
                }
                if(sum>target)  break;
               
            }
        }
        return ans;

    }
};
```