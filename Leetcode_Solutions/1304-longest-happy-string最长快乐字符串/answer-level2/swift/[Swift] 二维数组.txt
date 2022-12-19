![企业微信截图_f2047bd3-a862-4a0f-a026-4d5a3ec24806.png](https://pic.leetcode-cn.com/1c73f78923914997b966e39b838d949e78857ed2223f1791982f75a1756bb603-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_f2047bd3-a862-4a0f-a026-4d5a3ec24806.png)

------

## 基本思路

1. a、b、c 按照从大到小的顺序排序好
2. 利用二维数组添加元素
3. 最后转换为字符串

## 实际流程

假设我们有一个栗子： `a: 1, b: 8, c: 11`

### 第一步

首先确定大小关系，即 `c` 最大，`b` 其次，`a` 最小

### 第二步

针对最大的 `c`，我们将其分成两两一组的数组，添加到数组 `arrays` 中：

```swift
var arrays: [[String]] = []
var tmp: [String] = []
        
for _ in 0 ..< max.count {
            
    tmp.append(max.str)
            
    if tmp.count == 2 {
        arrays.append(tmp)
        tmp = []
    }
}

// 处理单数个的情况
if !tmp.isEmpty {
    arrays.append(tmp)
}
```

在这个例子中，当我们执行完这个 `for` 循环之后，`arrays` 将会是：

```swift
[
    ["c", "c"],
    ["c", "c"],
    ["c", "c"],
    ["c", "c"],
    ["c", "c"],
    ["c"]
]
```

### 第三步

分别对其余两个数据执行 `0 ..< count` 的循环，向 第二步生成的 `arrays` 的每组的末尾，追加对应的数据。

利用一个额外变量 `j` 来控制 `arrays` 的索引，每添加一次，`j` 增加 `1`

```swift
// 剩下的两组数据需要公用一个索引，即最小的那组数据要接着上一组的数据添加
var j = 0

func handle(tuple: (count: Int, str: String)) {
            
    for _ in 0 ..< tuple.count {
        arrays[j].append(tuple.str)
        j += 1
                
        if j >= arrays.count {
            j = 0
        }
    }
}

handle(tuple: other)
handle(tuple: another)
```

示例中，**第二大** 的数据是 `b: 8`，那么上面的代码第一遍 for 循环之后结果为：

```swift
[
    ["c", "c", "b"], // 每个
    ["c", "c", "b"], // 后面
    ["c", "c", "b"], // 都要
    ["c", "c", "b"], // 追加
    ["c", "c", "b"], // 一个
    ["c", "b"]       // "b"
]
```

此时 `b` 还有余量 `2`，`j` 将重置为 `0`，继续添加:

```swift
[
    ["c", "c", "b", "b"],
    ["c", "c", "b", "b"],
    ["c", "c", "b"],
    ["c", "c", "b"],
    ["c", "c", "b"],
    ["c", "b"]
]
```

最后，将在 `j` 为 `2` 的位置，添加最小的 `a: 1`：

```swift
[
    ["c", "c", "b", "b"],
    ["c", "c", "b", "b"],
    ["c", "c", "b", "a"], // <- 新添加的 "a"
    ["c", "c", "b"],
    ["c", "c", "b"],
    ["c", "b"]
]
```

这就是 `arrays` 最终的样子。

### 第四步

最后我们需要将 `arrays` 中的数据铺平为一个字符串。但是需要注意的是我们不能直接铺平，需要过滤。

假设我们最后的 `arrays` 长相如下所示：

```swift
[
    ["c", "c", "b"],
    ["c", "c"],
    ["c", "c"],
    ["c"]
]
```

铺平后将会是 `ccbccccc`。末尾的 5 个 `c` 明显不符合题意，所以我们需要过滤：

```swift
// 标记此后出现的长度小于等于2的元素都需要被舍弃掉
var isDiscard = false
        
return arrays.filter { 
            
    // 过滤掉长度小于等于 2 的元素
    if $0.count <= 2 && isDiscard == true { return false }
        
    // 标记出现过长度小于等于2个的元素    
    if $0.count <= 2 { isDiscard = true }
            
    return true
            
}.map { $0.joined() }.joined()
```


## Code

最后完成的代码如下：

```swift
func longestDiverseString(_ a: Int, _ b: Int, _ c: Int) -> String {
        
        if a >= b && a >= c {
            
            if b >= c {
                return helper(max: (a, "a"), other: (b, "b"), another: (c, "c"))
            } else {
                return helper(max: (a, "a"), other: (c, "c"), another: (b, "b"))
            }
        }
        
        if b >= a && b >= c {
            
            if a >= c {
                return helper(max: (b, "b"), other: (a, "a"), another: (c, "c"))
            } else {
                return helper(max: (b, "b"), other: (c, "c"), another: (a, "a"))
            }
        }
        
        if c >= a && c >= b {
            
            if a >= b {
                return helper(max: (c, "c"), other: (a, "a"), another: (b, "b"))
            } else {
                return helper(max: (c, "c"), other: (b, "b"), another: (a, "a"))
            }
        }
        
        return ""
    }
    
    func helper(
        max: (count: Int, str: String), 
        other: (count: Int, str: String),
        another: (count: Int, str: String)
    ) -> String {
        
        var arrays: [[String]] = []
        
        var tmp: [String] = []
        
        for _ in 0 ..< max.count {
            
            tmp.append(max.str)
            
            if tmp.count == 2 {
                arrays.append(tmp)
                tmp = []
            }
        }
        
        // 处理单数个的情况
        if !tmp.isEmpty {
            arrays.append(tmp)
        }
        
        // other 和 another 共用1个 j，所以放在 `handle(tuple:)` 之外
        var j = 0
        
        func handle(tuple: (count: Int, str: String)) {
            
            for _ in 0 ..< tuple.count {
                arrays[j].append(tuple.str)
                j += 1
                        
                if j >= arrays.count {
                    j = 0
                }
            }
        }
        
        handle(tuple: other)
        handle(tuple: another)
        
        // 标记此后出现的长度小于等于2的元素都需要被舍弃掉
        var isDiscard = false
        
        return arrays.filter { 
            
            // 过滤掉长度小于等于 2 的元素
            if $0.count <= 2 && isDiscard == true { return false }
            
            // 标记出现过长度小于等于2个的元素
            if $0.count <= 2 { isDiscard = true }
            
            return true
            
        }.map { $0.joined() }.joined()
    }
```
