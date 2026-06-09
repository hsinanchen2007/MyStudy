#### 思路
1. 根据括号有效性划分原语；
2. 记录原语位置，拼接得到结果；
3. 时间复杂度：O(N)，空间复杂度：O(1)。

![截屏2020-04-06 下午10.44.01.png](https://pic.leetcode-cn.com/f1344dd7b9b55947fa7b826cdf1885938eabd8561161368a558d6123980aff67-%E6%88%AA%E5%B1%8F2020-04-06%20%E4%B8%8B%E5%8D%8810.44.01.png)

#### 代码
```
var removeOuterParentheses = function(S) {
    let res = "";
    let cnt = 0;
    let start = 0;
    for (let i = 0; i < S.length; i++) {
        if (S[i] === '(') {
            cnt++;
        } else {
            if (--cnt === 0) {
                // 找到原语，拼接结果
                res += S.substring(start + 1, i);
                // 设置下一个原语起点，继续查找
                start = i + 1;
            }
        }
    }
    return res;
};
```
