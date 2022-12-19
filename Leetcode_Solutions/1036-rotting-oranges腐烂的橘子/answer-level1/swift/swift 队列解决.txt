### 解题思路
 广度优先搜索
 使用队列完成
 因为要记录时间, 一个队列作为搜索, 再来个容器记录次数,队列空了再从容器拿

没有队列,还得自己实现一下
### 代码

```swift
class Solution {
    func orangesRotting(_ grid: [[Int]]) -> Int {
    
        var arr = grid
        
        var q = MyQueue<(Int,Int)>()
        var s = MyStack<(Int,Int)>()
        
        var time = 0
        var freshCount = 0
        
        for i in 0..<grid.endIndex {
            for j in 0..<grid[0].endIndex {
                if grid[i][j] == 2 {
                    s.push((i,j))
                }
                if grid[i][j] == 1 {
                    freshCount += 1
                }
            }
        }
        
        if freshCount == 0 {
            return 0
        }
        
        //
        let endI = grid.endIndex
        let endJ = grid[0].endIndex
        
        while !s.isEmpty {
            
            while let a = s.pop() {
                q.enqueue(a)
            }
            
            while let a = q.dequeue() {
                for p in nearPostions(of: a, endI: endI, endJ: endJ) {
                    if arr[p.0][p.1] == 1 {
                        arr[p.0][p.1] = 2
                        s.push(p)
                        freshCount -= 1
                    }
                }
            }
            
            time += 1
            
            if freshCount == 0 {
                return time
            }
        }
        
        //
        
        return freshCount == 0 ? time : -1
    }

    func nearPostions(of p:(Int,Int),endI:Int,endJ:Int) -> [(Int,Int)] {
    
        return [(p.0-1,p.1),(p.0+1,p.1),(p.0,p.1-1),(p.0,p.1+1)].filter{
            $0.0>=0 && $0.0<endI &&
            $0.1>=0 && $0.1<endJ
        }
    }

    struct MyStack<T> {
        
        private var arr:[T] = []
        
        var isEmpty: Bool {
            return arr.isEmpty
        }
        
        var count: Int {
            return arr.count
        }
        
        mutating func push(_ x: T) {
            arr.append(x)
        }
        
        mutating func pop() -> T? {
            return arr.popLast()
        }
        
    }

    struct MyQueue<T> {
        
        private var stackA = MyStack<T>()
        private var stackB = MyStack<T>()
        
        var isEmpty: Bool {
           return stackA.isEmpty && stackB.isEmpty
        }
        
        mutating func dequeue() -> T? {
            if stackB.isEmpty {
                while !stackA.isEmpty {
                    stackB.push(stackA.pop()!)
                }
            }
            
            return stackB.pop()
        }
        
        mutating func enqueue(_ x: T) {
            stackA.push(x)
        }
    }
}
```