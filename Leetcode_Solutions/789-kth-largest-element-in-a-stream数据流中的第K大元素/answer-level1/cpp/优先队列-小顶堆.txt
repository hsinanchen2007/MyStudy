### 解题思路
[每日打卡](https://github.com/hapiii/leetcode)

### 代码

```cpp
class KthLargest {
    //小顶堆
    priority_queue<int, vector<int>, greater<int> > smallHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num:nums) {
            add(num);
        }
        
    }
    
    int add(int val) {
        if (smallHeap.size() < k) {
            smallHeap.push(val);
        }else if(val > smallHeap.top()){
            smallHeap.pop();
            smallHeap.push(val);
        }
        return smallHeap.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```