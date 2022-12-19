### 解题思路
1. 插入排序 &nbsp;$O(N^2)$     &emsp;稳定        &emsp; *当元素基本有序时使用插入排序速度很快
2. 冒泡排序 &nbsp;$O(N^2)$     &emsp;稳定
3. 选择排序 &nbsp;$O(N^2)$     &emsp;*不稳定*
4. 归并排序 &nbsp;$O(NlgN)$    &emsp;稳定        &emsp; *有自顶向下和自底向上两种方式
5. 快速排序 &nbsp;$O(NlgN)$    &emsp;*不稳定*    &emsp; *三路快排优化和随机pivot优化
6. 希尔排序 &nbsp;$O(N^{1.5})$ &emsp;*不稳定*
7. 堆排序   &emsp;$O(NlgN)$    &emsp;*不稳定*
8. 桶排序   &emsp;$O(kN)$      &emsp;稳定
9. 基数排序 &nbsp;$O(Nlg_rM)$   &emsp;稳定

### 代码

**3.归并排序**
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 归并排序【自顶向下】
        int N = nums.size();
        // 先分配空间, 如果在merge中频繁分配空间会影响效率
        vector<int> p(N);
        p.clear();
        mergeSort(nums, 0, N-1, p);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int l, int r, vector<int>&p){
        if(l < r){
            int mid = l+(r-l)/2;
            mergeSort(nums, l, mid, p);
            mergeSort(nums, mid+1, r, p);
            // 加入优化
            if(nums[mid]>nums[mid+1])
                merge(nums, l, mid, r, p);
        }
    }

    void merge(vector<int> &nums, int l, int mid, int r, vector<int>&p){
        int i = l;
        int j = mid+1;
        int index=l;
        while(i<=mid && j<=r){
            if(nums[i] < nums[j]){
                p[index++] = nums[i++];
            }
            else{
                p[index++] = nums[j++];
            }
        }
        while(i<=mid){
            p[index++] = nums[i++]; 
        }
        while(j<=r){
            p[index++] = nums[j++];
        }

        for(int i=l; i<=r; ++i){
            nums[i] = p[i];
        }
    }
};
```
```java []
class Solution {
    public int[] sortArray(int[] nums) {
        // 归并排序
        int N = nums.length;
        // 开辟额外空间
        int []P = new int[N];
        for(int i=0; i<N; ++i)
            P[i] = nums[i];
        mergeSort(nums, 0, N-1, P);
        return nums;
    }

    private void mergeSort(int []nums, int l, int r, int []P){
        if(l < r){
            int mid = l+(r-l)/2;
            mergeSort(nums, l, mid, P);
            mergeSort(nums, mid+1, r, P);
            merge(nums, l, mid, r, P);
        }
    }

