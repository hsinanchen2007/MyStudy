### 解题思路
为了减轻遍历次数，可以计算出需要会循环多少次track；
然后只用遍历一次num_people根据remain(剩余多少)和track(遍历次数)对应赋值即可
res[i] = a + base; 其中a是当前需要给的糖果，可能为0，base为之前轮次给的糖果
base公式为：(num_people * (track * (track - 1)) / 2) + track * (i + 1)，自己品吧!
其实就是(b + 0n) + (b + 1n) + (b + 2n) +  ...。
### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    const oneTraverse = (1 + num_people) * num_people / 2;
    let track = 0, remain = candies;
    while (remain > oneTraverse + num_people * track * num_people) {
        remain -= oneTraverse + num_people * track * num_people;
        track += 1;
    }
    const res = Array.from({length: num_people});
    for (let i = 0; i < num_people; i++) {
        const base = (num_people * (track * (track - 1)) / 2) + track * (i + 1);
        if (remain) {
            let a = i + 1 + track * num_people;
            a = remain > a ? a : remain;
            res[i] = a + base;
            remain -= a;
        } else {
            res[i] = base;
        }
    }
    return res;
};
```