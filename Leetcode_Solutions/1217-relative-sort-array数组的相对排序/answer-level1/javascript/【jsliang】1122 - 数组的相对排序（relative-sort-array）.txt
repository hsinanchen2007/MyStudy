复读机 **jsliang**：

* 给定两个数组 `arr1` 和 `arr2`。
* `arr2` 中每个元素是唯一的。
* `arr2` 是 `arr1` 的子集。`arr2` 的所有元素在 `arr1` 中都有。
* 对 `arr1` 中的元素进行排序，使 `arr1` 中项的相对顺序和 `arr2` 中的相对顺序相同。未在 `arr2` 中出现过的元素需要按照升序放在 `arr1` 的末尾。

举例说明：

```
示例1：

输入：
arr1: [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19],
arr2: [2, 1, 4, 3, 9, 6]

输出：

[2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]
```

那么，开始破解：

> 暴力破解

```js
const relativeSortArray = (arr1, arr2) => {
  // 1. arr2 中出现的，按 arr2 顺序排序
  const appear = []; 
  for (let i = 0; i < arr2.length; i++) {
    appear.push(...arr1.filter(item => item === arr2[i]));
  }
  // 2. arr2 中未出现的，按升序排序
  const notAppearing = arr1.filter(item => !arr2.includes(item)).sort((a, b) => a - b);

  // 3. 通过 ... 组合两个数组
  return [...appear, ...notAppearing];
};
```

如上，通过简单的三步，我们就成功破解了这道题~

Submit 提交如下：

```js
Accepted
* 16/16 cases passed (68 ms)
* Your runtime beats 78.97 % of javascript submissions
* Your memory usage beats 58.12 % of javascript submissions (34.6 MB)
```

当然，剩下的就是看戏，磕着瓜子看看大佬秀操作：

> 【题解区】利用 sort

```js
const relativeSortArray = (arr1, arr2) => {
  return arr1.sort((a, b) => {
    let ia = arr2.indexOf(a);
    let ib = arr2.indexOf(b);
    if (ia == -1 && ib == -1) {
      return a - b;
    } else if (ia == -1) {
      return 1;
    } else if (ib == -1) {
      return -1;
    } else {
      return ia - ib;
    }
  });
};
```

Submit 提交：

```js
Accepted
* 16/16 cases passed (76 ms)
* Your runtime beats 41.38 % of javascript submissions
* Your memory usage beats 60.25 % of javascript submissions (34.6 MB)
```

其他的就不一一列举了，贴了也不一定会用~

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library