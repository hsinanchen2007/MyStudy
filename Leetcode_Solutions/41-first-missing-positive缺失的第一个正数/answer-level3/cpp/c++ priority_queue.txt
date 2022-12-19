![image.png](https://pic.leetcode-cn.com/70693aadc9e83d0ff191e7c5160505931a78ca2ee4224c873d41fc7de8fe3790-image.png)
不必分配哈希表那么大空间
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index = 1;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto n:nums) {
            if (n >= index) heap.push(n);
            while (!heap.empty() &&  heap.top() <= index) {
                if(heap.top() == index)index++;
                heap.pop();
            }
        }
        return index;
    }
};
```
