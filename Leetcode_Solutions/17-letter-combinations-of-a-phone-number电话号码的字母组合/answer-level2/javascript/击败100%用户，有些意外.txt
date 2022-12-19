### 解题思路
这个结果有些意外，哈哈哈，还是忍不住想发出来，思路其实很好理解，看代码也能看出来，大概步骤如下：
1、枚举所有键盘的按键字符
2、遍历digits并通过索引得到字母(如:abc)
3、res为空数组的时候初始化第一个按键产生的字母组合
4、到了第二个以后的按键只用从现有res种取到所有现有字母组合并和此按键的元素拼接字符串即可
![微信图片_20191207170853.png](https://pic.leetcode-cn.com/f59ab920a4b1a4de118b04b85d4976e1594dfc5441819fb43e2d3251398a6c0f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191207170853.png)

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    const maps = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz"
    }
    const res = [];
    for (let num of digits) {
        let w = maps[num];
        if (res.length > 0) {
            let tmp = [];
            for (let i = 0; i < res.length; i++) {
                let wl = w.length;
                for (let j = 1; j < wl; j++) {
                    tmp.push(res[i] + w[j])
                }
                res[i] += w[0];
            }
            res.push(...tmp)
        } else {
            res.push(...w);
        }
    }
    return res;

};
```