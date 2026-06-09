### 思路

逐个比较两个相邻字符串的每个字符。假设相邻的两个字符串是 `s1` 和 `s2`，参与对比的两个字符分别为 `c1` 和 `c2`，这两个字符的对比无非就三种情况：

1. `c1 < c2`，是字典序：此时 `s1` 和 `s2` 符合字典序要求，我们无需再比对之后的字符串了
2. `c1 > c2`，非字典序：此时 `s1` 和 `s2` 不符合字典序的要求，该索引为必须要删除的索引。如果该索引还没有被删除（也有可能在其他比较的过程中删除了），我们就把这个要删除的索引记录下来，并且把要求的结果 `D.length + 1`，并且从头开始比对所有字符串
3. `c1 == c2`：这种情况比较特殊，看似是字典序，但这两个字符后其他字符的情况将决定 `s1` 和 `s2` 是否为字序。因此遇到两个字符相等的情况时，我们依然要继续比对字符串之后的其他字符

### 实现

```python []
class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        res = 0
        a_length = len(A)
        s_length = len(A[0])
        if a_length == 1:
            return 0
        
        # 记录已经删除的列
        mark = [0 for _ in range(s_length)]
        
        i = 1
        while i < a_length:
            pre_a = A[i - 1]
            cur_a = A[i]
            for j in range(s_length):
                # 如果是非字典序且该列还没有删除
                if pre_a[j] > cur_a[j] and mark[j] == 0:
                    mark[j] = 1
                    res += 1
                    # 重制 i 的位置，从第一个字符串开始重新比较
                    i = 0
                # 如果该列相等或该列已删除
                if pre_a[j] == cur_a[j] or mark[j] == 1:
                    continue
                break
            i += 1
                    
        return res
```
```swift []
class Solution {
    func minDeletionSize(_ A: [String]) -> Int {
        var res = 0
        var aLength = A.count
        var sLength = A[0].count
        if aLength == 1 {
            return 0
        }
        
        var mark = [Int](repeating: 0, count: sLength)
        
        var i = 1
        while i < aLength {
            var preA = Array(A[i - 1])
            var curA = Array(A[i])
            for j in 0...sLength-1 {
                if preA[j] > curA[j] && mark[j] == 0 {
                    res += 1
                    mark[j] = 1
                    i = 0
                }
                
                if preA[j] == curA[j] || mark[j] == 1 {
                    continue
                }
                
                break
            }
            i += 1
        }
        return res
    }
}
```