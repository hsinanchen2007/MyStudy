开心消消乐又来咯：

1. 有一串字符 `abbaca`，如果它当中有两个连在一起的，就消掉，直到不能再消为止。
2. 消除的过程： `abbaca` => `aaca` => `ca`。

好，直到规则，开始搞事：

> 暴力破解

```js
const removeDuplicates = (S) => {
  let newS = '';
  let flag = false;
  while (!flag) {
    let remove = false;
    for (let i = 0; i < S.length; i++) {
      if (S[i] === S[i + 1]) {
        i++;
        remove = true;
      } else {
        newS += S[i];
      }
    }
    S = newS;
    if (!remove) {
      flag = true;
    } else {
      remove = false;
      newS = '';
    }
  }
  return newS;
};
```

解析：

1. 设置 `newS` 来获取当前消除后的字符串。
2. 设置 `flag` 来判断是否中止开心消消乐。
3. 通过 `for` 遍历 S，判断是否存在 `S[i] === S[i + 1]`，如果存在，则跳两格，不添加这两个相同的，同时表明 `remove = true`，表明我消除过。
4. 循环结束后，将 `S` 替换为 `newS` 的内容，以示接下来如果还需要消除的话，就进一步消除。
5. 同时，判断这次是否进行了 `remove`，如果没进行，那就是最终结果；如果消除了，那么清空 `newS` 和重置 `remove`，卷土重来~

Submit 提交：

```js
Accepted
* 98/98 cases passed (100 ms)
* Your runtime beats 41.82 % of javascript submissions
* Your memory usage beats 65.64 % of javascript submissions (42 MB)
```

那么，是否存在一次遍历，就可以全部消除的方法？

> 线性遍历

```js
const removeDuplicates = (S) => {
  const stack = [];
  for (let i = 0; i < S.length; i++) {
    if (stack[stack.length - 1] === S[i]) {
      stack.pop();
    } else {
      stack.push(S[i]);
    }
  }
  return stack.join('');
};
```

这道题和判断有效的括号很想象，直接判断栈顶的内容即可~

Submit 提交：

```js
Accepted
* 98/98 cases passed (88 ms)
* Your runtime beats 73.64 % of javascript submissions
* Your memory usage beats 23.79 % of javascript submissions (42.5 MB)
```

当然，除此之外，还有一种方法，就是官方题解中的，使用正则替换出现的 `['aa', 'bb', 'cc', ..., 'zz']` 重复项，然后循环替换即可（跟 **jsliang** 暴力相似）：

* https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/solution/shan-chu-zi-fu-chuan-zhong-de-suo-you-xiang-lin-zh/

这里咱就不多逼逼了，感兴趣的小伙伴可以去看看。

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library