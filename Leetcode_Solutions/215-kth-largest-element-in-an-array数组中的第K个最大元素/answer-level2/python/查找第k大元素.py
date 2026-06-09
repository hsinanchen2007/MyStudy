### 解题思路
入口函数：findKthLargest
分区函数：partition
        根据随机生成的分区点，将分区值放置数组最后，存储数组第一个index为store_index，该函数将所有比分区值小的item放置在左侧。每次检测出小的值将其与store_index交换，并更新store_index的值。最后将store_index的值与数组最右侧的分区值进行交换。此时已经完成第一次划分，左侧值都比分区值小，右侧值都比分区值大。并返回store_index值。
选择函数：select
        通过random随机生成分区点，交由partition对数组进行分区，用partiton的返回值更新pivlot_index的值。通过pivlot_index与len(nums)-k即k_smallest进行对比，如果二者值相同即返回nums[k_smallest]为最终值，如果不等需要递归性对区间进行划分

时间复杂度分析：使用快排时，先划分区间，再对每个区间进行递归整个的时间复杂度是O(nlogn)，而查找第k大元素，不需要在每一个区间都进行递归，而是根据条件在其中一个区间内递归即可。所以最后的时间复杂度为O(n)

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(left,right,pivlot_index):
            pivlot = nums[pivlot_index]
            nums[pivlot_index],nums[right] = nums[right],nums[pivlot_index]
            
            store_index = left
            for i in range(left,right):
                if nums[i] < pivlot:
                    nums[store_index],nums[i] = nums[i],nums[store_index]
                    store_index += 1
            
            nums[store_index],nums[right] = nums[right],nums[store_index]
            
            return store_index
        
        def select(left,right,k_smallest):
            if left == right:
                return nums[left]

            pivlot_index = random.randint(left,right)
            pivlot_index = partition(left,right,pivlot_index)

            if pivlot_index == k_smallest:
                return nums[k_smallest]
            
            elif pivlot_index < k_smallest:
                return select(pivlot_index+1,right,k_smallest)
            else:
                return select(left,pivlot_index-1,k_smallest)
        
        return select(0,len(nums)-1,len(nums)-k)
```