常规的拓扑排序，注意边界情况的处理。
```swift []
class Solution {
    func findOrder(_ numCourses: Int, _ prerequisites: [[Int]]) -> [Int] {
        var result:[Int] = []
        
        if numCourses < 0 {
            return result
        }
        
        //没有前序条件所有课程都可以按顺序完成
        if prerequisites.count == 0 || prerequisites[0].count == 0 {
            for i in 0 ... numCourses - 1{
                result.append(i)
            }
            return result
        }
        
        var adjs:Array<Set<Int>> = Array<Set<Int>>(repeating: Set<Int>(), count: numCourses)
        
        for item in prerequisites {
            adjs[item[1]].insert(item[0])
        }
        
        var reCycle:Array<Bool> = Array(repeating: false, count: numCourses)
        var visited:Array<Bool> = Array(repeating: false, count: numCourses)
        
        var stack:[Int] = []
        
        for i in 0 ... numCourses - 1 {
            if dfs(adjs, i, &stack, &reCycle, &visited) {
                return result
            }
        }
        
        for _ in 0 ... numCourses - 1 {
            result.append(stack.removeLast())
        }
        
        return result
    }
    
    func dfs(_ adjs:Array<Set<Int>>, _ index:Int, _ stack:inout Array<Int>, _ recycle:inout Array<Bool>, _ visited:inout Array<Bool>) -> Bool {
        if recycle[index]  {
            return true
        }
        
        if visited[index] {
            return false
        }
        
        recycle[index] = true
        visited[index] = true
        
        for i in adjs[index] {
            if dfs(adjs, i, &stack, &recycle, &visited) {
                return true
            }
        }
        
        stack.append(index)
        recycle[index] = false
        
        return false
    }
}
```
