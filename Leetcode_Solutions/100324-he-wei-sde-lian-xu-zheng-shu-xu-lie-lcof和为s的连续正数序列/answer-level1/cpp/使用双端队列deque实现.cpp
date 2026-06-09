### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        //if(target )
        deque<int> que;
        vector<vector<int>> ans;
        int sum =0;
        for(int i = 1 ; i <= target ; i++)
        {
            que.push_back(i);
            sum += i;
            if(sum == target)
                ans.push_back(vector<int> ( que.begin() ,que.end()));
            else if(sum > target)
            {
                while(sum >= target)
                {
                    sum -= que.front();
                    que.pop_front();
                    if(sum == target)
                        ans.push_back(vector<int> ( que.begin() ,que.end()));
                }
            }
        }
        ans.pop_back();
        return ans;




    }
};
```