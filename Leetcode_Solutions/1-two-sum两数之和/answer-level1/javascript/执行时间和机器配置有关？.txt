![Annotation 2020-03-17 145944.png](https://pic.leetcode-cn.com/7c4e31c487a324966142a7506a92a4f127689cfadcf083e66b16d3c1e707311c-Annotation%202020-03-17%20145944.png)

膜拜学习了JS最快的40ms的方法，精妙！情不自禁用8年前的AMD A4的老本提交以下，92ms。。。再用公司新发的本本Thinkpad T580(i5)提交了一遍，48ms。。。。。。

(lll￢ω￢)，上服务器工作站！

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {

    // 我的提交，180 ms
    if (false) {
        let idx = 0;

        for (let i = 0; i < nums.length; i++) {
            idx = nums.indexOf(target - nums[i]);

            if (idx != -1 && i != idx) {
                return [i, idx];
            }
        }
    }

    // 执行用时为 40 ms 的范例，精妙！

        let map = new Map();
        for (let i = 0; i < nums.length; i++) {
            let dif = target - nums[i]
            if (map.has(dif)) {
                return [map.get(dif), i]
            }
            map.set(nums[i], i);
        }
    };
```