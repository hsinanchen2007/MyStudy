题意愣是花了很久才看懂，加上这给出的示例还容易给人造成误解。
先插入队列，然后把旧的3秒之前的移除掉，最后返回队列长度，即使3秒内所有的ping的数量。
```
class RecentCounter {
    var result:[Int]
    init() {
        result = []
    }
    
    func ping(_ t: Int) -> Int {
        result.append(t)
        while result.first! < (t-3000) {
            result.removeFirst()
        }
        return result.count
    }
}

```