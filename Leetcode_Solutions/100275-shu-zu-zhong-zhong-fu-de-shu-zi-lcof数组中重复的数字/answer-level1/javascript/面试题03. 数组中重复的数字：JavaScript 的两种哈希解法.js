## 方法一

### 解题思路

使用哈希表来进行处理，因为哈希表本身不允许出现重复元素，所以当添加元素失败或已经包含该数字时，则表示出现了重复元素，将其返回即可。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const numSet = new Set();
    for(const num of nums) {
        if(numSet.has(num)){
            return num;
        }

        numSet.add(num);
    }
    return -1;
};
```

**复杂度分析：**

- 时间复杂度：O(n)
- 空间复杂度：O(n)


## 方法二

### 解题思路

- 从题目描述中我们可以看出，因为所有数字都在 0 ～ n-1 的范围内，其实完全可以省掉额外的空间开辟，将每个位置的数交换映射到其对应的数组下标下面，当出现新的元素与其对应的下标中的数字相等时，即为重复数字。
- 这本质还是哈希的思想，思路 1 是使用库函数申请额外空间，思路 2 则是数组本身做哈希表，达到了节省空间的目的。
- 此处会用到 while 循环，原因是保证交换过来的新元素位置也要正确。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const len = nums.length;

    for(let i = 0; i < len; i++) {
        while(nums[i] !== i) {
            if(nums[i] === nums[nums[i]]) {
            return nums[i];
            }

            const temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;
        }
    }
    
    return -1;
};
```

**复杂度分析：**

- 时间复杂度：O(n)
- 空间复杂度：O(1)

---

> 注意：本题基于 [画解算法：面试题3. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/hua-jie-suan-fa-mian-shi-ti-3-shu-zu-zhong-zhong-f/) 撰写

---

**更多题解请关注**：[https://github.com/leviding/leetcode-js-leviding](https://github.com/leviding/leetcode-js-leviding)
