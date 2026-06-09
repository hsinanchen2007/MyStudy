![CleanShot 2019-07-27 at 12.47.12@2x.bcf37ef6345247afbd6e08fd292e7b0a.png](https://pic.leetcode-cn.com/51dff72ab841130317e6d5144a05332fc174e12b73e89be94aac5b474072c4d5-CleanShot%202019-07-27%20at%2012.47.12@2x.bcf37ef6345247afbd6e08fd292e7b0a.png)


## 解题分析

> query = "hello" -> "hellooo" -> "helllllooo" = S。

**解题成功的标准：**
1. 如果目标是一个字母，只匹配一个字母
2. 如果目标是两个字母，只匹配两个字母
3. 如果目标是三个字母，匹配1到3个字母
4. 如果目标字母在三个以上，匹配1到n个字母

通过分析S的字符串结构，来构建对应的正则表达式。
然后对words进行批量检查，筛选。返回筛选后数组长度即可。

```
例如
"heeelloooooo"
将它转化为正则表达式/he{1,3}l{2}o{1,6}/

符合条件的有：
"heeello"
"heello"
"hello"
"helloooo"
"hellooooo"
"helloooooo"
...
```

## 特殊情况处理

```
S="aaa"
words=["aaaa"]
```
这种情况下，`/a{1,3}/.test("aaaa")`的输出其实是true的，这种情况就与我们期望不一样了。

怎么办呢？

__使用断言。__

> 正则表达式的先行断言和后行断言一共有4种形式： 
> - (?=pattern) 零宽正向先行断言(zero-width positive lookahead assertion) 
> - (?!pattern) 零宽负向先行断言(zero-width negative lookahead assertion) 
> - (?<=pattern) 零宽正向后行断言(zero-width positive lookbehind assertion) 
> - (?<!pattern) 零宽负向后行断言(zero-width negative lookbehind assertion) 

将之前的匹配模式优化一下。

```
/a{1,2}/ => /(?<!a)a{1,2}(?!a)/

/a{1,2}/.test("aaaa") => true
/(?<!a)a{1,2}(?!a)/.test("aaaa") => false
```

## 最终代码

```javascript []
var expressiveWords = function(S, words) {
    let reg = ""
    let counter = 1
    for (let i = 0; i < S.length;i++) {
        let cur = S.charAt(i)
        let next = S.charAt(i + 1)
        if (cur === next) {
            counter++
            continue;
        }
        if (cur !== next) {
            if (counter >= 3) {
                reg += `(?<!${cur})` + `(${cur}{1,${counter}})` + `(?!${cur})`
                counter = 1
                continue;
            }
            if (counter === 2) {
                reg += `(?<!${cur})` + `${cur}{${counter}}` + `(?!${cur})`
                counter = 1
                continue;
            }
            reg += `(?<!${cur})` + cur + `(?!${cur})`
            continue;
        }
    }
    
    let checkRE = new RegExp(reg)

    return words.filter(x => checkRE.test(x)).length
};
```



