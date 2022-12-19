### 解题思路
建立树模型，进行广度优先搜索，对访问过的节点进行标记

### 代码

```swift
class Solution {

func numIslands(_ grid: [[Character]]) -> Int {
    
    guard !grid.isEmpty && !(grid.first?.isEmpty)! else { return 0 }
    
    class Node {
         
        let val: Character
        
        var isVisited = false
        
        var isLand: Bool {
            return val == "1"
        }
        
        init(val: Character) {
            self.val = val
        }
    }
    
    let maxY = grid.count - 1
    let maxX = grid.first!.count - 1
    
    let nodes = grid.map { $0.map { Node(val: $0) } }
    
    func visitNeighbors(x: Int, y: Int) {
        let node = nodes[y][x]
        guard node.isLand && !node.isVisited else { return }
        node.isVisited = true
        
        if y > 0 {
            visitNeighbors(x: x, y: y - 1)
        }
        
        if x > 0 {
            visitNeighbors(x: x - 1, y: y)
        }
        
        if y < maxY {
            visitNeighbors(x: x, y: y + 1)
        }
        
        if x < maxX {
            visitNeighbors(x: x + 1, y: y)
        }
    }
    
    return nodes.enumerated().reduce(0) { (result1: Int, element1) in
        return result1 + element1.element.enumerated().reduce(into: 0) { (result2: inout Int, element2: (offset: Int, element: Node)) in
            if element2.element.isLand && !element2.element.isVisited {
                visitNeighbors(x: element2.offset, y: element1.offset)
                result2 += 1
            }
        }
    }
}

}
```