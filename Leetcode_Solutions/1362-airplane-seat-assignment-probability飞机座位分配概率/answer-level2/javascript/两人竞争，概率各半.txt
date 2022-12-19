### 解题思路
1.如果只有一个位置，一定是对的
2.当大于两个位置时，只有一个人不知道其位置，若坐到别人的位置，另一个人也随机坐，此时还是只有一个人同我竞争，概率是一半，等效于两人坐。
3.若有两人不知座位随机坐，则三人竞争，概率是1/3.等

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var nthPersonGetsNthSeat = function(n) {
    return n==1?1:.5;
};
```