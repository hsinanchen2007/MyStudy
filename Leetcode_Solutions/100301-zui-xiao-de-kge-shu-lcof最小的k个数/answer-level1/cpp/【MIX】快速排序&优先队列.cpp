### 解题思路
快速排序: 时间复杂度$O(N)$
优先队列: 时间复杂度$O(NlgK)$
### 代码

```java []
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        // quick sort 求解
        if(arr.length==0 || k==0)
            return new int[0];

        return quickSort(arr, 0, arr.length-1, k-1);
    }

    private int[] quickSort(int []A, int lo, int hi, int k){
        int j = partition(A, lo, hi);
        if(j == k)
            return Arrays.copyOf(A, j+1);

        return j>k ? quickSort(A, lo, j-1, k) : quickSort(A, j+1, hi, k);
    }

    // partition: 小于A[j]的在左边, 大于A[j]的在右边
    private int partition(int []A, int lo, int hi){
        int pivot = A[lo];
        int i = lo;
        int j = hi+1;
        while(i<=j){
            while(++i<=hi && A[i]<pivot);
            while(--j>=lo && A[j]>pivot);

            if(i <= j){
                // swap A[i] A[j]
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }   
        }
        // place pivot
        A[lo] = A[j];
        A[j] = pivot;

        return j;
    }
}
```
```python []
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 优先队列
        from queue import PriorityQueue as PQ
        q = PQ()
        for x in arr:
            q.put((-x, x))
            if q.qsize() > k:
                q.get()

        res = []
        while q.empty() is False:
            res.append(q.get()[1])

        return res
```
```c++ []
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 优先队列, 使用大顶堆
        priority_queue<int, vector<int>, less<int>> q;
        for(auto & x: arr){
            q.push(x);
            if(q.size() > k)
                q.pop();
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};
```
**quick sort**
```java []
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        // quick sort, 时间复杂度O(N)
        int N = arr.length;
        if(N==0 || k==0)
            return new int[0];

        return quickSort(arr, 0, N-1, k-1);
    }

    private int[] quickSort(int []A, int lo, int hi, int k){
        int j = partition(A, lo, hi);
        // 当pivot就是k, 拷贝排序后的k+1个元素返回
        if(j == k)
            return Arrays.copyOf(A, j+1);
        // 否则在j前半部分或者j后半部分递归
        return j>k ? quickSort(A, lo, j-1, k) : quickSort(A, j+1, hi, k);
    }

    // partition: 小于A[j]的在左边, 大于A[j]的在右边
    private int partition(int []A, int left, int right){
        int mid = left + (right-left)/2;
        // 将轴心元素交换至首位
        int temp = A[left];
        A[left] = A[mid];
        A[mid] = temp;

        temp = A[left];

        while(left < right){
            // 先从后向前扫描
            while(left < right && A[right] >= temp)
                right--;
            A[left] = A[right];

            // 在从前向后扫描
            while(left < right && A[left] <= temp)
                left++;
            A[right] = A[left];   
        }

        A[left] = temp;
        return left;
    }
}
```
