### 解题思路
这是一道知道贪心但是不知道怎么贪心的题…
首先，这道题满足贪心的性质是：**每一天选择参加距当前结束时间最快的会议可推出全局最优解。**
关键就是，**如何找到当天结束时间最快的会议。**

一开始本能的想法是定义一个数组 a[i] 表示以 i 为起始时间，结束时间最短的会议，然后按起始时间从小到大排序优化一下。可还是避免不了O(n^2)的时间复杂度。
后来看了别人的题解，感觉真是奇妙。(参考lucifer 1004的题解)

要找到当天结束时间最快的会议，我们可以运用一个小顶堆解决。这个堆是按结束时间从小到大排序的。或许更正式一点，**小顶堆里存的是当天可参加的所有会议的结束时间。** 很明显，我们只需要选择小顶堆的top会议即可。现在的任务是构建这个小顶堆。

首先，我们遍历起始时间 i，将当天开始的所有会议加进小顶堆中，并且将小顶堆里已经“过期” (结束时间 < 当天) 的会议剔除掉。然后，参加小顶堆的top会议即可。

现在还有一个问题，就是**通过 O(1) 获取某天开始的所有会议。** 我们可以很自然的想到这需要一个 时间 -> 会议 映射。你可以创建一个起始时间桶，也可以用一个map， 这个容易处理。因为我们遍历起始时间需要从 1 - 10^5，空间很密集，桶比map更合适一些。

### 代码
```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int MAX = 1e5+5;
        int ans = 0;
        vector<int> btn[MAX];    //起始时间桶
        for(int i = 0;i < events.size();i++)	//起始时间 -> 会议下标
        {
            btn[events[i][0]].push_back(i);
        }
        priority_queue<int,vector<int>,greater<int>> Q;
        for(int i = 1;i < MAX;i++)	//遍历起始时间
        {
            for(int j = 0;j < btn[i].size();j++)	//将该时间起始的所有会议按结束时间进堆
            {
                Q.push(events[btn[i][j]][1]);
            }
            while(!Q.empty() && Q.top() < i) Q.pop();	//剔除过期的会议
            if(!Q.empty()) Q.pop(), ans++;	//选距当前结束时间最短的会议
        }
        return ans;
    }
};

```

map做法：
```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int MAX = 1e5+5;
        unordered_map<int,vector<int>> mp;  //用map会超时...emm...
        for(int i = 0;i < events.size();i++) 
        mp[events[i][0]].push_back(i);
        
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> Q;
        for(int i = 1;i < MAX;i++)
        {
            for(int j = 0;!mp[i].empty() && j < mp[i].size();j++)    //i时间开始的会议取结束时间全部加进小顶堆
            Q.push(events[mp[i][j]][1]);

            while(!Q.empty() && Q.top() < i) Q.pop();
            if(!Q.empty()) Q.pop(), ans++;
        }
        return ans;
    }
};
```