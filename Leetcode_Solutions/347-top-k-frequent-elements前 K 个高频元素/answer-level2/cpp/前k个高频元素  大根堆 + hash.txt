### 解题思路
给定一个非空的整数数组，返回其中出现频率前 k 高的元素

1. 计算每个元素出现的次数 ：
考虑用hash表 `unordered_map<int,int> hash;` key = nums[i] , value = nums[i] 出现的次数

2. 返回其中出现频率前 k 高的元素 ，时间复杂度必须优于 O(n log n)
考虑堆结构 ： 使用大根堆，每次插入 `pair<value,key>` ，注意不是 <key,value> ,因为大根堆优先按第一个值从大到小排序，这里我们需要按 nums[i] 出现的次数排序。
最后返回堆的前K个元素， `res.push_back(heap.top().second);` 
注意这里是  heap.top().second = key = nums[i]


### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> hash;
        priority_queue<pair<int,int>> heap;
        for(int i = 0;i < nums.size();i ++)
            hash[nums[i]] ++;
        for(auto it : hash)  //也可以只开一个大小为k的堆
            heap.push(make_pair(it.second,it.first));
        while(!heap.empty() && k > 0){
            res.push_back(heap.top().second);
            heap.pop();
            k --;
        }
        return res;
    }
};
```