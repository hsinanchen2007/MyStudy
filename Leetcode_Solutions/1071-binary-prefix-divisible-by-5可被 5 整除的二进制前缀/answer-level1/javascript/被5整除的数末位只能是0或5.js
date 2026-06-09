# 只考虑十进制最后一位的运算
1. 能被5整除的数末位只能是0或5
2. 所以我们只需计算最后一位的变化
3. 判断最后一位是否为0或5就能得到结果了
4. 理论上二进制可以是无限位
5. 时间复杂度O(n)
![TIM图片20190920163921.png](https://pic.leetcode-cn.com/5783bdf591f0a6e9496f1d090873678fa4a28203643b324b689867555424855b-TIM%E5%9B%BE%E7%89%8720190920163921.png)
```
/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(A) {
    var ans = [];
    var last = A[0];
    ans[0] = last == 0;
    for (var i = 1;i < A.length;i++) {
        last *= 2;
        if (A[i] == 1) {
            last++;
        }
        last = last + '';
        last = last[last.length - 1] * 1;
        ans[i] = last == 0 || last == 5;
    }
    return ans;
};
```
