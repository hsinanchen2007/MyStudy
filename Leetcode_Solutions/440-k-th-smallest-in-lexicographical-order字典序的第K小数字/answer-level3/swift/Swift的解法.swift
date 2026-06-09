### 解题思路
我也是参考了这个链接的思路：https://blog.csdn.net/FJJ543/article/details/81908992
和这个解法的注释：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/bian-li-chou-xiang-de-shi-cha-shu-qu-qian-xu-bian-/

### 代码

```swift
class Solution {
    func findKthNumber(_ n: Int, _ k: Int) -> Int {
        var current = 1
        var judge = k - 1 //judge是还剩余的个数
        while(judge > 0){
            var steps = 0, now = current, next = current + 1
            //尽可能地向下展开节点
            while(now <= n){
                //计算展开子树后的节点数量
                //此时now和next并未发生同层的移动，只是在向下展开
                steps = steps + min(n+1,next) - now
                //节点展开之后，相应的now和next也要对应地到下一层
                now = now * 10
                next = next * 10
            }
            if(steps <= judge){
                //展开的节点数小于等于剩余的个数时
                //我们需要向同一层的下一个节点移动，减去当前的所有子节点数，得到新的剩余个数
                current = current + 1
                judge = judge - steps
            }else{
                //展开的节点数大于剩余的个数时，向下层移动
                current = current * 10
                judge = judge - 1
            }
        }
        return current
    }
}
```