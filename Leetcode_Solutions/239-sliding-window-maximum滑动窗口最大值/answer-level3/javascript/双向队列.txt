### 解题思路
1. 滑动窗口，下标很重要，因为要用下标去确定元素是不是滑动超出窗口，没有下标不行。  下标找元素复杂度O（1），元素找下标复杂度O（n）
2. 用deque保存下标值，在每次新元素来之前（就是移动窗口的时候）  先检查deque的第一个是不是从窗口滑动出去了。 用deque保存第一位永远是最大的值（的下标）
3. 新来元素，如果比第一个值大（就是它是最新且最大的） 那它就是老大，排在deque的第一个就是它的下标，就因为它值大而且年轻（下标最大）
4. 如果它没有deque的第一个元素大，就让它从栈顶比较，它大就把栈顶的顶出去（爷比你大还比你年轻），可以预知这样式顶不到头的，所以不用做边界处理（就是第三步的意义）
5. 最后每来一个，处理完后就将deque[0]的下标在nums中对应的值打入res（最终结果）数组中就完事了

特别注意的一点是，纵然第一个窗口是一下跳出来的，你也不能直接求最大值，就比如k是3，前三个是【3，2，1】
这时你需要把三个都保存下来，deque = 【0，1，2】  如果再来个1  那么deque就是【1，2，3】 
看到没，保存前面的下标作用就出现了，也就是说 我们deque只有一种情况能丢弃数据信息
*爷比你大还比你年轻*
其他情况，只比你大，或者只比你年轻，都是不能丢弃的信息。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {
    if (nums.length === 0 || nums.length < k)
        return []
    let res = []
    let queue = []
    for (let i = 0; i < nums.length; i++) {
        if (queue[0] == (i - k))
            queue.shift()
        if (nums[i] > nums[queue[0]] || queue.length == 0) {
            queue = [i]
        } else {
            while (nums[queue[queue.length - 1]] < nums[i]) {
                queue.pop()
            }
            queue.push(i)
        }
        res.push(nums[queue[0]])
    }
    return res.slice(k - 1)
};
```