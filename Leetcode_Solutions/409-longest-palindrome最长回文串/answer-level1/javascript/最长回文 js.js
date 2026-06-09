### 解题思路
回文即左右对称。
最多出现对称轴处1个奇数字符串填充，对称轴左右两侧剩余都为偶数长度的字符串填充。
可转化为由 Odd(非1的奇数字符串总长度)+Even(偶数字符串总长度)+1(个数：0 ~ 1) 组成。
第一步统
计所有字母的数量（hash map）
第二步
数据分类
如果存在数量为1的字符，同类型的有且只有1组能被使用，用于填充对称轴。此时长度结果中 1的个数为1
如果存在数量为非1的奇数个数的字符串，全部减1后视为可用于对称轴左右填充的字符，累加得到 Odd
如果存在数量为偶数个数的字符串，全部视为可用于对称轴左右填充的字符，累计得到 Even
第三部
数据矫正
当数据中不存在长度为1的字符且存在奇数长度字符时，此时统计的值还可以填充1个字符（第二步中为了转为偶数长度，减了1）。所以补1.

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const countMap = new Map();
    s.split('').map((i) => {
        countMap.set(i, countMap.has(i) ? countMap.get(i)+1 : 1)
    });
    let allOdd = 0;
    let allEven = 0;
    let oneNum = false;
    countMap.forEach((value, key) => {
        if(value === 1){
            if(!oneNum){
                oneNum = true;
            }
        }else if(value%2 !== 0) {
            allOdd += (value - 1);
        }else {
            allEven += value
        }
    })
    return allOdd + allEven + (!oneNum && allOdd !==0 ? 1 : 0) + (oneNum? 1 : 0)
};
```