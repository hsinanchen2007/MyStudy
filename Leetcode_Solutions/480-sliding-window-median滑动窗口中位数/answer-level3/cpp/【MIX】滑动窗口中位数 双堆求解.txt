### 解题思路
1. 需要底层为支持删除操作`remove`的堆(平衡二叉树实现), 维护一个大顶堆和一个小顶堆(Java)
2. `multiset`和中位数迭代器实现(C++)
3. 自定义堆`HashHeap`结构(Python)

### 代码

```java []
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        int N = nums.length;
        double []res = new double[N-k+1];
        if(N == 0)
            return res;
        
        pqMax = new PriorityQueue<Integer>((Integer n1, Integer n2)->{
            if(n1 < n2) return 1;
            else if(n1 == n2) return 0;
            else return -1;
        });
        pqMin = new PriorityQueue<Integer>();
        int index = 0; // 在res中移动的指针
        for(int i=0; i<N; ++i){
            // 和数据流求中位数思路一致, 当元素<=pivot时加入大顶堆, 默认无元素时加入大顶堆
            if(pqMax.size()==0 || pqMax.peek()>=nums[i]) pqMax.offer(nums[i]);
            else pqMin.offer(nums[i]);
            balance(); // 堆平衡调整
            // 对元素淘汰
            if(i>=k){
                if(nums[i-k] > pqMax.peek()) pqMin.remove(nums[i-k]);
                else pqMax.remove(nums[i-k]);
            }
            balance(); // 堆平衡调整
            // 堆结果加入
            if(i>=k-1){
                if((k & 0x01)==1) res[index++] = pqMax.peek();
                else res[index++] = ((double)pqMax.peek()+(double)pqMin.peek())/2.0;
            }
        }

        return res;
    }

    // 保持两侧堆元素数量 0<=(#pqMax - #pqMin)<=1
    private void balance(){
        while(pqMax.size() > pqMin.size()+1) pqMin.offer(pqMax.poll());
        while(pqMax.size() < pqMin.size()) pqMax.offer(pqMin.poll());
    }

    private PriorityQueue<Integer> pqMax; // 大顶堆
    private PriorityQueue<Integer> pqMin; // 小顶堆
}
```
```c++ []
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // 多重集合+迭代器
        // 需要不断计算中位数值向结果向量中添加
        vector<double> res;
        int N = nums.size();
        if(N == 0)
            return res;
        // 使用multiset, 底层实现为RBTree, 具备自动排序的特性
        multiset<int> REC(nums.begin(), nums.begin()+k);
        auto mit = next(REC.begin(), k/2); // 迭代器指向中位数的位置
        
        int i = k;
        while(i<=N){
            if((k&0x01)==1) res.push_back((double)(*mit));
            else res.push_back(((double)(*mit)+(double)(*prev(mit)))/2.0);

            if(i == N) break;

            // 插入新元素, 并进行中位数迭代器调整
            REC.insert(nums[i]);
            if(nums[i] < *mit) --mit;
            if(nums[i-k] <= *mit) ++mit;
            // 删除第一个大于或等于nums[i-k]的元素
            REC.erase(REC.lower_bound(nums[i-k]));
            ++i;
        }
        return res;
    }
};
```
```python []
class HashHeap:
    def __init__(self, desc=False):
        self.hash = dict()
        self.heap = []
        self.desc = desc

    @property
    def size(self):
        return len(self.heap)

    def push(self, e):
        self.heap.append(e)
        self.hash[e] = self.size-1
        self._sift_up(self.size-1)

    def pop(self):
        e = self.heap[0]
        self.remove(e)
        return e

    def top(self):
        return self.heap[0]

    def remove(self, e):
        if e not in self.hash:
            return
        
        idx = self.hash[e]
        self._swap(idx, self.size-1)

        del self.hash[e]
        self.heap.pop()

        if idx < self.size:
            self._sift_up(idx)
            self._sift_down(idx)

    def _smaller(self, left, right):
        return right<left if self.desc is True else left<right

    # 向上调整堆结构
    def _sift_up(self, index):
        while index != 0:
            parent= index//2
            if self._smaller(self.heap[parent], self.heap[index]):
                break
            self._swap(parent, index)
            index = parent

    # 向下调整堆结构
    def _sift_down(self, index):
        if index is None:
            return
        
        while index*2 < self.size:
            smallest = index
            left, right = index*2, index*2+1
            if self._smaller(self.heap[left], self.heap[smallest]):
                smallest = left
            if right < self.size and self._smaller(self.heap[right], self.heap[smallest]):
                smallest = right
            if smallest == index:
                break
            
            self._swap(index, smallest)
            index = smallest

    # 交换元素
    def _swap(self, x, y):
        e1 = self.heap[x]
        e2 = self.heap[y]
        self.heap[x] = e2
        self.heap[y] = e1
        self.hash[e1] = y
        self.hash[e2] = x

     
class Solution:
    K = 0
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        if not nums or len(nums) < k:
            return []
            
        self.maxheap = HashHeap(desc=True)
        self.minheap = HashHeap()
        self.K = k

        for i in range(0, k - 1):
            self.add((nums[i], i))
            
        medians = []
        for i in range(k - 1, len(nums)):
            self.add((nums[i], i))
            medians.append(self.median)
            self.remove((nums[i - k + 1], i - k + 1))
            
        return medians
            
    def add(self, item):
        if self.maxheap.size > self.minheap.size:
            self.minheap.push(item)
        else:
            self.maxheap.push(item)
            
        if self.maxheap.size == 0 or self.minheap.size == 0:
            return
            
        if self.maxheap.top() > self.minheap.top():
            self.maxheap.push(self.minheap.pop())
            self.minheap.push(self.maxheap.pop())
        
    def remove(self, item):
        self.maxheap.remove(item)
        self.minheap.remove(item)
        if self.maxheap.size < self.minheap.size:
            self.maxheap.push(self.minheap.pop())
        
    @property
    def median(self):
        if self.K % 2==1:
            return self.maxheap.top()[0]
        else:
            return (self.maxheap.top()[0]+self.minheap.top()[0])/2

```