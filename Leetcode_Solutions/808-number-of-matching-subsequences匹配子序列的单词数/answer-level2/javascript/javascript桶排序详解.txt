### 解题思路

大家好，我是 17

依据官方给出的桶排序算法的javascript版本

算法
1. 把所有单词按首字母分 26 组，也叫装桶
2. 迭代 S 中的每个字母 c ,找到 c 开头的所有单词
3. 取出这一组单词 list，同把原来桶中的单词清空。
4. 迭代 list 中的每个单词，发现长度为 1 ，答案 +1 ，否则 去掉道字母后装桶。

看官方给的例子 `words = ['dog', 'cat', 'cop']  S = 'dcaog'`

初始化 bucket=[], 字母a 的charCode是97，a 对应的是第一个桶
第一个单词 dog,首字母是 d 对应 的桶是 `'d'.charCodeAt(0)-97`，也就是3
`bucket[3]=['dog']`
`'cat', 'cop'` 对应的是 2号桶
`bucket[2]=['cat','dog']`

为了好描述下面会用字母表示是哪个桶，比如 2号桶是` bucket[c]`
桶初始化完毕，下面开始迭代 S

第一个字母 d 对应的桶 是 ['dog'],发现dog长度不为1，去掉d,把og装桶

```javascript

bucket=[
 d: []
 c: ['cat','cop']
 o: [ 'og' ]
]

```
官方没有解释 d 桶为什么清空，我来解释一下。比如本例中的 S 如果改成 ’ddcaog‘ 加了个字母 d。第一次判断后，如果不把 d 的桶清空，后面第二个 d 又会找到 d 桶，再添加一个’og‘ 进来，这样会导致结果加倍。

迭代字母 c 后

```javascript
 bucket=[
 d: ['at']
 o: [ 'og','op' ]
]
```
迭代字母 a 没找到桶，直接到 o

迭代字母 o 后

```javascript
 bucket=[
 d: ['at',]
 g:[g],
 p:['p']
]
```

迭代字母 g  发现 g:[g] 是答案。

全部字母迭代完毕。

在存的时候用到了一个技巧，存单词和单词的索引，因为这个就避免了 substring 操作，提高了速度。



### 代码

```javascript
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function (S, words) {
  let bucket = Array.from({ length: 26 }, () => [])
  for (let word of words) {
    bucket[word.charCodeAt(0) - 97].push({
      word,
      index: 0
    })
  }
  let count = 0
  for (let c of S) {
    let list = bucket[c.charCodeAt(0) - 97]
    bucket[c.charCodeAt(0) - 97] = []
    let len = list.length
    for (let i = 0; i < len; i++) {
      let {word,index }=list[i]
      if (index === word.length - 1) {
        count++
      }
      else {
        index++
        bucket[word.charCodeAt(index) - 97].push({
          word,
          index
        })
      }
    }

  }
  return count
};
```
也可以用 map 做桶，写法差不多。