### 解题思路
由于两个数组的特殊性：两个数组都是排序后的数组。同时数组A有足够的缓冲空间。所以选择A存储排序后的数组。
步骤：比较A[m-1]和B[n-1]的数，将较大的数保存在数组A的末尾，同时移动数组中的位置
注意：A[m-- -1]记得建议，因为数组从0开始编号，数组的下标等于数组长度减1

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A,m,B,n){
       while (m > 0 && n > 0) {
            // 对比选出较大的数放在 m + n - 1 的位置，并将选出此数的指针向前移动
            A[m + n - 1] = A[m - 1] > B[n - 1] ? A[m-- -1] : B[n-- - 1];
        }
        // 剩下的数都比已经遍历过的数小
        // 如果 m 不为 0，则 A 没遍历完，都已经在 A 中不用再管
        // 如果 n 不为 0，则 B 没遍历完，直接全移到 A 中相同的位置
        while (n > 0) {
            A[n - 1] = B[n - 1];
            n--;
        }
};

```