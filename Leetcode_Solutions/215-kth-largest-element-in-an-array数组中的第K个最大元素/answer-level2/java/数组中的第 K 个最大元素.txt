
#### 方法零：排序

最朴素的方法是先对数组进行排序，再返回倒数第 k 个元素，就像 Python 中的 `sorted(nums)[-k]`。
算法的时间复杂度为 $O(N \log N)$，空间复杂度为 $O(1)$。这个时间复杂度并不令人满意，让我们试着用额外空间来优化时间复杂度。

#### 方法一：堆

思路是创建一个大顶堆，将所有数组中的元素加入堆中，并保持堆的大小小于等于 `k`。这样，堆中就保留了前 `k` 个最大的元素。这样，堆顶的元素就是正确答案。

像大小为 `k` 的堆中添加元素的时间复杂度为 ${O}(\log k)$，我们将重复该操作 `N` 次，故总时间复杂度为 ${O}(N \log k)$。

在 Python 的 `heapq` 库中有一个 `nlargest` 方法，具有同样的时间复杂度，能将代码简化到只有一行。 

本方法优化了时间复杂度，但需要 ${O}(k)$ 的空间复杂度。
        
<![image.png](https://pic.leetcode-cn.com/0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png),![image.png](https://pic.leetcode-cn.com/a0a8884c1593080a46d7928282922cc0cfb4850e30c7433a06dc48836bde446c-image.png),![image.png](https://pic.leetcode-cn.com/88d2f3663b76229c414346abd178aec40d87519dfee0ecda3184930997529d0b-image.png),![image.png](https://pic.leetcode-cn.com/882b50c54fbf798ba601321f773f9cafcb1d32515d4ec17948e6b1a94c1257ee-image.png),![image.png](https://pic.leetcode-cn.com/6ceb387953a60a188a60c5af64acf0b2d66b031c9efd901d8bccd94a36aafef9-image.png),![image.png](https://pic.leetcode-cn.com/98af6a4fcd855e4e89a7d0d2a95b3458097528dcf7c75e71a7bbc816224d6db9-image.png),![image.png](https://pic.leetcode-cn.com/9ea7b0a74ab45ce35ee534ac10e3faed07017781053134015b14fa46c9dd335d-image.png),![image.png](https://pic.leetcode-cn.com/3e579347b949bff791493f70353991929090b506885045ad5bbd362d7f305cdc-image.png),![image.png](https://pic.leetcode-cn.com/6537c2b2968211e0ac9d37f1b200087eb97f3c838b1cb30c060926f0e2e447e1-image.png),![image.png](https://pic.leetcode-cn.com/3e7f7180e34550acb24ea5eb0077d1153549102c2214ad7c35bdb5b1a243b413-image.png),![image.png](https://pic.leetcode-cn.com/c41f3c8ec069db1e12aa0505a0d3b04fa340d2473772b60c623a2635a8275aec-image.png)>


```Java [solution 1]
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // init heap 'the smallest element first'
        PriorityQueue<Integer> heap =
            new PriorityQueue<Integer>((n1, n2) -> n1 - n2);

        // keep k largest elements in the heap
        for (int n: nums) {
          heap.add(n);
          if (heap.size() > k)
            heap.poll();
        }

        // output
        return heap.poll();        
  }
}
```

```Python [solution 1]
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return heapq.nlargest(k, nums)[-1]
```


**复杂度分析**

* 时间复杂度 : ${O}(N \log k)$。 
* 空间复杂度 : ${O}(k)$，用于存储堆元素。
<br />
<br />


---
#### 方法二：快速选择

 [快速选择算法](https://en.wikipedia.org/wiki/Quickselect) 的平均时间复杂度为 ${O}(N)$。就像快速排序那样，本算法也是 Tony Hoare 发明的，因此也被称为 _Hoare选择算法_。

本方法大致上与快速排序相同。简便起见，注意到第 `k` 个最大元素也就是第 `N - k` 个最小元素，因此可以用第 `k` 小算法来解决本问题。

首先，我们选择一个枢轴，并在线性时间内定义其在排序数组中的位置。这可以通过 _划分算法_ 的帮助来完成。

> 为了实现划分，沿着数组移动，将每个元素与枢轴进行比较，并将小于枢轴的所有元素移动到枢轴的左侧。

这样，在输出的数组中，枢轴达到其合适位置。所有小于枢轴的元素都在其左侧，所有大于或等于的元素都在其右侧。

这样，数组就被分成了两部分。如果是快速排序算法，会在这里递归地对两部分进行快速排序，时间复杂度为 ${O}(N \log N)$。

而在这里，由于知道要找的第 `N - k` 小的元素在哪部分中，我们不需要对两部分都做处理，这样就将平均时间复杂度下降到 ${O}(N)$。

最终的算法十分直接了当 :

* 随机选择一个枢轴。

* 使用划分算法将枢轴放在数组中的合适位置 `pos`。将小于枢轴的元素移到左边，大于等于枢轴的元素移到右边。

* 比较 `pos` 和 `N - k` 以决定在哪边继续递归处理。

> ! 注意，本算法也适用于有重复的数组


![image.png](https://pic.leetcode-cn.com/1c1fe2ba0c651a7916a77114d58478fd5f52a7fc9b4bf554101f0b3c1047a8c0-image.png)


```Java [solution 2]
import java.util.Random;
class Solution {
  int [] nums;

  public void swap(int a, int b) {
    int tmp = this.nums[a];
    this.nums[a] = this.nums[b];
    this.nums[b] = tmp;
  }


  public int partition(int left, int right, int pivot_index) {
    int pivot = this.nums[pivot_index];
    // 1. move pivot to end
    swap(pivot_index, right);
    int store_index = left;

    // 2. move all smaller elements to the left
    for (int i = left; i <= right; i++) {
      if (this.nums[i] < pivot) {
        swap(store_index, i);
        store_index++;
      }
    }

    // 3. move pivot to its final place
    swap(store_index, right);

    return store_index;
  }

  public int quickselect(int left, int right, int k_smallest) {
    /*
    Returns the k-th smallest element of list within left..right.
    */

    if (left == right) // If the list contains only one element,
      return this.nums[left];  // return that element

    // select a random pivot_index
    Random random_num = new Random();
    int pivot_index = left + random_num.nextInt(right - left); 
    
    pivot_index = partition(left, right, pivot_index);

    // the pivot is on (N - k)th smallest position
    if (k_smallest == pivot_index)
      return this.nums[k_smallest];
    // go left side
    else if (k_smallest < pivot_index)
      return quickselect(left, pivot_index - 1, k_smallest);
    // go right side
    return quickselect(pivot_index + 1, right, k_smallest);
  }

  public int findKthLargest(int[] nums, int k) {
    this.nums = nums;
    int size = nums.length;
    // kth largest is (N - k)th smallest
    return quickselect(0, size - 1, size - k);
  }
}
```

```Python [solution 2]
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def partition(left, right, pivot_index):
            pivot = nums[pivot_index]
            # 1. move pivot to end
            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]  
            
            # 2. move all smaller elements to the left
            store_index = left
            for i in range(left, right):
                if nums[i] < pivot:
                    nums[store_index], nums[i] = nums[i], nums[store_index]
                    store_index += 1

            # 3. move pivot to its final place
            nums[right], nums[store_index] = nums[store_index], nums[right]  
            
            return store_index
        
        def select(left, right, k_smallest):
            """
            Returns the k-th smallest element of list within left..right
            """
            if left == right:       # If the list contains only one element,
                return nums[left]   # return that element
            
            # select a random pivot_index between 
            pivot_index = random.randint(left, right)     
                            
            # find the pivot position in a sorted list   
            pivot_index = partition(left, right, pivot_index)
            
            # the pivot is in its final sorted position
            if k_smallest == pivot_index:
                 return nums[k_smallest]
            # go left
            elif k_smallest < pivot_index:
                return select(left, pivot_index - 1, k_smallest)
            # go right
            else:
                return select(pivot_index + 1, right, k_smallest)

        # kth largest is (n - k)th smallest 
        return select(0, len(nums) - 1, len(nums) - k)
```

**复杂度分析**
* 时间复杂度 : 平均情况 ${O}(N)$，最坏情况 ${O}(N^2)$。
* 空间复杂度 : ${O}(1)$。
