由题意可知三个部分每一部分的 1 的个数都相等，区别在于前导 0 的个数不同。先计算数组中总共有3x个 1，每个部分就有x个 1，我们从数组的末尾开始往前遍历，直到我们遇到x个 1 停下，这样我们就知道了没有前导 0 的情况下每个部分的序列是什么样的了。我们知道，数组的结构一定是这样的, [n1个0, part1, n2个0, part2, n3个0, part3], 然后我们再从头开始遍历数组，先跳过所有的前导 0，然后我们开始比较 part1和part3是否相等，如果不相等说明无解，如果相等，我们再跳过n2个 0，比较 part2和part3是否相等，如果不相等说明无解.

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var threeEqualParts = function(A) {
    //算法的时间复杂度O(N**2)
    let first_split_idx, second_split_idx;
    let nof_one = 0;
    for(let n of A) {
        if(n === 1) nof_one++;
    }
    if(nof_one % 3 !== 0) return [-1, -1];
    if(nof_one === 0) {
        //特殊情况
        return [0,A.length - 1];
    }
    let nof_one_div_three = nof_one / 3;
    let nof_one_in_last = 0;
    //先找到 last part
    let i;
    for(i = A.length - 1; i >= 0; i--) {
        if(nof_one_in_last === nof_one_div_three) {
            break;
        }
        if(A[i] === 1) nof_one_in_last++;
    }
    let last_begin = i + 1;
    let last_part = A.slice(last_begin);
    let mid_begin,first_begin;
    //然后找 first part
    let first_non_zero;
    for(let i = 0; i <= last_begin - last_part.length * 2; i++) {
        if(A[i] === 0) continue;
        else {
            first_non_zero = i;
            break;
        } 
    }
    if(first_non_zero === undefined) return [-1, -1];
    for(let j = first_non_zero; j < first_non_zero + last_part.length; j++) {
        if(A[j] !== last_part[j - first_non_zero]) {
            //如果题目有解，那么必然这部分和 last_part必然是相等的。否则题目没有解
            return [-1, -1];
        }
    }
    first_split_idx = first_non_zero + last_part.length;
    //下面寻找是否存在 mid part
    //先跳过先导的 0
    first_non_zero = undefined;
    for(let i = first_split_idx; i <= last_begin - last_part.length ; i++) {
        if(A[i] === 0) continue;
        else {
            first_non_zero = i;
            break;
        }
    }
    if(first_non_zero === undefined) return [-1, -1];
    for(let i = first_non_zero; i < first_non_zero + last_part.length; i++) {
        if(A[i] !== last_part[i - first_non_zero]) return [-1, -1];
    }
    //寻找到了 mid part和 last part 相等
    second_split_idx = first_non_zero + last_part.length;
    return [first_split_idx-1, second_split_idx];
};
```