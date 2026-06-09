### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>v;
        //int i=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(i!=0&&(i+1)%2==0)
            //int freq=2*i;
            //int val=2*i+1;
            v.insert(v.end(),nums[i-1],nums[i]);
        }
        return v;
    }
};
```