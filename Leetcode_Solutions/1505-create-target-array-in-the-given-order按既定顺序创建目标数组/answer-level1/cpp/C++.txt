### 解题思路
简单的c++

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        int n=nums.size();
        vector<int> target(n);
        int t=0,m=0;
        for(int i=0;i<n;i++)
        {
            m=index[i];
            t=nums[i];
            target.insert(target.begin()+m,t);//在第m个位置插入t
        }
        target.resize(n);//去除多余的元素
        return target;

    }
};
```