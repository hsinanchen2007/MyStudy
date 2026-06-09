- 要找到最短距离为 k 的好友 可以通过广度优先 
- 广度优先遍历每一层好友 都放到 visited 中  因为已经遍历过的节点 不可能是最短距离为 k 的好友
- 遍历level次  最后得到最短距离为 level 的好友
- 然后统计video次数 排序即可 
```
var watchedVideosByFriends = function (watchedVideos, friends, id, level) {
  let next = [id]; // 下一次广度优先遍历的父节点
  let visited = new Set(); // 已经遍历过的节点 不可能是最短距离为 k 的好友
  let res = new Map(); 
  while (level--) {
    let temp = new Set();
    next.forEach(id => {
      visited.add(id);
    })
    next.forEach(id => {
      friends[id].forEach(el => {
        if (!visited.has(el)) {
          temp.add(el);
        }
      })
    })
    next = Array.from(temp);
  }
  next.forEach(id => watchedVideos[id].forEach(video => res.set(video, (res.get(video) || 0) + 1)))
  let arr = [];
  res.forEach((val, key) => {
    arr.push([val, key]);
  })
  return arr.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] > b[1] ? 1 : -1).map(el => el[1]);
};
```
