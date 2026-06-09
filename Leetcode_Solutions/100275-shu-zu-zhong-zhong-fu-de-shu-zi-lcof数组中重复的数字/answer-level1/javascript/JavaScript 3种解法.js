### 解题思路

#### 1. 排序

数据排序后，比较当前值与后一位的值是否相同，相同则返回。

时间复杂度：O(nlogn) 为一个长度n的数组排序

空间复杂度：O(n) 需要一个额外的等长度的数组空间

#### 2. 哈希表

遍历数组，当前值在哈希表中的话，则返回当前值，否则则加入哈希表

时间复杂度：O(n) 遍历一次当前数组

空间复杂度：O(n) 需要一个额外的哈希表

#### 3. JS API Set

这种方法是对上一次方法的拓展

利用ES6中的Set，Set中的每个元素只允许出现一次。

遍历数组，当前值加入set后，判断set长度是否改变，若不变，则证明当前值为重复值

时间、空间复杂度同上

#### 4. 交换位置

可见上面的方法以空间换时间，那有没有什么空间复杂度比较低的方法呢？

由于题目的条件是 `nums 里的所有数字都在 0～n-1 的范围内` ，我们可以借用一个额外的变量，来将数组中的所有值，换在与他们值相同的索引上。如果索引上已有一个相同的值，则证明该值重复。

具体步骤是，从第一个元素开始，查看nums[元素值]是否与元素值相同，是则返回元素值。否则则交换这两者。

时间复杂度：O(n) 虽然有两层循环，但是每个元素值最多只需要交换两次则能到自己的位置上，所以时间复杂度不高。

空间复杂度：O(1) 

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

// 第2种解法
var findRepeatNumber = function(nums) {
  let obj = {};
  for(let item of nums) {
    if (!obj[item]) {
      obj[item] = true;
    } else {
      return item
    }
  }
};

// 第3种解法
var findRepeatNumber = function(nums) {
  let setList = new Set();
  for(let i in nums) {
    let size = setList.size;
    setList.add(nums[i])
    if ( setList.size == size) {
      return nums[i]
    }
  }
};

// 第4种解法
var findRepeatNumber = function(nums) {
  if(!nums || nums.length == 1) return false;
  for(let i = 0; i < nums.length; ++i) {
    while(nums[i] != i) {
      if (nums[i] == nums[nums[i]]) {
        return nums[i];
      }
      swapPositin(nums, i, nums[i])
    }
  }
};

var swapPositin = function(arr, i, j) {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
```