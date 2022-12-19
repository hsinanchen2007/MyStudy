看到这题，我的第一想法就是sort，但是时间复杂度肯定不是O(n),所以就放弃了，实话说，最近刷题刷的我有点自闭，越刷越没思路，希望自己可以坚持下去吧。
- 方法一
利用set，官方解题c++版，将数组转换为集合，遍历数组，巧就巧在，但凡存在nums[i]-1，当前元素不做处理，直接continue，而只有不存在nums[i]-1的时候再去找最长序列，举个例子
```
[4,5,3,6]
当遇到4，5，6的时候不做处理，直到3的时候查找最长序列，因为处理3的时候会包含处理4，5，6的情况，节约时间。

```
也不知写清楚了没有。。。。

```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		int res = 0;
		for (int num:nums) {
			if (s.count(num - 1))continue;
			else
			{
				int len = 1;
				while (s.count(++num))
					len++;
				res = max(res, len);
			}
		}
		return res;
	}
};
```
- 方法二
题解区一大佬的想法，个人觉得这个是真的牛逼，真正的O(n),所以记录下来。

[https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/dong-tai-gui-hua-python-ti-jie-by-jalan/](here)
```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_map<int,int> map;
		int res = 0;
	    for(auto num:nums){
            if(map.find(num)==map.end()){
                int left=map.find(num-1)==map.end()?0:map[num-1];
                int right=map.find(num+1)==map.end()?0:map[num+1];
                map[num]=map[num-left]=map[num+right]=left+right+1;
                res=max(res,left+right+1);
            }
        }
		return res;
	}
};
```

