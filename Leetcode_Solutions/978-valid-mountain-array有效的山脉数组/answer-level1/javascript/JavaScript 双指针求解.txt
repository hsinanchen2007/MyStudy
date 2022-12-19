### 解题思路
- 双指针思路进行求解，通过 left 和 right 从左边和右边进行遍历
- left 和 right 都只能达到倒数第二个的位置
- 最后left 和 right 的位置相等， 则说明找到了同一个位置

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
 var validMountainArray = function(A) {
    if(A.length < 3) return false
    let left = 0
    let right = A.length - 1
    while( left < A.length - 2 && A[left] < A[left + 1]){
        left ++
    }
     while( right > 1 && A[right] < A[right - 1]){
         right --
     }
     return left === right
};

```