暴力法的话最后一个测试用例无法通过，那么可以对暴力法进行优化，提高查找时的效率。代码如下：
PS：都是些常用的函数，可以自己找一个数组带进去试一试，就很容易理解了！！
```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || t < 0 || k < 1) //特殊情况处理
            return false;
        set<long> s;//stl中的集合基于红黑树来组织，添删查的复杂度为 n*logn
        s.insert(nums[0]);
        
        for(int i=1;i < nums.size();i++){
            if(s.size() > k){
                s.erase(nums[i-k-1]);//确保s中的元素满足k的限制
            }
            if(s.find(nums[i]) != s.end())//如果找到，则t的限制也一定满足，直接返回
                return true;
            
            s.insert(nums[i]);//先插入
            auto it = s.find(nums[i]);//再查找
            if(it == s.begin()){ //和相邻元素做比较
                if(abs(*it - *(++it)) <= t){
                    return true;
                }
            }else if(it == --s.end()){
                if(*it - *(--it) <= t){
                    return true;
                }
            }else{
                auto it2 = it;
                if(abs(*it - *(++it)) <= t || *it2 - *(--it2) <= t)
                    return true;
            }
        }
        return false;
    }
};
```
