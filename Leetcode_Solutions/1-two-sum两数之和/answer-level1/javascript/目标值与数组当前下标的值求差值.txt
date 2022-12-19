依次遍历数组。

用目标值`target`与数组当前下标的值做减法运算，得到一个差`d`。

然后用`Array.prototype.indexOf()`到数组中寻找是否存在`d`这个数。

> 这里要注意`Array.prototype.indexOf(searchValue [, fromIndex])`的第二个参数，使用这个参数来定义检索的索引。
> 例如 `twoSum([3, 2, 4], 6)`。
> 第一次遍历时，索引为0，数组下标为0的数为`3`，且目标值减去数组下标为0的数`3`也等于`3`，即`6-3=3`。
> 当差`3`和数组当前下标的值`3`相同时，使用`Array.prototype.indexOf(3)`会返回当前的下标`0`.
> 这时的结果为 [0, 0]。
> 为了避免这个情况，`Array.prototype.indexOf(3，0 + 1)`传入第二个参数即可。
> `0`为当前下标，`0+1`代表从当前下标的下一个下标处开始检索差值。

若不存在，则继续下一次循环。

若存在，则返回遍历的当前索引作为第一个下标；`Array.prototype.indexOf()`的返回值作为第二个下标。

完整代码：

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function(nums, target) {
  for(let i in nums) {
    const index = nums.indexOf(target - nums[i], (+i + 1));

    if(index !== -1) {
      return [+i, index];
    }
  }
};
```