```
/**把从某个元素开始遍历到有环为止的一系列数称为序列
 * 1.任何两个元素不可能到达同一个元素
 * 2.出现环就意味着某个序列最后一个元素的值是第一个元素的下标
 * 3.因为任何两个元素不可能到达同一个元素，所以任何两个环不可能有相同元素、即不相交。
 * 那么任何访问过的元素在原数组中标记一下，即可避免重复遍历已经遍历过的环
 * 4.总结起来，这道题就是找环的最大长度
 * @param {number[]} nums
 * @return {number}
 */
var arrayNesting = function(nums) {
    let ans = 0
    for(let i = 0;i < nums.length; i++) {
        let start = i
        let count = 0
        while(nums[start] !== Infinity) {
            count++
            let temp = start
            start = nums[start]
            nums[temp] = Infinity
        }
        if(count > ans) ans = count
    }
    return ans
};
```
