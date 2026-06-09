### 解题思路
默认的优先队列是权值高的在队首，我们题目要求求第k大的数，说明比第k+1大之后的数都用不到了，所以我们可以维护一个小顶堆，这样堆顶元素就是我们要求的数字。
### 代码

```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int i = 0 ; i < nums.size() ; ++i)
            add(nums[i]);
    }
    
    int add(int val) {
        q.push(val);
        cnt++;
        if(cnt > kk)
        {
            q.pop();
            cnt--;
        }
        return q.top();
    }
private:
    priority_queue<int, vector<int>, greater<int> > q;
    int kk, cnt = 0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```