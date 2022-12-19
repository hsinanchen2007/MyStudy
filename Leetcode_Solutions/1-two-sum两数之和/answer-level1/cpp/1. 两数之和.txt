哈希表法
==============
哈希表二次遍历
----------------
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> res;
        //第一遍遍历建立哈希表，key为元素值，value为索引值
        for(int index=0;index<nums.size();++index){
            hashMap[nums[index]]=index;
        }
        //第二遍遍历
        for(int i=0;i<nums.size();++i){
            //如果没找到返回指向结尾得迭代器
            //如果找到值，不能是当前值，所有索引不能相同
            if(hashMap.find(target-nums[i]) != hashMap.end() && hashMap[target-nums[i]]!=i){
                 return res={i,hashMap[target-nums[i]]};
            }
        }
        return res;
    }
};


```
哈希表一次遍历
--------------

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> res;
        //一次遍历
        for(int i=0;i<nums.size();++i){
            //如果发现满足条件的key值return value值，没发现就加入map
            if(hashMap.find(target-nums[i]) != hashMap.end()){
                return res={hashMap[target-nums[i]],i};
            }else{
                hashMap[nums[i]]=i;
            }
        }
        return res;
    }
};
```