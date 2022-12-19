# 学习自 [Huahua酱LeetCode视频](https://www.bilibili.com/video/av38705526)

# 伪代码
## BFS

```go
q.push(start) // 初始节点放入队列
step = 0 // 初始化步长为0

while not q.empty(): // 当前节点不为空
    ++step // 扩展一层节点
    size = q.size() // 当前这一层节点的个数
    while size-- > 0: // 当前这一层节点数量大于0
        node = q.pop() // 不断出队
        new_nodes = expand(node) // 扩展下一层的节点
        if goal in new_nodes: return step + 1 // 找到结果step+1返回步长
        q.append(new_nodes) // 如果没有找到结果，把下一层的所有节点加入队列

return NOT_FOUND // 队列全部结束，没有找到结果
```

## Bidirectional BFS

```go
s1.insert(start) // 方便使用HashSet
s2.insert(end) // start和end放入两个set
step = 0 // 初始化步长为0

while not (s1.empty() || s2.empty()): // 当两个set都不为空，循环执行
    ++step // 步长+1
    swap*(s1, s2) // 交替从左端扩展和从右端扩展
    s = {} // 定义新的空集合
    for node in s1: // 当前需要扩展的这一层节点进行遍历
        new_nodes = expand(node) // 扩展下一层节点
        if any(new_nodes) in s2: return step + 1 // 新的节点在s2集合中，返回step+1，找到路径
        s.append(new_nodes) // 如果没有找到结果，把下一层的所有节点加入队列
    s1 = s // 临时的集合赋值给s1，即把已经走的路径存储起来

return NOT_FOUND // 队列全部结束，没有找到结果
```

# Go实现

## BFS

```go
// BFS Time Complexity: O(n*26^l), l = len(word), n=|wordList| Space Complexity: O(n)
func ladderLength(beginWord string, endWord string, wordList []string) int {
    dict := make(map[string]bool) // 把word存入字典
    for _, word := range wordList {
        dict[word] = true // 可以利用字典快速添加、删除和查找单词
    }
    if _, ok := dict[endWord]; !ok {
        return 0
    }
    // queue := []string{beginWord} 定义辅助队列
    var queue []string
    queue = append(queue, beginWord)

    l := len(beginWord)
    steps := 0

    for len(queue) > 0 {
        steps++
        size := len(queue)
        for i := size; i > 0; i-- { // 当前层级节点
            s := queue[0] // 原始单词
            queue = queue[1:]
            chs := []rune(s)
            for i := 0; i < l; i++ { // 对单词的每一位进行修改
                ch := chs[i]                  // 对当前单词的一位
                for c := 'a'; c <= 'z'; c++ { // 尝试从a-z
                    if c == ch { // 跳过本身比如hot修改为hot
                        continue
                    }
                    chs[i] = c
                    t := string(chs)
                    if t == endWord { // 找到结果
                        return steps + 1
                    }
                    if _, ok := dict[t]; !ok { // 不在dict中，跳过
                        continue
                    }
                    delete(dict, t)          // 从字典中删除该单词，因为已经访问过，若重复访问路径一定不是最短的
                    queue = append(queue, t) // 将新的单词添加到队列
                }
                chs[i] = ch // 单词的第i位复位，再进行下面的操作
            }
        }
    }
    return 0
}
```

## Bidirectional BFS

```go
// Bidirectional BFS Time Complexity: O(n*26^l/2), l = len(word), n=|wordList| Space Complexity: O(n)
func ladderLength(beginWord string, endWord string, wordList []string) int {
    dict := make(map[string]bool) // 把word存入字典
    for _, word := range wordList {
        dict[word] = true // 可以利用字典快速添加、删除和查找单词
    }
    if _, ok := dict[endWord]; !ok {
        return 0
    }
    q1 := make(map[string]bool)
    q2 := make(map[string]bool)
    q1[beginWord] = true // 头
    q2[endWord] = true   // 尾

    l := len(beginWord)
    steps := 0

    for len(q1) > 0 && len(q2) > 0 { // 当两个集合都不为空，执行
        steps++
        // Always expend the smaller queue first
        if len(q1) > len(q2) {
            q1, q2 = q2, q1
        }

        q := make(map[string]bool) // 临时set
        for k := range q1 {
            chs := []rune(k)
            for i := 0; i < l; i++ {
                ch := chs[i]
                for c := 'a'; c <= 'z'; c++ { // 对每一位从a-z尝试
                    chs[i] = c // 替换字母组成新的单词
                    t := string(chs)
                    if _, ok := q2[t]; ok { // 看新单词是否在s2集合中
                        return steps + 1
                    }
                    if _, ok := dict[t]; !ok { // 看新单词是否在dict中
                        continue // 不在字典就跳出循环
                    }
                    delete(dict, t) // 若在字典中则删除该新的单词，表示已访问过
                    q[t] = true     // 把该单词加入到临时队列中
                }
                chs[i] = ch // 新单词第i位复位，还原成原单词，继续往下操作
            }
        }
        q1 = q // q1修改为新扩展的q
    }
    return 0
}
```