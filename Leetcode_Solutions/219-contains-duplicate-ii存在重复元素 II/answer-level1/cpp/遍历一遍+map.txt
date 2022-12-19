![1585973650(1).jpg](https://pic.leetcode-cn.com/1ccd22ea2cdafa184c0ce45434be5c4e8a62a2b066e9df7967530a36eb9e0e36-1585973650\(1\).jpg)

一开始维护一个大小为k的滑窗进行比较，通过22/23，最后一个超时。于是转而使用一个map，通过key值直接查找，节省了部分时间，但是效率依旧不是特别高，代码附上，欢迎提出宝贵意见。

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> tmp;
        for(int i=0;i<nums.size();i++){
            if(tmp.find(nums[i])==tmp.end()) tmp.insert({nums[i],i});                
            else 
            {
                if(i-tmp[nums[i]]<=k&&i-tmp[nums[i]]>=-k) return true;
                else tmp[nums[i]]=i;
            }
        }
        return false;
    }
};
```
