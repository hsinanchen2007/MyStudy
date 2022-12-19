### 解题思路 归并排序

学习来自大佬[c++ 归并排序 【面试题51. 数组中的逆序对】](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/c-gui-bing-pai-xu-mian-shi-ti-51-shu-zu-zhong-de-n/)

    /*
     * 归并排序
     *
     * 使用归并排序的思想，在排序的过程中能够计数逆序对的个数：
     * 1. 将数组的数据不断的对半分，直到分解成长度为1的子数组；
     * 2. 把长度为1的子数组合并、排序，同时统计逆序对的个数；
     * 3. 把长度为2的子数组合并、排序，同时统计逆序对的个数；
     * 4. 依步骤2,3的操作对子数组不断合并、排序，返回最终的逆序对的个数。
     *
     * 这里重点是如何在归并排序合并过程中统计逆序对的个数：
     * 1. 合并两个子数组之前，子数组中的数是有序的；
     * 2. 使用两个指针，分别指向两个子数组的末尾元素；
     * 3. 比较指针指向的元素，如果前一个子数组指针指向的元素大于后一子数组指针指向的元素，
     *    则前一指针指向的数能够与后一指针指向的数前面的所以数组成逆序对（包括该数本身），
     *    将逆序对的个数加上后一指针指向数的索引加1，将较大的数复制到空数组中，前一子数组指针前移；
     * 4. 重复步骤3的比较，将两个子数组合并复制到一个数组中，同时也统计了逆序对的个数。
     * */
### 代码

```cpp
int reversePairs(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    // 合并数组用
    std::vector<int> copyNums(nums.size(), 0);

    // 逆序对的个数
    int count = 0;
    mergeSort(nums, copyNums, 0, nums.size() - 1, count);

    return count;
}

void mergeSort(std::vector<int> &nums, std::vector<int> &copyNums, int start, int end, int &count) {
    // 只有一个数，不存在逆序对
    if (start >= end) {
        return;
    }

    // 将序列划分为对等的两部分
    int mid = start + (end - start) / 2;

    // 递归划分左部分
    mergeSort(nums, copyNums, start, mid, count);
    // 递归划分右部分
    mergeSort(nums, copyNums, mid + 1, end, count);

    // 优化2：如果数组的这个子区间本身有序，无需合并
    if (nums[mid] <= nums[mid + 1]) {
        return;
    }


    // 划分结束后，实行线性合并操作

    // 定义两区间的指针i和j
    // 分别指向两区间的第一个数
    int i = start, j = mid + 1;

    // 计数器
    int k = 0;

    // 两指针都未结束遍历前
    while (i <= mid && j <= end) {
        // 比较指针i指向的数与指向j指向的数，
        // 将较小的数放入临时数组copyNums中
        if (nums[j] < nums[i]) {
            copyNums[k++] = nums[j++];
            // 后一子序的数小于前一子序产生逆序对，
            // 计算逆序对为前一子序i及i后数的个数
            count += (mid - i + 1);
        } else {
            copyNums[k++] = nums[i++];
        }
    }

    // 如果j指针提前结束，
    // 将i指针对应区间剩下的数依次放入临时数组
    while (i <= mid) {
        copyNums[k++] = nums[i++];
    }

    // 如果i指针提前结束，
    // 将j指针对应区间剩下的数依次放入临时数组
    while (j <= end) {
        copyNums[k++] = nums[j++];
    }

    // 每次计算当前合并子序列的大小，
    // 将临时数组内已经排序好的数放回原数组对应部分
    int len = end - start + 1;
    for (int i = 0; i < len; i++) {
        // 注意索引的对应
        nums[start + i] = copyNums[i];
    }
}
```