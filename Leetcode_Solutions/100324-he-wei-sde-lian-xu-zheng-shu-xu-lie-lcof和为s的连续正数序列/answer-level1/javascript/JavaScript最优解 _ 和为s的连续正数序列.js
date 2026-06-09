![image.png](https://pic.leetcode-cn.com/87d23c77c556cf43c0acfccdccd121ab6c17237f51b3fce04023a94025c5f408-image.png)

### 解题思路

**优不优不重要，重要的是好理解**

题中序列为差是1 的等差数列，等差数列求和公式为 Sn = (A1 + An) * n / 2 或者 Sn = nA1 + n(n - 1) * d / 2

解：设答案为resArr,数组第一位left，第二位right，当前求和结果cur,目标结果target

因为后一位肯定大于前一位，当left>right,不考虑

当left<right时，利用等差数列公式求cur
    
    1. 若cur小于target，将right往后移
    2. 若cur大于target时，将left往后移
    3. 若cur等于target时，将left至right的值以数据的形式放入resArr中，然后left往后移，继续循环

最终返回resArr

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    var left=1
    var right=2
    var resArr=[]
    var cur
    while(left<right){
        cur=((left+right)*(right-left+1))/2
        if(cur<target){
            right++
        }
        if(cur>target){
            left++
        }
        if(cur===target){
            var _arr=[]
            for(var i=left;i<=right;i++){
                _arr.push(i)
            }
            resArr.push(_arr)
            left++
        }
    } 
    return resArr  
};

```