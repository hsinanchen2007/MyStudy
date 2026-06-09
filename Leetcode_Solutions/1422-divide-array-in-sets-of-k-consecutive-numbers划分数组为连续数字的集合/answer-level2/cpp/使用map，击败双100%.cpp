### 解题思路
使用map对数组元素进行计数，同时因为map的特性，会根据数组元素大小进行排序，对于map的key值，判断其连续的k个数是否仍满足需要即可，如果满足需求，则对应元素出现的次数-1。

### 代码

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second==0)
                continue;
            int s=it->first;
            while(mp[s]>0){
                mp[s]--;
                for(int i=1;i<k;i++)
                    if(mp[s+i]==0)
                        return false;
                    else
                        mp[s+i]--;
            }
        }
        return true;
    }
};
```