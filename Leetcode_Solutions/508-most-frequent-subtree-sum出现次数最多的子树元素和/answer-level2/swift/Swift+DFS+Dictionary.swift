思路很简单，在做DFS的时候，将每个子树的元素和都用一个字典保存起来，key是元素和，value是出现次数。作为DFS之后，将字典里面value最大的值输出就行

```
class Solution {
    var sumDict = [Int: Int]()
    func findFrequentTreeSum(_ root: TreeNode?) -> [Int] {
        treeSum(root)
        var res = [Int]();
        var max = 0;
        for (key, value) in sumDict {
            if value > max {
                res.removeAll()
                max = value
                res.append(key)
            } else if value == max {
                res.append(key)
            } 
        }
        return res
    }
    
    func treeSum(_ root: TreeNode?) -> Int {
        guard let r = root else {
            return 0
        }
        var sum = r.val + treeSum(r.left) + treeSum(r.right)
        if let s = sumDict[sum] {
            sumDict[sum] = s + 1
        } else {
            sumDict[sum] = 1;
        }
        return sum
    }
}
```
