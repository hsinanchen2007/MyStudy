### 解题思路
此处撰写解题思路
虽然是第一道题，但是我看见了很懵，于是这是借鉴的其他大佬的。链接：[https://www.cnblogs.com/Kanna/p/12395193.html。](https://www.cnblogs.com/Kanna/p/12395193.html。)
首先我想跟着这个题的格式来写，用c++的vector，去找了vector，map的用法，再甩一个链接[https://blog.csdn.net/qq_21567767/article/details/81709452](https://blog.csdn.net/qq_21567767/article/details/81709452)，其中需要注意的是map（空间优）与unordered_map（时间优）的区别，就是时间与空间的相互取代代价。
我下面写的借鉴的两次hash，因为题目要找的是序号的集合，所以将数组nums的值作为key，序号作为value，用.find查找（查找有无key），而且大佬的写法很简便，古德古德古德啊。
为什么写的这么啰嗦呢，因为自己c++学的啥也不会，就查的多了一点儿，毕竟自己是个小菜鸡，希望以后能坚持刷题，坚持背单词。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&m[target-nums[i]]!=i)
                return {i,m[target-nums[i]]};
        }
        return {};
    }
};
```