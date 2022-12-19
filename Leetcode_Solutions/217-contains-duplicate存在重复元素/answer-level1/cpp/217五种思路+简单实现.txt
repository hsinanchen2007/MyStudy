思路大体分三类，排序+检索、映射到集合中、取巧。
# 排序
## 用内置函数排序
排序+遍历
复杂度O(nlogn)+O(n)
```C++
sort(nums.begin(),nums.end());
for(int i = 0;i<nums.size()-1;++i)
    if(nums[i]==nums[i+1])
        return true;
return false;
```
## 手动实现
排序时
复杂度O(nlogn)
堆排、胜者树较好
# 映射
## unordered_set
检索+插入
复杂度O(n)+O(1)
```C++
unordered_set<int> u;
for(int i:nums){
    if(u.find(i)!=u.end())
        return true;
    u.insert(i);
}
return false;
```
## set
复杂度O(n^2)
```C++
return set<int>(nums.begin(),nums.end()).size()!=nums.size();
```
# 取巧
经观察C++组高速算法，发现有一个清奇的思路，即假设所给数组近似从大到小排列，然后在遍历数组的过程中，仅在有逆序数时，检索此前数组中是否有与此逆序数相等的数。但实际上，若样本从小到大排列，则此算法退化为暴力遍历，复杂度为O(n^2)。