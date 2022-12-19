### 解题思路
#### 一、优先队列
相关题目：[合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

1、创建一个**优先队列（小顶堆）**，首先将所有的列表的 **第一个** 元素加入到优先队列中； 在加入元素创建队列时，得到 **所有列表的第一个元素的最大值**

2、设置当前最小长度 = INT_MAX

3、每次从优先队列中取出最小的元素，然后判断 最大值 - 最小值。如果长度比 当前最小长度 小，则更新 最小长度 和 最小区间的端点 (l, r)。

4、然后，加入 **当前元素所在列表中，在当前元素之后的元素**，并维护区间最大值。

5、简要证明：通过该解法，总是可以得到 **以某一元素为起点，包含所有列表元素的最小长度区间**，然后找到这些长度的最小值即可。

6、详见图解

<![image.png](https://pic.leetcode-cn.com/b7d09ed43ceacbef53a4b133c04c3e7d74dd82b3250f3d2bdb002410bfa47285-image.png),![image.png](https://pic.leetcode-cn.com/4ba29c893e514c238e471adae6bcc69ba92621224cea093d4b051b16726fb730-image.png),![image.png](https://pic.leetcode-cn.com/9791be553ab2597ab72ba466746e01e7f899de15fa203cd9f6a15a415086d50a-image.png),![image.png](https://pic.leetcode-cn.com/ed9b23bac497e9c0708d8183de5156831d60fe810690354772a527a3d886c4d4-image.png),![image.png](https://pic.leetcode-cn.com/4ec634ec121a260e860625215929820af9e91b12d20938dae3caab65611223b7-image.png),![image.png](https://pic.leetcode-cn.com/931bcc654111817c6bddfc1716cb0b8e2f257437a403ab0548c38bd176079a33-image.png),![image.png](https://pic.leetcode-cn.com/63f2d0755a24e15fa8532d1caccd99547e3222a3b1bf4d2bbe8b16c622d2c339-image.png),![image.png](https://pic.leetcode-cn.com/50cd0a1ed11c0fe2e0c479d356548d400a030699da78b762e298c707523a9dee-image.png),![image.png](https://pic.leetcode-cn.com/b3fa9093f32edca9d76e25a48b0bb2cd1cb770127a41d74a8e8897e14a622e50-image.png),![image.png](https://pic.leetcode-cn.com/8281e1c39e60f25dd232c99265e719b5c364e583cf26e80d6701d83102ebc3a5-image.png),![image.png](https://pic.leetcode-cn.com/0fae400c17e1dddb94e99e3ebe1e34ace3fd7a5dadcd166f1a29b8a9cfa8917f-image.png),![image.png](https://pic.leetcode-cn.com/146197628fd79aa55d974929510f3ef99178c1959448d5731e50e41915df428d-image.png),![image.png](https://pic.leetcode-cn.com/8b56a02c075d9c678c2a14337d5cfad6116974d6d58136d5d9c7b94f2330bcad-image.png),![image.png](https://pic.leetcode-cn.com/6381adf91dabc94aac1a611b78ddba12748f07fd108153b8a14b4ee79165697f-image.png),![image.png](https://pic.leetcode-cn.com/2b8ef0333e7d4b1b49fa751c270422e90043cba92254780e0af8cbde48fff221-image.png),![image.png](https://pic.leetcode-cn.com/8ee0a634c8c01818d0581f5679f628bddeba3246622de9150724f544f8e71ee4-image.png),![image.png](https://pic.leetcode-cn.com/f36ec63667970fffea5821f3a48e0c32e38a3fc7fa5f10d009e3f703092b7365-image.png),![image.png](https://pic.leetcode-cn.com/bec4fb70744fe48a6646312592349e3f51040cff36986b0619257b4535df2ca6-image.png),![image.png](https://pic.leetcode-cn.com/0e5d6de8a7da017e7bc6dd1a15fa1a5633a49180d695cf403fb7822d19c3eb3b-image.png),![image.png](https://pic.leetcode-cn.com/0b152c946b87796d08054f73e8c992cf6f13486b97de049e84102e743e39e194-image.png)>


#### 代码

```cpp
class Solution {
    struct Node
    {
        int val, x, y;
        Node(int v, int x, int y) : val(v), x(x), y(y) {}
        bool operator>(const Node& r) const { return val > r.val; }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        if(k == 1) return {nums[0][0], nums[0][0]};

        priority_queue<Node, vector<Node>, greater<Node>> q;
        int maxv = INT_MIN, minl = INT_MAX, l, r;

        for(int i = 0; i < k; ++i) 
            q.push(Node(nums[i][0], i, 0)), maxv = max(maxv, nums[i][0]);

        while(q.size() == k)
        {
            Node cur = q.top(); q.pop();

            if(maxv - cur.val < minl)
                minl = maxv - cur.val, l = cur.val, r = maxv;
            
            if(cur.y + 1 < nums[cur.x].size())
            {
                maxv = max(maxv, nums[cur.x][cur.y + 1]);
                q.push(Node(nums[cur.x][cur.y + 1], cur.x, cur.y + 1));
            }
        }

        return {l, r};
    }
};
```

#### 二、双指针
1、将所有列表元素加入一个 **元素值 - 包含该元素的列表下标集合** 的 map

2、**在树中应用双指针**。指针为 **map的迭代器**。对每个 元素值 right，找到 **使[right, left]能够包含所有列表的 最大元素值 left**。

3、长度最小的 [left, right] 即为所求。

4、这个代码很神奇，运行时间 32ms，100%

#### 代码
```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        if(k == 1) return {nums[0][0], nums[0][0]};

        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i)
        for(int v : nums[i])
            m[v].push_back(i);

        int cnts[k] = {0}, lc = 0, minl = INT_MAX, l = 0;
        
        auto s = m.begin();
        for(auto t = m.begin(); t != m.end(); ++t)
        {
            for(int i : t->second) if(++cnts[i] == 1) ++lc;
            if(lc < k) continue;
            int lastv;
            while(lc >= k)
            {
                lastv = s->first;
                for(int i : s->second) if(--cnts[i] == 0) --lc;
                ++s;
            }
            if(t->first - lastv < minl)
                minl = t->first - lastv, l = lastv;
        }
        return {l, l + minl};
    }
};
```
