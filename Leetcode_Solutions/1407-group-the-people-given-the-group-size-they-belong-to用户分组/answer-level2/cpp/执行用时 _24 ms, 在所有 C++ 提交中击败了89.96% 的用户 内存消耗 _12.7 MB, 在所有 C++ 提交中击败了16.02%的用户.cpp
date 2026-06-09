### 解题思路
首先排序，然后得到groupsize的array，类似[1,3,3]这样，然后再计数并插入

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> arr;
        for(int i=0;i<groupSizes.size();++i)
        {
            arr.push_back(groupSizes[i]);
        }
        sort(arr.begin(), arr.end());
        vector<int> temp;
        int index=0;
        int c=1;
        temp.push_back(arr[0]);
        vector<vector<int>> res;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]!=temp[index])
            {
                temp.push_back(arr[i]);
                index++;
                c=1;
            }
            else{
                if(c<temp[index])
                {
                    c++;
                }
                else{
                    c=1;
                    temp.push_back(arr[i]);
                    index++;
                }
            }
        }
        for(int i=0;i<temp.size();++i)
        {
            int size = temp[i];
            int count=0;
            vector<int> group;
            for(int j=0;j<groupSizes.size();++j)
            {
                if(groupSizes[j]==size)
                {
                    groupSizes[j]=0;
                    group.push_back(j);
                    count++;
                    if(count==size)
                        break;
                }
            }
            res.push_back(group);
        }
        return res;
    }
};
```