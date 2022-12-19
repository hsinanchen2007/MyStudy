### 解题思路
很容易想到的是用**栈**或者**正负1**来相互抵消，但是碰到“（（（））”这样的case，会出现“balance不等于0，于是未触发记录“最大数”的动作，导致最大数结果为0其实为4”的错误出现。卡了几天，越想越复杂，后来抵抗不住诱惑看了“题解”。。。。。。。。。。。。。

真相原来如此美丽简约，反过来再来一遍就行了。。。。。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function (s) {
    if (s.indexOf("(") === -1 || s.indexOf(")") === -1) {
        return 0;
    }

    let bal = 0,
        val = 0,
        ret = 0,
        len = 0;

    for (let i = s.indexOf('('); i < s.length; i++) {
        val = s[i] == "(" ? 1 : -1;
        bal += val;
        if (bal >= 0) {
            len++;
            if (bal == 0) {
                ret = Math.max(len, ret);
            }
        } else {
            bal = len = 0;
        }
    }

    len = val = bal = 0;
    for (let i = s.lastIndexOf(")"); i >= 0; i--) {
        val = s[i] == "(" ? -1 : 1;
        bal += val;
        if (bal >= 0) {
            len++;
            if (bal == 0) {
                ret = Math.max(len, ret);
            }
        } else {
            bal = len = 0;
        }
    }

    return ret;

};
```