### 暴力破解
暴力破解思路很简单，一个盆可以装多少水取决于最低的那个缺口，直接拿数组的取第一个元素，不管它多长总有 `undefined` 的时候
```javascript
var longestCommonPrefix = function (strs) {
    // 特殊情况 strs 为空 `[]`，为 单数组 `['x']` ,这些情况可以取值直接拿就好
    return strs == 0 ? "" : strs.length == 1 ? strs[0] : ((t = '') => {
        // 匿名函数我有定义 `t = ''`
        for (let v of strs[0]) {
            t += v; 
            for (let i in strs) { // 遍历数组元素
                if (strs[i].indexOf(t) != 0) { // 判断存在并且第一个下标为 0
                    return t.substring(0, t.length - 1);
                }
            }
        }
        return t;
    })();
}
*/
```
时间还早给你们来一段暴力破解的 `动画` , 假设 `strs = ['abcad','abd','abx'];`
> 第一次循环
> > |strs[i]|t |strs[i].indexOf(t) == 0|
> > |:------|:-|:----------------------|
> > |abcad  |a |true                   |
> > |abd    |a |true                   |
> > |abx    |a |true                   |
> > ---
> 第二次循环
> > |strs[i]|t  |strs[i].indexOf(t) == 0|
> > |:------|:- |:----------------------|
> > |abcad  |ab |true                   |
> > |abd    |ab |true                   |
> > |abx    |ab |true                   |
> > ---
> 第三次循环
> > |strs[i]|t   |strs[i].indexOf(t) == 0|
> > |:------|:---|:----------------------|
> > |abcad  |abc |true                   |
> > |abd    |abc |false                  |
> > |abx    |abc |false                  |

### 复杂化的代码
这有一点迷不知道怎么怎么说，应该是比较接近`人`的思维吧，假设 `strs = ["flower","flow","flight"]`,我们想的时候会不会拿第一个下标和第二个下标进行比较`"flower","flow"`,70%的人应该都会这样，所以这也是这样，当我们拿`"flower","flow"`比较以后发现`flow`是公共前缀，然后在拿它去和其他字符串去比较.
```javascript
var longestCommonPrefix = function (strs) { // 疯狂压缩
    return strs == 0 ? '' : strs.length == 1 ? strs[0] : (([t, s, m] = ['', strs.length - 1, strs[0].length]) => {
        // 直接拿暴力破解的第一句再追加 s，m 两个变量
        for (let i = 0; i < m; i++){
            // 直接拿第一个下标元素和第二个下标元素进行对比
            [t, i] = strs[0][i] === strs[1][i] ? [t + strs[0][i], i] : [t, m];
        }
        for (let i = s; i >= 2; i--) {
            let is = true;
            while (is) {
                const l = t.length;
                if (l == 0) {
                    // 当字符串 t 的长度等于0直接退出
                    return '';
                } else {
                    // 比较以后发现开始位置不低于0 就进行去掉 t 的最后一位字符否则跳过改字符串循环
                    [t, is] = strs[i].indexOf(t) != 0 ? [t.substring(t, l - 1), true] : [t, false];
                }
            }
        }
        return t;
    })();
};
```
我比较推荐暴力破解，因为假设数组是 ['ab','ab','c'] 的时候因为在第一个循环就决定了是否有公共前缀，而且代码还容易看懂