### 解题思路
1. 首先如果数组长度等于一时无须分析，返回唯一一个数字即可
2. 因为是有序数组，再利用`arr.indexOf()`和`arr.lastIndexOf()`可得出元素数量
3. （元素数量 / 数组长度）即为出现率，大于或等于0.25就是满足条件的数，返回即可

---

> Tips : 元素数量 和 数组长度在运算时要 +1 , 否则当 arr 类似于 [1,2,3,4,5,5,6] 时会计算不出来

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = a => a.length<2 ? a[0] : a.filter(n => ((a.lastIndexOf(n) - a.indexOf(n)+1) / (a.length+1) >= 0.25))[0];

```