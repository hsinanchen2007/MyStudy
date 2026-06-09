### 解题思路
+ 遇到数组： 双指针，快慢指针考虑
+ 题解:
    1. 此题已排序的数组A和数组B 合并到数组A，
    2. 因数组A足够大，已有未使用的空间，考虑用尾插，
    3. 比较两指针位置的值，填充到数组A的末尾
    4. 若数组A遍历完后，数组B还有剩n个的话，替换数组A前n个

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    let len1 = m - 1;
    let len2 = n - 1;
    let count = m+n-1;

    while(len1 >=0 && len2 >= 0){
        A[count--] = A[len1] > B[len2] ? A[len1--] : B[len2--];
    }


    function arrayCopy(src, srcIndex, dest, destIndex, length) {
        dest.splice(destIndex, length, ...src.slice(srcIndex, srcIndex + length));
    }

    // 表示将数组B从下标0位置开始，拷贝到数组A中，从下标0位置开始，长度为len2+1
    arrayCopy(B, 0, A, 0, len2 + 1);
};
```