### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var maximum = function(a, b) {
var k = (a+b)/2;/*取得两数的平均数*/
k = k + Math.abs(a-k);/*K值加上到其中任何一个数的距离*/
return k;
};
```