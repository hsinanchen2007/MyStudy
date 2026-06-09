解题思路：
1. 使用splice方法，先将nums2数组合并到nums1
2. 采用排序算法，对新的nums1进行排序，即可得到一个有序数组

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    // 1. 将nums2添加到nums1
    nums1.splice(m,n,...nums2);
    // 2. 对新的nums1进行排序
    insertionSort(nums1);
    
    // 插入排序
    function insertionSort(arr) {
        var len = arr.length;
        var preIndex, current;
        for (var i = 1; i < len; i++) {
            preIndex = i - 1;
            current = arr[i];
            while(preIndex >= 0 && arr[preIndex] > current) {
                arr[preIndex+1] = arr[preIndex];
                preIndex--;
            }
            arr[preIndex+1] = current;
        }
        return arr;
    }
};