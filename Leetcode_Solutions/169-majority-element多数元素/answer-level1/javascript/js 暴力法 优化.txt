### 解题思路

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
维护一个最大值，省去第二次遍历

### 代码

```javascript
/**
 * 169. 多数元素
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
维护一个最大值，省去第二次遍历
 */

 /**
  * 暴力
  * 使用map存n个数字，遍历，匹配的+1 最后计算长度
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let len = nums.length;
    let lists = new Map();

    let maxNum = 1;
    let maxEl = nums[0];
    for(let e of nums) {
        if(lists.has(e)) {
            lists.set(e, lists.get(e) + 1);

            //max
            if(lists.get(e) > maxNum) {
                maxEl = e;
                maxNum = lists.get(e);
            }
        } else {
            lists.set(e, 1);
        }
    }

    return maxEl;
};


```