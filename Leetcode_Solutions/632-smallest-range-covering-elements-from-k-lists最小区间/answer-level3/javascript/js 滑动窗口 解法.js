
### [632\. 最小区间](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/)

Difficulty: **困难**


你有 `k` 个升序排列的整数数组。找到一个**最小**区间，使得 `k` 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 `b-a < d-c` 或者在 `b-a == d-c` 时 `a < c`，则区间 [a,b] 比 [c,d] 小。

**示例 1:**

```
输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释:
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
```

**注意:**

1.  给定的列表可能包含重复元素，所以在这里升序表示 >= 。
2.  1 <= `k` <= 3500
3.  -10<sup>5</sup> <= `元素的值` <= 10<sup>5</sup>
4.  **对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。**


### Solution

Language: **JavaScript**

#### 解题思路
**主要思路**
要找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中，要找最小区间那么就先排序，然后再去遍历元素，要使得 k 个列表中的每个列表至少有一个数包含在其中，那么在排序之前得给每一个元素打上一个标签，标记其属于哪个列表，然后维护一个滑动窗口来遍历所有元素。

**详细步骤**
1. 先循环列表 `nums`，将列表中的每个数字都映射成一个数组，数组的第一项是其值，第二项是该数字所在`nums` 列表中的子列表的索引，用来标记其属于哪个子列表，并将所有的映射后的数组放入一个新的数组`objNums`中
2. 对 `objNums` 中所有的数据按照其子数组中第一项数字的大小进行排序
3. 维护一个滑动窗口，开始遍历 `objNums`，从窗口右边放入元素，如果是第一次放入一个子列表的值，就将计数器 `count++`
4. 如果`count` == 所有子列表的数量和，那就说明每个列表至少有一个数包含在窗口里面，那么窗口的左右边界的值，就是一个符合要求的解
5. 但是题目要求最小的区间，所以我们可以记录下区间的左边界值和区间的差值，比较每一个符合要求的解的差值，并保留差值较小的解
6. 找到符合要求的区间后，我们从窗口的左边删除一个该类型元素，如果该类型的元素全部删除完，就要更新计数器`count--`，然后再从窗口右边加入新元素。
7. 直到循环遍历结束，返回符合要求的最小区间解

#### 代码

```javascript
/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var smallestRange = function(nums) {
    let numsLen = nums.length, count = 0;
    let l = 0, r = 0, needs = {}, start = 0, ansLen = Infinity;
    /*****  合并数组方法一 start *****/
    // let objNums = nums.reduce((accumulator, currentVal, idx) => {
    //     return accumulator.concat(currentVal.map(n => [n, idx]))
    // }, [])
    /*****  合并数组方法一 end *****/

    /*****  合并数组方法二 start *****/
    let objNums = [];
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums[i].length; j++) {
            objNums.push([nums[i][j], i])
        }
    }
    /*****  合并数组方法二 end *****/

    /*****  合并数组方法三 start *****/
    // let objNums = nums.reduce((accumulator, currentVal, idx) => {
    //     let t = currentVal.map(n => [n, idx])
    //     accumulator.push(...t)
    //     return accumulator;
    // }, [])
    /*****  合并数组方法三 end *****/
    objNums.sort((a, b) => (a[0] - b[0]))
    while (r < objNums.length) {
        let v1 = objNums[r];
        needs[v1[1]] ? needs[v1[1]]++ : (needs[v1[1]] = 1) && count++;
        while (count === numsLen) {
            if (objNums[r][0] - objNums[l][0] < ansLen) {
                ansLen = objNums[r][0] - objNums[l][0];
                start = objNums[l][0]
            }
            if (--needs[objNums[l++][1]] === 0) count--;
        }
        r++;
    }
    return [start, start + ansLen];
};
```

**时间复杂度**：`O(nlog(n))`，`n` 为所有元素的数量和
排序时间复杂度是`O(nlog(n))`，滑动窗口循环遍历元素的时间复杂度为`O(n)`，所以总的时间复杂度是`O(nlog(n))`

**空间复杂度**：`O(n)`，`n` 为所有元素的数量和

#### 性能优化

在我上面的解法中，对于合并数组有三种方式

```js
    /*****  合并数组方法一 start *****/
    let objNums = nums.reduce((accumulator, currentVal, idx) => {
        return accumulator.concat(currentVal.map(n => [n, idx]))
    }, [])
    /*****  合并数组方法一 end *****/

    /*****  合并数组方法二 start *****/
    let objNums = [];
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums[i].length; j++) {
            objNums.push([nums[i][j], i])
        }
    }
    /*****  合并数组方法二 end *****/

    /*****  合并数组方法三 start *****/
    let objNums = nums.reduce((accumulator, currentVal, idx) => {
        let t = currentVal.map(n => [n, idx])
        accumulator.push(...t)
        return accumulator;
    }, [])
    /*****  合并数组方法三 end *****/
```

一个是使用`reduce` + `concat`，一种是直接使用`for`循环，还有一种是使用 `reduce` + `push`，但是最后发现使用`concat`的执行用时与不使用`concat`差距非常大

**方法一：**
![方法一](https://pic.leetcode-cn.com/91b2aff7749cefe727fbe6f618c9c6dfe66da12d081e759849aca98492dbe514.png)

**方法二：**
![方法二](https://pic.leetcode-cn.com/3a69d262a16eaddaff6bfbedb1cf32094c10075ea31dd62fc0bff88524c488cd.png)

**方法三：**
![方法三](https://pic.leetcode-cn.com/67a28e6c234c455d4e6a43069e668f7291e5fddcda932aca9661bb7bc95ddffa.png)

#### 总结
`concat` 的原理是申请一个新数组，然后将`concat`的两个数组都拷贝这个新数组中，这可能是其性能差的主要原因，还有个原因可能是在循环中频繁创建新对象，会多次引发 `js` 的垃圾回收机制的运行，这个也比较耗时。所以尽量少使用 `concat`，特别是在循环或迭代中最好不要使用`concat`。
