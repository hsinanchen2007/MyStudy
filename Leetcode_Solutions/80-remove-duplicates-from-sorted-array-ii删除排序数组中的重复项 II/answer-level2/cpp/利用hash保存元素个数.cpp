### 解题思路
建立unordered_map key为元素值 value为元素个数
通过快慢指针判断是否更新指针

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int>mp;
        int j=0;
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=1;
                nums[++j]=nums[i];
            }else{
                if(mp[nums[i]]<2){
                    mp[nums[i]]++;
                    nums[++j]=nums[i]; 
                }
            }
        }
        return j+1;
    }
};
```