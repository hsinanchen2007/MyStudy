### 解题思路
首先你要知道`归并排序`的流程：

- 先将数组分成两部分，然后分别将这两部分排好序；
- 然后开一个 helper 数组，指针 a 和 b 分别指向这两个部分的第一个元素；
- 比较指针 a 所指元素与指针 b 所指元素的大小，将小的元素放进 helper 数组中；
- 如果某个指针遍历到对应部分的末尾的话，则需要将另一个指针所指元素以及它后面的元素直接添加到 helper 数组中；
- 最后再将 helper 数组中的数据拷贝到原数组中即可。

**重点在于在两个指针比较的过程中，如果第一个子数组中的数字大于第二个子数组中的数字，则可以构成逆序对，并且逆序对的数目就是第二个子数组中剩余数字的个数。**

### 代码：含注释
```
class Solution {
    // 用于统计逆序对的数量
    int res;
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } 
        
        res = 0;
        mergeSort(nums, 0, nums.length - 1);
        return res;
    }
    
    // 归并排序整体逻辑
    public void mergeSort(int[] nums, int left, int right) {
        // 如果两个指针相遇，则说明已经排好序
        if (left == right) {
            return;
        }
        
        int middle = left + ((right - left) >> 1);
        // 对数组的左半部分进行归并
        mergeSort(nums, left, middle);
        // 对数组的右半部分进行归并
        mergeSort(nums, middle + 1, right);
        merge(nums, left, middle, right);
    }
    
    // 归并排序合并的过程
    public void merge(int[] nums, int left, int middle, int right) {
        int[] help = new int[right - left + 1];
        int i = 0;
        // pos1 指向左半部分数组中第一个元素
        int pos1 = left;
        // pos2 指向右半部分数组中第一个元素
        int pos2 = middle + 1;
        
        while (pos1 <= middle && pos2 <= right) {
            // 运算符 <= 是为了去除元素相等的情况
            // 例如在 [1, 3, 2, 3, 1] 中，排除 [1, 1] 和 [3, 3] 的情况
            if (nums[pos1] <= nums[pos2]) {
                // 将元素较小的放进 help 数组中
                help[i++] = nums[pos1++];
            } else if (nums[pos1] > nums[pos2]) {
                help[i++] = nums[pos2++];
                // 本题核心：由于 nums[pos1] > nums[pos2]，
                // 则从 nums[pos1] 到 nums[middle] 必定都是大于 nums[pos2] 的，
                // 因为两部分的子数组已经是各自有序的
                res += (middle - pos1 + 1);
            }
        } 
        
        // 下面这两个 while 是当其中一个子数组中的指针如果已经遍历完了，
        // 那么另一个子数组肯定会有剩余元素，所以将剩余部分直接放到 help 中
        while (pos1 <= middle) {
            help[i++] = nums[pos1++];
        }
        while (pos2 <= right) {
            help[i++] = nums[pos2++];
        }
        // 将 help 中的元素拷贝到原数组
        for (int j = 0; j < help.length; j++) {
            nums[left + j] = help[j];
        }
    }
}
```

### 代码：不含注释
```
class Solution {
    int res;
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } 
        
        res = 0;
        mergeSort(nums, 0, nums.length - 1);
        return res;
    }
    
    public void mergeSort(int[] nums, int left, int right) {
        if (left == right) {
            return;
        }
        
        int middle = left + ((right - left) >> 1);
        mergeSort(nums, left, middle);
        mergeSort(nums, middle + 1, right);
        merge(nums, left, middle, right);
    }
    
    public void merge(int[] nums, int left, int middle, int right) {
        int[] help = new int[right - left + 1];
        int i = 0;
        int pos1 = left;
        int pos2 = middle + 1;
        
        while (pos1 <= middle && pos2 <= right) {
            if (nums[pos1] <= nums[pos2]) {
                help[i++] = nums[pos1++];
            } else if (nums[pos1] > nums[pos2]) {
                help[i++] = nums[pos2++];
                res += (middle - pos1 + 1);
            }
        } 
        
        while (pos1 <= middle) {
            help[i++] = nums[pos1++];
        }
        while (pos2 <= right) {
            help[i++] = nums[pos2++];
        }
        for (int j = 0; j < help.length; j++) {
            nums[left + j] = help[j];
        }
    }
}
```

### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)