    private void merge(int []nums, int l, int mid, int r, int []P){
        int i = l;
        int j = mid+1;
        int k = l;
        while(i<=mid && j<=r){
            if(nums[i] < nums[j]){
                P[k++] = nums[i++];
            }
            else{
                P[k++] = nums[j++];
            }
        }

        while(i<=mid){
            P[k++]=nums[i++];
        }

        while(j<=r){
            P[k++]=nums[j++];
        }

        // copy
        for(int m=l; m<=r; ++m)
            nums[m]=P[m];
    }
}
```
```python []
```

**4.快速排序**
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 三路快排
        // 针对元素中有大量等于pivot的值进行优化, 边界在移动状态
        int N = nums.size();
        quickSort(nums, 0, N-1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int l, int r){
        if(l < r){
            swap(nums[l], nums[rand()%(r-l+1)+l]);
            int pivot = nums[l];

            // nums[l+1..lt] < pivot
            int lt = l;
            // nums[gt..r] > pivot
            int gt = r+1;
            // nums[lt+1..i] == pivot
            int i = l+1;

            while(i < gt){
                if(nums[i] < pivot){
                    swap(nums[i++], nums[++lt]);
                }
                else if(nums[i] > pivot){
                    swap(nums[i], nums[--gt]);
                }
                else{
                    ++i;
                }
            }
            swap(nums[l], nums[lt]);

            // 对小于pivot部分排序
            quickSort(nums, l, lt-1);
            // 对大于pivot部分排序
            quickSort(nums, gt, r);
        }
    }
};
```
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 快速排序(双指针优化+随机pivot优化)
        int N = nums.size();
        quickSort(nums, 0, N-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r){
        if(l < r){
            int pivot = partition(nums, l, r);
            quickSort(nums, l, pivot-1);
            quickSort(nums, pivot+1, r);
        }
    }

    int partition(vector<int>&nums, int l, int r){
        // 减少极端序列(近乎有序, 时间复杂度为O(N^2))发生的概率(取中点, 随机化)
        // int mid = l+(r-l)/2;
        // swap(nums[l], nums[mid]);
        swap(nums[l], nums[rand()%(r-l+1)+l]);
        int pivot = nums[l];
        // 如果数据集中存在大量重复元素, 进行双指针扫描优化, 将重复元素均匀地分散到两侧
        int i=l+1, j=r;
        while(i <= j){
            while(i<=r && nums[i] < pivot) ++i;
            while(j>=l+1 && nums[j] > pivot) --j;
            if(i <= j){
                swap(nums[i++], nums[j--]);
            }
        }

        swap(nums[l], nums[j]);
        return j;
    }
};
```
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 快速排序
        int N = nums.size();
        quickSort(nums, 0, N-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r){
        if(l < r){
            int pivot = partition(nums, l, r);
            quickSort(nums, l, pivot-1);
            quickSort(nums, pivot+1, r);
        }
    }

    int partition(vector<int>&nums, int l, int r){
        // 减少极端序列发生的概率
        int mid = l+(r-l)/2;
        swap(nums[l], nums[mid]);
        int pivot = nums[l];
        int j = l;
        for(int i=l+1; i<=r; ++i){
            if(nums[i] < pivot){
                swap(nums[++j], nums[i]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
```
```java []
class Solution {
    public int[] sortArray(int[] nums) {
        // 快速排序
        int N = nums.length;
        quickSort(nums, 0, N-1);
        return nums;
    }

    private void quickSort(int []nums, int l, int r){
        if(l < r){
            int pivot = partition(nums, l, r);
            quickSort(nums, l, pivot-1);
            quickSort(nums, pivot+1, r);
        }
    }

    private int partition(int []nums, int l, int r){
        int pIndex = (int)(Math.random()*(r-l)+l);
        swap(nums, l, pIndex);
        int pivot = nums[l];
        int i = l+1;
        int j = r;
        while(i<=j){
            while(i<=r && nums[i] <= pivot) i++;
            while(j>=l+1 && nums[j] >= pivot) --j;
            if(i<=j){
                swap(nums, i, j);
            }
        } 
        swap(nums, l, j);
        return j;
    }

    private void swap(int []nums, int i, int j){
        int temp= nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
```python []
from random import randint
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 快速排序
        N = len(nums)
        self.quickSort(nums, 0, N-1)
        return nums

    def quickSort(self, nums, l, r):
        if l<r:
            pivot = self.partition(nums, l, r)
            self.quickSort(nums, l, pivot-1)
            self.quickSort(nums, pivot+1, r)

    def partition(self, nums, l, r):
        # 需要固定随机数引擎
        index = randint(l, r)
        nums[l], nums[index] = nums[index], nums[l]
        pivot = nums[l]

        i = l+1
        j = r
        while i<=j:
            while i<=r and nums[i]<=pivot: i+=1
            while l<j and nums[j]>=pivot: j-=1
            if i<=j:
                nums[i], nums[j] = nums[j], nums[i]

        nums[j], nums[l] = nums[l], nums[j]
        return j
```
**7.堆排序**
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 堆排序(未优化版本)
        int N = nums.size();
        vector<int> res;
        MaxHeap<int> heap(N+1);
        for(int num: nums)
            heap.insert(num);
        while(!heap.empty()){
            res.insert(res.begin(), heap.extractMax());
        }

        return res;
    }

private:
    // 设计大顶堆
    template<typename T>
    class MaxHeap{
    private:
        T *E;   // 内置数组指针
        int cnt; // 当前存储的元素数量
        int capacity; // 数组容量

        // 堆调整算法
        // 上调, 当插入的子元素大于父元素
        void siftUp(int k){
            while(k > 1 && E[k/2] < E[k]){
                swap(E[k/2], E[k]);
                k /=2;
            }
        }

        // 下调, 当父元素小于某个子元素
        void siftDown(int k){
            while(2*k <= cnt){
                // 交换E[j]和E[k]
                int j = 2*k;
                // 在左右子树中选择较大元素进行交换
                if(j+1<=cnt && E[j+1]>E[j])
                    j+=1;

                if(E[k] > E[j])
                    break;
                swap(E[k], E[j]);
                k = j;
            }
        }

    public:
        MaxHeap(int capacity){
            E = new T[capacity+1];
            this->capacity = capacity;
            this->cnt=0;
        }

        ~MaxHeap(){
            delete []E;
        }

        int size(){
            return cnt;
        }

        bool empty(){
            return this->cnt == 0;
        }

        // 从数组的1号位置开始存储
        void insert(T e){
            assert(cnt+1<=capacity);
            E[++cnt] = e;
            siftUp(cnt);
        }

        // 删除并返回堆中最大元素
        T extractMax(){
            assert(cnt > 0);
            T e = E[1];
            swap(E[1], E[cnt--]);
            siftDown(1);
            return e;
        }

    };
};
```
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 堆排序(heapify优化)
        int N = nums.size();
        vector<int> res;
        MaxHeap<int> heap(nums, N);
        while(!heap.empty()){
            res.insert(res.begin(), heap.extractMax());
        }

        return res;
    }

