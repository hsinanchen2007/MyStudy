```
/**
 * @param {number[]} chips
 * @return {number}
 */
var minCostToMoveChips = function(chips) {
    var even = 0
    var odd = 0
    chips.forEach(item => {
        if(item % 2 === 0){
            even++
        }else{
            odd++
        }
    })
    return even < odd ? even : odd 
};
```
读了很久的题目和评论才明白了一些：
- 1.首先理解筹码的概念：给出的数组一个萝卜（筹码）一个坑，坑上给你看的是筹码的位置，具象一些就是筹码都一样，位置和个数不一样。用一维数组表示了原来是二维层面上的东西，光看题目，只有费解。
- 2.其次就是题目要求的答案的意思：要求将所有筹码移动到同一位置的最小代价。
    - 2.1.移动偶数位不用代价，移动奇数位代价为1
    - 2.2.代价最小的情况：计算偶数位与奇数位分别的筹码个数，谁的个数少移动谁
- 我晕了@@