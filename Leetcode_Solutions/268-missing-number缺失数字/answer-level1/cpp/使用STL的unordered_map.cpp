### 解题思路
使用unordered_map存储数字出现的次数，在遍历nums数组的过程中记录下最大值p，对于0,1,2,...,p，若数字i出现次数为0则返回i,若0-p都出现过，则返回p+1

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int p=-1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            p=max(p,nums[i]);
        } 
        for(int i=0;i<=p;i++)
            if(mp[i]==0)
                return i;
        return p+1;
    }
};
```