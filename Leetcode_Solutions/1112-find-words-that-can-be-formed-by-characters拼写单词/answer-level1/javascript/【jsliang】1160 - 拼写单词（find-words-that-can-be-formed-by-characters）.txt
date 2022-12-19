先看懂题目意思：

1. 给定一份词汇表 `words` 和一份字母表 `chars`。
2. 判断 `chars` 是否能构成 `words` 中的词汇。
3. 字母表 `chars` 中的字母在对同一个词汇中只能使用一次。
4. 返回能构成词汇的长度和。

示例：

> 示例 1

```
输入：
words = ['cat', 'bt', 'hat', 'tree']
chars = 'atach'

输出：6

解释：
能够组成 'cat' 和 'hat' 两个字符串，长度为 3 + 3 = 6
```

> 示例 2

```
输入：
words = ['hello', 'world', 'leetcode']
chars = 'welldonehoneyr'

输出：10

解释：
能够组成 'hello' 和 'world' 连个字符串，长度为 5 + 5 = 10
```

OK，开始解题：

> 暴力破解

```js
const countCharacters = (words, chars) => {
  chars = chars.split('');
  let result = 0;
  for (let i = 0; i < words.length; i++) {
    let flag = true;
    const word = words[i].split('');
    for (let j = 0; j < word.length; j++) {
      const length1 = word.filter(item => item === word[j]).length;
      const length2 = chars.filter(item => item === word[j]).length;
      if (length1 > length2) {
        flag = false;
        break;
      }
    }
    if (flag) {
      result += word.length;
    }
  }
  return result;
};
```

如果我没记错的话，类似的题目出现过挺多次了，求字符串 `a` 和字符串 `b` 是否包含共有字母或者字符串 `a` 是否为字符串 `b` 的子集之类的。

这道题求的就是字符串 `a` 是否为字符串 `b` 的子集。

那么就有思路：

1. 先将 `chars` 打成数组，以及 `words` 中的每个元素打成数组。
2. 然后判断 `words` 中每个元素的每个字母，看它在 `words[i]` 中的长度和 `chars` 中的长度比对。如果 `chars.length` 满足不了它的要求，那么 `flag` 红牌直接给出即可。
3. 如果满足了要求，那么 `result` 加上这个长度，最终返回这个长度接口。

写上面思路的时候，突然想起如果红牌都给了，就没必要继续遍历字符串了。

所以有：

```js
if (length1 > length2) {
  flag = false;
  break;
}
```

小伙伴可能疑问这有没有作用，可以对比下：

> break 前

```js
Accepted
* 36/36 cases passed (3028 ms)
* Your runtime beats 5.38 % of javascript submissions
* Your memory usage beats 54.42 % of javascript submissions (44 MB)
```

> break 后

```js
Accepted
* 36/36 cases passed (204 ms)
* Your runtime beats 61.29 % of javascript submissions
* Your memory usage beats 67.35 % of javascript submissions (43.5 MB)
```

OK，这样，我们就完成了这道题的破解。

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library