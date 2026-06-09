# 利用 Tire Tree 解决

- 编译成JavaScript再提交
- Tire设计
  - ITrieNode 节点接口
  - createTrieNode 创建节点
  - getFirstCharCodeAt 获取字符的Unicode编码
  - trieInsert 想 tire 树中插入节点
  - tireSearch 搜索节点
- 解决本题（设计 MapSum implements ITrieNodeAndValue）
  - ITrieNodeAndValue extends ITrieNode 本题需求节点
  - public value：用于保存单词值
  - insert 题目要求
  - sum 题目要求

## 设计前缀树

```ts
interface ITrieNode {
  isEnd: boolean
  next: ITrieNode[]
}

const createTrieNode = (): ITrieNode => {
  return {
    isEnd: false,
    next: new Array(26)
  }
}

const getFirstCharCodeAt = (c: string): number => {
  return c.charCodeAt(0) - 'a'.charCodeAt(0)
}

const trieInsert = (root: ITrieNode, word: string): ITrieNode => {
  let node: ITrieNode = root
  for (const c of word) {
    const node_index = getFirstCharCodeAt(c)
    if (node.next[node_index] === undefined)
      node.next[node_index] = createTrieNode()
    node = node.next[node_index]
  }
  node.isEnd = true
  return node
}

const trieStartsWith = (
  root: ITrieNode,
  prefix: string
): ITrieNode | null => {
  let node: ITrieNode = root
  for (const c of prefix) {
    node = node.next[getFirstCharCodeAt(c)]
    if (node === undefined) {
      return null
    }
  }
  return node
}

const tireSearch = (root: ITrieNode, word: string): ITrieNode | null => {
  let node: ITrieNode = root
  for (const c of word) {
    const next_index = getFirstCharCodeAt(c)
    node = node.next[next_index]
    if (node === undefined) return null
  }
  return node.isEnd ? node : null
}
```

## 解决本题

```typescript

interface ITrieNodeAndValue extends ITrieNode {
  value: number
  next: ITrieNodeAndValue[]
}

class MapSum implements ITrieNodeAndValue {
  value: number = 0
  isEnd: boolean = false
  next: ITrieNodeAndValue[] = new Array(0)

  insert(key: string, val: number) {
    ;(trieInsert(this, key) as ITrieNodeAndValue).value = val
  }

  sum(prefix: string): number {
    const prefixNode = trieStartsWith(this, prefix) as ITrieNodeAndValue | null
    if (!prefixNode) return 0
    let ans = 0
    // 层次遍历所有节点
    const queue: ITrieNodeAndValue[] = [prefixNode]
    while (queue.length !== 0) {
      const tmp = queue.shift() as ITrieNodeAndValue
      if (tmp.isEnd) ans += tmp.value
      tmp.next.forEach(item => item !== undefined && queue.push(item))
    }
    return ans
  }
}
```

## jest 测试

```typescript
import { MapSum } from '../677 map-sum-pairs'

describe('test 677 map-sum-pairs', () => {
  test('test MapSum', () => {
    const mapSum = new MapSum()
    mapSum.insert('apple', 3)
    expect(mapSum.sum('app')).toBe(3)
    mapSum.insert('app', 2)
    expect(mapSum.sum('app')).toBe(5)

    const mapSum2 = new MapSum()
    mapSum2.insert('apple', 3)
    expect(mapSum2.sum('apple')).toBe(3)
    mapSum2.insert('app', 2)
    expect(mapSum2.sum('app')).toBe(5)
  })
})

```