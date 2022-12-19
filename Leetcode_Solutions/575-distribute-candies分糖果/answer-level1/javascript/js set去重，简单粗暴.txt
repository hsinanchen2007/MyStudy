### 解题思路
![image.png](https://pic.leetcode-cn.com/d859fdb30d0aace252d723e62e810ca88083e8c2e3921faa6b368d295dc35049-image.png)
因为要将糖果平均分，去重后set的大小就是糖果的种类数量
=：每个人都拿到了一样的糖果数，并且糖果种类也一样
<：糖果种类比糖果数一半还少，那说明拿到的有重复种类的糖果
\>: 种类比自己能拿到的糖果数还多

### 代码

```javascript
/**
 * @param {number[]} candies
 * @return {number}
 */
var distributeCandies = function(candies) {
    let set = new Set(candies);
    if(set.size <= candies.length/2) return set.size;
    if(set.size > candies.length/2) return candies.length/2;
};
```