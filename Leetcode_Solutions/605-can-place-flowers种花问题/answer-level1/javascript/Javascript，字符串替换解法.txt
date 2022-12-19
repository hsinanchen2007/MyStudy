我的思路和其他同学的有点不同：我是将通过'1'分隔开的坑组进行处理，通过计算得出的。
希望对大家有帮助。

**解题思路**

第一反应想到的是分组，分开求解每个坑组的可用数目，求和后与n比较。
但数组的分组并不好处理（会比较麻烦，而且可以想像性能并不好）。

- 根据"010"来分割坑组
- “1”左右的“0”是不可用的
- 考虑边界情况（最左边和最右边），最左边和最右边的“0”是可用的。
- 完全可用的坑组，最多可以放(偶数/2 或者 (奇数+1)/2)个。（4个坑最多放2个，5个坑最多放3个）

由于需要替换，这里使用了正则表达式。

```javascript []
var canPlaceFlowers = function(flowerbed, n) {
    const remainSpace = flowerbed.join('')
        .replace(/1+/g, '1')
        .replace(/010/g, ',')
	.replace(/10/g, '') .replace(/01/g, '')
        .split(',')
        .filter(x => x!=='1')
        .map(x => x.length % 2 === 0 ? x.length / 2 : Math.floor((x.length+1) / 2))
        .reduce((a,b) => a+b, 0)
    return n <= remainSpace
};
```



