### 解题思路
使用哈希表，将数组arr中的元素的顺序编号和数组元素进行对应即可

### 代码

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<int> res;
        unordered_map<int,int> m;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int t=1;
        m[temp[0]]=t;
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]==temp[i-1]) m[temp[i]]=t;
            else { ++t;m[temp[i]]=t;}
        }
        for(int a:arr)
        {
            res.push_back(m[a]);
        }
        return res;
    }
};
```