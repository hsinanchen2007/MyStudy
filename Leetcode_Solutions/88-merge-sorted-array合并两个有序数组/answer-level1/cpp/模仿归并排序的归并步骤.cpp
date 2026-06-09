
## 类比归并排序的归并步骤

在归并排序的归并步骤中，用两个探针遍历两个子数组，对比最小元素，将更小的那个加入一个额外的合并数组
本问题相当于将合并数组的部分存储空间已经在第一个数组的后面准备好了，所以我们可以直接模仿归并步骤，用双探针遍历两个子数组的并对比最大元素，将较大的放到第一个数组的最后

## 关键问题

什么时候可以确定归并结束？（即循环退出条件）第一个数组遍历结束时？还是第二个数组遍历结束时？
- 如果第一个数组遍历结束，第二个数组还没有，则说明第二个数组还存在有“没有复制到合并数组”的元素，那么归并显然没有完成
- 如果第一个数组遍历没有结束，第二个数组结束了，那么根据归并的判断条件，第一个数组的遍历探针停留处之后的元素一定比它大，之前的元素一定是第一个数组中原来就比它小的元素，因此此时已经满足次序了，没有必要继续再把第一个数组遍历完了

因此我们的主循环只需确保第二个数组的完整遍历；在循环内部，分类讨论第一个数组没有遍历完（进行归并步骤）和遍历完（直接把第二个数组的元素复制到合并数组中）的情况

## 效率分析

时间复杂度：
- Best case：O(n)，当第二数组全都比第一个数组的大时，但不管怎样，第二数组总得完整遍历一遍，
- Worst case: O(m+n)，这种情况第二个数组遍历完时，第一个也遍历的差不多了

空间复杂度：
O(1)，因为用于存储的数组就是第一个数组及其后面的空间，直接往里面复制就行了

## Code

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Regard m, n as probes for two sub-arrays, and m+n as a probe for the memory array
        // Traverse from tail to head and do the merge procedure

        while(n >= 1){ // The 2nd array must be  fully traversed
            if(m >= 1 && nums1[m-1] > nums2[n-1]){ // Still merging, nums1's element is bigger
                nums1[m+n-1] = nums1[m-1];
                --m;
            }
            else{ // 1. Nums1 fully traversed; 2. Still merging, nums2's element is bigger  
                nums1[m+n-1] = nums2[n-1];
                --n;
            }
        }

    }
    
};
```

