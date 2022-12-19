有时候 LeetCode 题目的描述令人诟病，你是知道的：

* 没有花园有 3 条以上的路径可以进入或者离开。
* 不存在花园有 4 条或者更多路径可以进入或离开。

那就是不存在 [4, n) 路径了。

> 虽然这话并没有什么软用……

……

> FBI warning：这道题是中等难度，LeetCode 放到简单难度就是想折腾你

……

经过近 3 小时的折腾，终于搞出套路：

> 暴力破解【未简化】

```js
const gardenNoAdj = (N, paths) => {
  // 1. 构造通道
  const gardenMap = Array.from(Array(N), (value, index) => {
    return {
      garden: index + 1,
      path: [],
    };
  });
  
  // 2. 填充数据
  for (let i = 0; i < paths.length; i++) {
    gardenMap[paths[i][0] - 1].path.push(paths[i][1]);
    gardenMap[paths[i][1] - 1].path.push(paths[i][0]);
  }
  
  // 3. 开始挖坑，拿好花种
  const result = Array.from(Array(N + 1), () => '');
  const flowers = [1, 2, 3, 4];

  // 4. 开始填坑
  for (let i = 0; i < gardenMap.length; i++) {
    const values = [];
    for (let j = 0; j < gardenMap[i].path.length; j++) {
      const k = gardenMap[i].path[j];
      values.push(result[k]);
    }
    const canUse = Array.from(new Set([...flowers].filter(x => !values.includes(x))));
    result[i + 1] = canUse[0];
  }

  // 5. 去掉没用的坑
  result.shift();
  return result;
};
```

拿 `[[1, 2], [1, 4], [2, 4], [3, 4], [2, 6], [6, 1]]` 分析：

**首先**，步骤 1 + 步骤 2，生成数据：

```js
[
  { garden: 1, path: [ 2, 4, 6 ] },
  { garden: 2, path: [ 1, 4, 6 ] },
  { garden: 3, path: [ 4 ] },
  { garden: 4, path: [ 1, 2, 3 ] },
  { garden: 5, path: [] },
  { garden: 6, path: [ 2, 1 ] },
]
```

这时候我们知道，哪个花园可以通向哪个花园。

**然后**，我们开始挖坑和设置花种：

```js
['', '', '', '', '', '', '']
[1, 2, 3, 4]
```

需要注意的是，为了保持索引的一致性，这里我们加了个表示 0 的坑，最后会通过 `result.shift()` 清空掉。

**接着**，开始填坑：

```
1 => ['', 1, '', '', '', '', '']
2 => ['', 1,  2, '', '', '', '']
3 => ['', 1,  2,  1, '', '', '']
4 => ['', 1,  2,  1,  3, '', '']
5 => ['', 1,  2,  1,  3,  1, '']
6 => ['', 1,  2,  1,  3,  1,  1]
```

可以看到，我们通过 `values` 获取了当前花园通向其他花园的值，然后我们通过 `canUse` 取 `values` 和 `flowers` 的差集，表明我们剩余可用的花种有多少。

这时候，知道剩余可用花种，我们用第一种就行了。

**最后**，通过 `result.shift()` 把第一个坑去掉，就是我们的结果。

Submit 提交：

```js
Accepted
* 51/51 cases passed (324 ms)
* Your runtime beats 7.14 % of javascript submissions
* Your memory usage beats 13.33 % of javascript submissions (76.1 MB)
```

当然，为了代码的条理性，我们编写了一些无用代码，**jsliang** 整理下：

> 暴力破解【简化】

```js
const gardenNoAdj = (N, paths) => {
  // 1. 构造通道，索引 0 对应花园 1
  const gardenPath = Array.from(Array(N), () => []);
  
  // 2. 填充数据
  for (let i = 0; i < paths.length; i++) {
    gardenPath[paths[i][0] - 1].push(paths[i][1]);
    gardenPath[paths[i][1] - 1].push(paths[i][0]);
  }
  
  // 3. 开始挖坑，拿好花种
  const result = Array.from(Array(N), () => '');
  const flowers = [1, 2, 3, 4];

  // 4. 开始填坑
  for (let i = 0; i < gardenPath.length; i++) {
    const path = gardenPath[i].map(item => result[item - 1]);
    const canUse = Array.from(new Set([...flowers].filter(item => !path.includes(item))));
    result[i] = canUse[0];
  }

  // 5. 去掉没用的坑
  return result;
};
```

Submit 提交：

```js
Accepted
* 51/51 cases passed (240 ms)
* Your runtime beats 16.67 % of javascript submissions
* Your memory usage beats 16.67 % of javascript submissions (73.5 MB)
```

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library
