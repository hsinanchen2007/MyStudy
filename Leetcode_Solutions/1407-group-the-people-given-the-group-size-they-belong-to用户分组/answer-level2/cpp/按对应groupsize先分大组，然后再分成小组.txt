### 解题思路
因为最多500组，因此建立一个大小为505的vector<int>A[505]，略大一点以防止溢出。
然后根据对应groupsize相同的人先分到同一组来进行分组，按照比如groupsize是3
那么就把ta先分到A[3]中，然后遍历这个A按照A[i].size()/i 分成对应的小vector当中。
从而完成分组。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> result[505];
        for(int i=0; i<n; i++){
            result[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> final_result;
        for(int i=0; i<505; i++){
            int j = 0;
            while( j < result[i].size() ){
                vector<int>temp;
                for(int k=0; k<i; k++,j++){
                    temp.push_back(result[i][j]);
                }
                final_result.push_back(temp);
            }
        }
        return final_result;
    }
};


```