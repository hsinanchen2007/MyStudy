![image.png](https://pic.leetcode-cn.com/7da6618953539e16a1e6bb57610cdd2bfd482b70197042ce4eb4013bd3d7f5de-image.png)

### 解题思路
###### 感觉这道题至少也是 简单+ 的级别
1. 思路就是把 K 转换为字符串的数组，从后向前遍历，与 A对应的位置 相加
2. 主要是考虑以下各种边界条件
- 遍历终止的条件是 K 遍历完 或者 进位等于 0，比如`[9,9,9] 1`，这组测试用例，最后的 1 加上 9 等于 10，数组的最后一位被加成 10，当前位写 0，进位为 1，这时候，虽然 K 已经遍历结束，但是 进位为 1，所以要继续计算
- 当 A 已经遍历完首位的时候，如果没有到终止条件的话（也就是 K 没有遍历完，或者进位不为 0），那么需要继续计算，此时 向 A 数组首位前插入一个元素 0 ，继续计算即可。
- 遍历终止后，判断进位如果不为 0，把他插入到数组 A 的首位。因为一直是两个 1 位数的相加，所以进位永远最大只能是 1 位

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */

var addToArrayForm = function(A, K) {
  if (!K) return A;
  
  K = String(K).split('');
  let index = A.length - 1, carry = 0;
  while (K.length > 0 || carry > 0) {
    let k = K.length > 0 ? Number( K.pop() ) : 0;
    if (index === -1) {
      A.unshift( 0 );
      index++;
    }
    
    let sum = k + A[index] + carry;
    if (sum > 9) {
      sum = String( sum );
      carry = Number( sum.slice(0, sum.length - 1) );
      sum = Number( sum[ sum.length - 1 ] );
    }
    else {
      carry = 0;
    }
    
    A[index] = sum;
    index--;
  }
  
  if (carry !== 0) {
    A.unshift( carry );
  }
  
  return A;
};





```