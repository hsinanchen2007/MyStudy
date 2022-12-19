 思路：此题与岛屿相关问题类似，都是组团、配对问题，适合用并查集

- 并查集是什么
    - 是一种树形的数据结构，用来处理一些不相交集合(Disjoint Sets)的合并与查询问题
    - 适用场景
        - 组团，配对问题
    - 联合-查找算法（union-find algorithm），是此数据结构的基本操作
        - Create: 初始化时，每个元素是一个集合，且自己是集合代表，我为自己代言
        - Find：确定元素属于哪个子集，找到它的集合代表
        - Union：将两个子集合并成一个集合
    - 代码模版
    ```javascript
    // 包含路径压缩优化: 处于同一路径上的节点都直接连接到根节点
    let makeSet = (x) => { parent[x] = x }
    let find = (x) => {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]]
            x = parent[x]
        }
        return x
    }
    let union = (x, y) => {
        let rootX = find(x), rootY = find(y)
        if (rootX === rootY) return
        parent[rootX] = rootY
    }
    ```

解题：
```javascript
/**
 *  - 因为矩阵是n*n的，所以是n个人之间的关系，创建一个长度为n的数组，表示初始化的n个独立的集合，自己是自己的集合代表(parent), 此时集合数量count = n
 *  - 遍历矩阵M，如果i,j两个人的关系 M[i][j] == 1，那就找到他们各自的集合代表，如果不一致，就合并为一个集合，因为他们是一个共同的朋友圈
 *  - 返回集合数量
 */
const findCircleNum = (M) => {
  if (!M.length) return 0
  let n = M.length, count = n
  let parent = new Array(n)
  for (let i = 0; i < n; i++) parent[i] = i
  
  const findParent = (p) => {
    while (parent[p] != p) {
      parent[p] = parent[parent[p]]
      p = parent[p]
    }
    return p
  }
  
  const union = (p, q) => {
    let rootP = findParent(p), rootQ = findParent(q)
    if (rootP === rootQ) return 
    parent[rootP] = rootQ
    count--
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (M[i][j] === 1) union(i, j)
    }
  }
  return count
}
```