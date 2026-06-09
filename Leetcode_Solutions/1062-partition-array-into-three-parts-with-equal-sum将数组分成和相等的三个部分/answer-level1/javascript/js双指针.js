### 解题思路
关键点：
数组之和一定被3整除，记录除以3得到的平均数
利用双指针，从数组首尾向中间靠拢，当经过的数字之和等于平均数时指针停止移动。
指针中间至少隔了1位

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    if (!A || !A.length || A.length < 2) return false;
    let sum = 0;
    A.forEach(item => sum+=item);
    if (sum % 3 !== 0) return false;
    let average = sum / 3;
    let head = 0, tail = A.length - 1, sum1 = '0';
    sum = '0';
    while (head < tail-1) {
        if (sum === average && sum1 === average) {
            return true;
        }
        if (sum !== average) {
            sum = +sum + A[head];
            sum !== average && head++;
        }
        if (sum1 !== average) {
            sum1 = +sum1 + A[tail];
            sum1 !== average && tail--;
        }
        
    }
    return false;
};
```