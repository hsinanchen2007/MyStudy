### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> res;
        int i  = 1;
        while(target > 0)
        {
            target = target - (i++);
            if(target % i ==0 && target>0)
            {
                vector<int>temp;
                for(int j =0;j < i;j++)
                {
                    temp.push_back(target/i + j) ;
                }
                res.push_back(temp);               
            } 
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```