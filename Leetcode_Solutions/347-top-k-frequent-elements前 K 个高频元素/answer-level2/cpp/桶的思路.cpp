##### 题感：写出了一个 O(n) 级别的复杂度 ，大部分题解都说是要用到堆，我只知道我是模拟，看了评论才发现是桶排序，想了想，结果思路确实是，哈哈哈。
**思路：**
* 统计每个数的频次，将结果存入哈希表。
* 新建一个桶，将哈希表中每个数插入索引为它的频次的这个桶里。
* 由于桶的索引是数的频次，越往后面的索引也就意味着频次越高，因此倒着遍历桶，取出最先遍历的k个数就是我们想要的答案。


```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > p ; 
        for(int i = 0 ; i < nums.size() ; i ++){
            p[nums[i]]++ ; 
        }
        vector<vector<int> > ant(nums.size() + 1) ;
        int max_size = INT_MIN ; 
        for(auto iter = p.begin() ; iter != p.end() ; iter++){
            ant[iter->second].push_back(iter->first) ;
            max_size = max(max_size , iter->second) ; 
        }
        int sum = 0 ;
        vector<int> ans ; 
        for(int i = max_size ; i>=0 ;i--){
            if(ant[i].size() != 0){
                for(int j = 0 ; j < ant[i].size() ; j++){
                    ans.push_back(ant[i][j]) ; 
                    ++sum ; 
                    if(sum >= k)
                        break; 
                }
            }
            if(sum >= k)
                break ; 
        }
        
        return ans; 
    }
};