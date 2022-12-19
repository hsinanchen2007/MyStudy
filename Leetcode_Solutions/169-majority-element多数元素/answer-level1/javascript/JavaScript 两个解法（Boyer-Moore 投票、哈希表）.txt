
## 方法一：Boyer-Moore 投票

这道题网上很多人提到 `Boyer-Moore` 投票算法，参考知乎的一个回答，我模拟下过程：

**用 array 和 result 两个数组模拟**
一个 “隐性数组” array，array 存储的是 “当前暂时无法删除的数字”、还有一个结果数组 “result”，result 里面存储的是每次删除一对元素之后的当前结果。

输入： `[1, 2, 1, 3, 1, 1, 2, 1, 5]`

* 从第一个数字 1 开始，我们想要一个不等于 1 的数字和 1 抵消，但是只扫描了一个1，暂时无法抵消，存入 array -> `[1]`，result 由于没有抵消任何元素，所以还是 result -> `[1, 2, 1, 3, 1, 1, 2, 1, 5]`
* 继续扫描到第二个元素 2，和 1 不等，抵消，array -> `[]`，result -> `[1, 3, 1, 1, 2, 1, 5]`
* 扫描第三个元素 1，无法抵消，存入array，array -> `[1]`，result -> `[1, 3, 1, 1, 2, 1, 5]`
* 扫描到 3，和 1 不等，抵消，array -> `[]`，result -> `[1, 1, 2, 1, 5]`
* 扫描到 1，array -> `[1]`，result -> `[1, 1, 2, 1, 5]`
* 扫描到 1，array -> `[1, 1]`（这里我们发现！array里只可能存在一种数，因为只有当 array 为空或者当前扫描到的数和 array 里的数字相同才把这个数字放入 array），result -> `[1, 1, 2, 1, 5]`
* 扫描到 2，把它和一个 1 抵消，至于抵消哪个 1，无所谓，array -> `[1]`，result -> `[1, 1, 5]`
* 扫描到 1，array -> `[1, 1]`，result -> `[1, 1, 5]`
* 扫描到 5，和其中一个 1 抵消，array -> `[1]`，result -> `[1]`
至此扫描完了数组里的所有数，result 里剩下 1，所以 1 就是所求。回顾整个过程，就是抵消了 `(1, 2)` | `(1, 3)` | `(1, 5)`， 剩下了一个 1。

**用 major 和 count 变量模拟（优化）**
前面分析过程的时候就说了：
> array里只可能存在一种数，因为只有当 array 为空或者当前扫描到的数和 array 里的数字相同才把这个数字放入 array
所以，可以不用数组，只用一个变量 major 来存下一个数，然后用另一个变量 count 表示当前还有多少个没有抵消的数字。当 count 为 0 时，表示抵消完了。

输入： `[1, 2, 1, 3, 1, 1, 2, 1, 5]`

major 初始化为任意数
count  初始化为0

* 扫描 1，count 是 0（没有元素可以和当前的 1 抵消），major -> 1，count -> 1（此时有一个 1 无法被抵消）
* 扫描 2，不等于 major，抵消，major -> 1，count -> 0（抵消完了）
* 扫描 1，等于 major，count -> 1
* 扫描 3，不等于 major，抵消，major -> 1，count -> 0 （抵消完了）
* …
* 扫描 5，不等于 major，抵消，major -> 1，count -> 1

至此扫描结束，还剩一个 1 没有抵消，它就是我们要找的数。

```js
var majorityElement = function(nums) {
    let major = 0, count = 0;
    for (let i = 0; i < nums.length; i += 1) {
        if (count === 0) major = nums[i];
        nums[i] === major ? count ++ : count --;
    }
    return major;
};
```

## 方法二：用一个 HashMap 记录下次数
用一个对象存每个数字出现的次数，根据题目说明必然存在出现了`n/2`次的数，循环过程中加个判断即可。
```js
var majorityElement = function(nums) {
    const obj = {};
    for (let i = 0; i < nums.length; i += 1) {
        obj[nums[i]] = obj[nums[i]] + 1 || 1;
        if (obj[nums[i]] > nums.length / 2) return nums[i];
    }
};
```