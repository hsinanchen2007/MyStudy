这道题还是挺新奇的：

1. 有数组 `[[1, 2], [1, 3], [2, 3]]`。
2. 数组每个元素中，例如 `[1, 2]`，1 表示村民，2 表示它信任的人。
3. 如果被信任的人共同是一个人，那么这个人是法官：`[[1, 2], [1, 3], [2, 3]]`，法官是 3。
4. 如果被信任的人还信任另一个人，那么这个人不是法官：`[[1, 2], [1, 3], [2, 3], [3, 1]]`。

这样，我们就窃取了本题机密，开始暴力破解：

> 暴力破解

```js
const findJudge = (N, trust) => {
  // 1. 哈希表：记录村民（信任别人的人）
  const villagerMap = new Set();
  // 2. 哈希表：记录法官（被信任的人）
  const judgeMap = new Map();
  // 3. 遍历信任清单，进行哈希记忆
  for (let i = 0; i < trust.length; i++) {
    // 3.1 当前被信任的人
    const trusted = trust[i][1];
    // 3.2 当前被信任的次数
    const time = judgeMap.get(trusted);
    // 3.3 哈希表：记录每个村民
    villagerMap.add(trust[i][0]);
    // 3.4 哈希表：统计法官次数
    if (time) {
      judgeMap.set(trusted, time + 1);
    } else {
      judgeMap.set(trusted, 1);
    }
  }
  // 4. 开始汇报结果
  for (let [key, value] of judgeMap) {
    // 4.1 如果被信任次数为 N - 1
    // 4.2 如果它不在村民清单中
    if (value === N - 1 && !villagerMap.has(key)) {
      return key;
    }
  }
  // 5. 如果找不到，返回 -1
  // 6. 如果存在 findJudge(1, []) 情况
  return !trust.length ? N : -1;
};
```

如上，**jsliang** 给你安排地清清楚楚了~

Submit 提交如下：

```js
Accepted
* 89/89 cases passed (120 ms)
* Your runtime beats 62 % of javascript submissions
* Your memory usage beats 39.13 % of javascript submissions (43.8 MB)
```

如果小伙伴觉得自己思路更清晰，亦或者提交的结果更完美，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library