private:
    // 设计大顶堆
    template<typename T>
    class MaxHeap{
    private:
        T *E;   // 内置数组指针
        int cnt; // 当前存储的元素数量
        int capacity; // 数组容量

        // 堆调整算法
        // 上调, 当插入的子元素大于父元素
        void siftUp(int k){
            while(k > 1 && E[k/2] < E[k]){
                swap(E[k/2], E[k]);
                k /=2;
            }
        }

        // 下调, 当父元素小于某个子元素
        void siftDown(int k){
            while(2*k <= cnt){
                // 交换E[j]和E[k]
                int j = 2*k;
                // 在左右子树中选择较大元素进行交换
                if(j+1<=cnt && E[j+1]>E[j])
                    j+=1;

                if(E[k] > E[j])
                    break;
                swap(E[k], E[j]);
                k = j;
            }
        }

    public:
        MaxHeap(int capacity){
            E = new T[capacity+1];
            this->capacity = capacity;
            this->cnt=0;
        }

        MaxHeap(vector<T> vec, int n){
            E = new T[n+1];
            capacity = n;
            for(int i=0; i<n; ++i){
                E[i+1] = vec[i];
            }
            cnt = n;
            // heapify, 叶子节点已经是一个堆, 时间复杂度为O(N)
            for(int i = cnt/2; i>=1; --i)
                siftDown(i);
        }

        ~MaxHeap(){
            delete []E;
        }

        int size(){
            return cnt;
        }

        bool empty(){
            return this->cnt == 0;
        }

        // 从数组的1号位置开始存储
        void insert(T e){
            assert(cnt+1<=capacity);
            E[++cnt] = e;
            siftUp(cnt);
        }

        // 删除并返回堆中最大元素
        T extractMax(){
            assert(cnt > 0);
            T e = E[1];
            swap(E[1], E[cnt--]);
            siftDown(1);
            return e;
        }

    };
};
```
```c++ []
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 堆排序(原地排序)
        int N = nums.size();
        heapSort(nums, N);
        return nums;
    }

private:
    template<typename T>
    void siftDown(vector<T>& vec, int n, int k){
        while(2*k+1 < n){
            int j = 2*k+1;
            if(j+1 < n && vec[j+1]>vec[j]){
                j+=1;
            }
            if(vec[k] >= vec[j])
                break;
            swap(vec[k], vec[j]);
            k=j;
        }
    }

    template<typename T>
    void heapSort(vector<T>& vec, int n){
        // 从第一个非叶子节点开始heapify
        for(int i=(n-1)/2; i>=0; --i){
            siftDown(vec, n, i);
        }

        for(int i=n-1; i>0; --i){
            // 每次循环将最大元素置于循环序列最后, 对前面的的元素进行heapify1
            swap(vec[0], vec[i]);
            siftDown(vec, i, 0);
        }
    }
};
```
```java []
class Solution {
    public int[] sortArray(int[] nums) {
        int N = nums.length;
        if(N == 0 || nums==null)
            return nums;

        // build heap
        for(int i=(N-1)/2; i>=0; --i){
            siftDown(nums, N, i);
        }

        // sort
        for(int i=N-1; i>0; --i){
            swap(nums, 0, i);
            siftDown(nums, i, 0);
        }
        return nums;
    }

    private void siftDown(int[] nums, int N, int k){
        while(2*k+1 < N){
            int j = 2*k+1;
            if(j+1 < N && nums[j]<nums[j+1])
                j++;
            
            if(nums[k] >= nums[j])
                break;
            
            swap(nums, k, j);  
            k = j;
        }
    }

    private void swap(int[] A, int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
```
```python []
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 堆排序
        N = len(nums)
        for i in range((N-1)//2, -1, -1):
            self.siftDown(nums, N, i)

        for i in range(N-1, -1, -1):
            nums[0], nums[i] = nums[i], nums[0]
            self.siftDown(nums, i, 0)
        return nums

    # heapify
    def siftDown(self, nums, N, k):
        while 2*k+1 < N:
            # 确定调整元素与左右子元素中较大的进行交换
            j = 2*k+1
            if j+1<N and nums[j] < nums[j+1]:
                j+=1

            if nums[k] > nums[j]:
                break

            nums[k], nums[j] = nums[j], nums[k]
            k = j
```