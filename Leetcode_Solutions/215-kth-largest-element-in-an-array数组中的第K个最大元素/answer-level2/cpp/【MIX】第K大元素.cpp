### 解题思路
1. 暴力排序
2. 快速排序
3. 小顶堆优先队列

### 代码
**快速排序**
```c++ []
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 快速排序方法求解
        int N = nums.size();
        return quickSort(nums, 0, N-1, N-k);
    }

    int quickSort(vector<int> &nums, int l, int r, int k){
        int pivot = partition(nums, l, r);
        if(pivot == k)
            return nums[pivot];
        else if(pivot < k)
            return quickSort(nums, pivot+1, r, k);
        else
            return quickSort(nums, l, pivot-1, k);
    }

    int partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[rand()%(r-l+1)+l]);
        int pivot = nums[l];
        int i = l+1;
        int j = r;
        while(i<=j){
            while(i<=r && nums[i]<=pivot) ++i;
            while(j>l && nums[j]>=pivot) --j;
            if(i<=j){
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[j], nums[l]);
        return j;
    }
};
```
```java []
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int N = nums.length;
        // 优先队列求解
        // 使用小顶堆
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->(a-b));
        for(int d: nums){
            if(pq.size() == k){
                int e = pq.poll();
                if(d > e){
                    pq.offer(d);
                }else{
                    pq.offer(e);
                }
            }else{
                pq.offer(d);
            }
        }
        return pq.poll();
    }
}
```
```python []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]
```
```python []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        q = []
        for d in nums:
            heapq.heappush(q, d)
            if(len(q) > k):
                heapq.heappop(q)

        return heapq.heappop(q)
```

**暴力排序**
```c++ []
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](int v1, int v2){
            return v1>v2;
        });
        return nums[k-1];
    }
};
```