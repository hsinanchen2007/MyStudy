### 解题思路

1. 要求的是第k大的数，翻译一下也就是要求从最大往小的方向数第k个数字。因此我们可以用小堆来存储数据（即堆顶的数字最小）。
2. 当pq.size() > k 时，我们就需要将top() 弹出来，这样优先队列当中存储的就只有k个数字，且堆顶的是最小的那个，子节点都比堆顶大。
3. 循环结束后，返回堆顶元素，就是要求的第k大的数。

复杂度分析：
1. 堆的平均操作复杂度（包含 sift up / sift down）在 O(lgk)
2. 外面包了一个for循环是 O(n)
3. 因此复杂度是 O(nlgk)

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::function<bool(int,int)>> pq([](int a, int b)->bool{ return a > b; });
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
```