### 解题思路
![image.png](https://pic.leetcode-cn.com/704ab0e96cb0cebc4f8882cb3224054abf07c2f617bf0946f31578a0fa4445f8-image.png)


### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums) mp[num]+=1;
        int res;
        for(auto k:mp)
            if(k.second==1){res=k.first;break;}
        return res;
    }
};
```