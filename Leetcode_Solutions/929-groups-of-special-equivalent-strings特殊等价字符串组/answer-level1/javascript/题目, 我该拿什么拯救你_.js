### 解题思路

真的是我阅读理解不行么??  看半天题目描述, 依旧一脸懵逼....

其实:

1. 有个数组, 元素是 字符串
2. 字符串中的字符 两两交换 , 交换的字符 索引 满足i ％ 2 == j ％ 2, 就是说 奇跟奇, 偶跟偶 交换
3. 不管交换多少次, 只要 字符串交换后 有和 另一个字符串交换 后 相同, 就为等价的
4. 把这些等价的字符串归为 一个数组中
5. 求 有多少个这样的数组


既然 奇跟奇, 偶跟偶 交换,  我们何不 把字符串的字符索引为  奇 和 偶 的分离开来, 各放到一个数组中

然后 奇 偶 数组排序下, 再拼接起来,  如果它们是 **特殊等价**  的话, 这样的处理下来, 得到的就会是 完全相等的字符串

```js
//如: 
A = ["abcd","cdab","adcb","cbad"]

// 奇偶分离
A = [
      [['a','c'],['b','d']],
      [['c','a'],['d','b']],
      [['a','c'],['d','b']],
      [['c','a'],['b','d']]
    ]

// 排序
A = [
      [['a','c'],['b','d']],
      [['a','c'],['b','d']],
      [['a','c'],['b','d']],
      [['a','c'],['b','d']]
    ]

// 拼接
A = ['acbd','acbd','acbd','acbd']

// 去重
A = ['acbd']

// 返回长度即可

```

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {number}
 */
var numSpecialEquivGroups = function(A) {
    let list = A.map(item => {
      let arr = item.split('')
      let odd = arr.filter((t,i) => i%2===1).sort().join('')
      let event = arr.filter((t,i) => i%2===0).sort().join('')
      return event+odd
    })
    return [...new Set(list)].length
};
```