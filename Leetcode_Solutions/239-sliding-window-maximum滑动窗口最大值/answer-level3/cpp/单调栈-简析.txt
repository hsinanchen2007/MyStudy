### 解题思路

执行用时 :52 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :13.2 MB, 在所有 cpp 提交中击败了25.75%的用户

问题：求解滑动窗口最大值
容器：deque，双向队列，可以使用双向链表
分析：
区间最大值，从前向后推移过程中，若前方出现值小于当前值的数据，可以直接覆盖掉。
每次做一次弹出判定，弹出deque头部，距离大于k的值。

### 代码

```cpp
class Solution {
public:
struct data{
    int d;
    int p;
};
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<data>de;
    int len=nums.size();
    vector<int>res;
    for(int i=0;i<len;i++){
        while(!de.empty() && de.back().d < nums[i]){
            de.pop_back();
        }
        de.push_back(data{nums[i], i});
        if (i - de.front().p >= k){
            de.pop_front();
        }
        if(i >= k-1) {
            res.push_back(de.front().d);
        }
    }
    return res;
    }
};
```