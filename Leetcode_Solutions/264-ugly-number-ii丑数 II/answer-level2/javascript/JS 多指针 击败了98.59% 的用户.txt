整体思路有两种，一种是很简单的 直接判断数字是否丑数，然后打表。
第二种是设置三个变量 p2 p3 p5分别代表 公因数 2 3 5的个数

从1开始，由于1是特殊的丑数。
然后分别递增 2 3 5的乘数
因为丑数是只包含2 3 5为因数，因此 后续的丑数必然是由前面的丑数*2/3/5得到。

然后三个指针分别计数，如果指针位置的丑数*指针的值等于当前的丑数，该指针加一

```
/**
 * @param {number} n
 * @return {number}
 */
// 执行用时 : 96 ms, 在Ugly Number II的JavaScript提交中击败了98.59% 的用户
// 内存消耗 : 37.1 MB, 在Ugly Number II的JavaScript提交中击败了40.00% 的用户
var nthUglyNumber = function(n) {
    let ret=[1],p2=0,p3=0,p5=0;
    while(n>0)
        {
            let temp = Math.min(ret[p2]*2,ret[p3]*3,ret[p5]*5)
            ret.push(temp)
            if(ret[p2]*2==temp)
                {p2++}
            if(ret[p3]*3==temp)
                {p3++}
            if(ret[p5]*5==temp)
                {p5++}
            n--;
        }
    return ret[ret.length-2]
};
```