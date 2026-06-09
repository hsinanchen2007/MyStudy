![Snipaste_2020-04-05_19-30-49.png](https://pic.leetcode-cn.com/da5ebec39d1c57febb059e9165ba622ba4e664d1fa3bee7eff7ea1f81e553fdb-Snipaste_2020-04-05_19-30-49.png)

### 解题思路
方法一：剑指Offer思路，利用了众数的特点
时间复杂度:O(n),空间复杂度:O(1)
方法二：桶排序的思路
时间复杂度:O(n),空间复杂度:O(n)

### 代码
方法一
```javascript
var majorityElement = function (nums) {
    let now = 1;
    let result = nums[0];
    for (let i = 1; i < nums.length; i++) {
        if (now === 0) {
            result = nums[i];
            now = 1;
        } else if (result === nums[i]) {
            now++;
        } else {
            now--;
        }
    }
    return result
};
```
方法二
```javascript
var majorityElement = function (nums) {
    let len = nums.length;
    // 使用哈希表存储每个数字出现的频率
    let hashMap = new Map();
    for (let i = 0; i < len; i++) {
        // 已经出现则次数+1，次数超过长度的一半则返回该元素
        if (hashMap.has(nums[i])) {
            let val = hashMap.get(nums[i]) + 1;
            hashMap.set(nums[i], val);
            if (val > len >> 1) return nums[i];
        } else {
            hashMap.set(nums[i], 1);
        }
    }
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/6dcefecf9455c300c07e05a7f7e4bc75d5d365c6406f5f0c2fd47b16ba4c8446-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

