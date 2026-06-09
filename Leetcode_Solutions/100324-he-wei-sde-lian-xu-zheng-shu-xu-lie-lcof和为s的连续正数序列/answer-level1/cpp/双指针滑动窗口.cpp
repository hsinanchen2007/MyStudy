### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i=1,j=1;
        int sum = 0;
        while(i <=target/2 )
        {
            if(sum<target){
                sum+=j;
                j++;
            }
            else if(sum>target){
                sum-=i;
                i++;
            }
            else {
                vector<int> tmp;
                for(int k = i; k<j; k++)
                {
                    tmp.push_back(k);
                }
                ans.push_back(tmp);
                sum-=i;
                i++;
            }

        }
        return ans;
    }
};
```