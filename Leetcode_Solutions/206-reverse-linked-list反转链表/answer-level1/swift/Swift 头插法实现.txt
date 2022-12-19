### 解题思路

![image.png](https://pic.leetcode-cn.com/f7a7ddde22f98dce3509cc3316706ae27d5d60be002c394cf673e402da0d820a-image.png)

![image.png](https://pic.leetcode-cn.com/df2c0329fe1b9845679c799bb17ea4ee2ed1a4cad7e9be63d3d180cf4d0f222e-image.png)

![image.png](https://pic.leetcode-cn.com/7ad1b3f806dfc107172b265952f6e965cec01c31b34877117c4f7daabf084439-image.png)

![image.png](https://pic.leetcode-cn.com/08276955289b78faef425392dbc12f3684b7ffb1286ff2ea6f3af548ecd8de3f-image.png)

![image.png](https://pic.leetcode-cn.com/f31c12dbc10d9b3e474dc658740f167d09ff9a2d63e85cfb4f4acacad13db39f-image.png)

以下即可用循环步骤实现，循环上述的2-5步即可。

![image.png](https://pic.leetcode-cn.com/6c8dcd5a7ab459d592a132471067c92262a32ab2b3406a381225cab73e4ab83b-image.png)

![image.png](https://pic.leetcode-cn.com/b40a1116989e8c18df5fdf853fea44b427610f774efe1486d2795cb0c5a1749a-image.png)

![image.png](https://pic.leetcode-cn.com/5467e95774a6e88432c8c9f8c99de5ceb2032d6dbea13eda80e0d48da94bc966-image.png)

![image.png](https://pic.leetcode-cn.com/00596e5a2b7fb64844cf85a4c79dca0f2d9e26129799e22399ea646705b8e432-image.png)


### 代码

```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        
        var newH:ListNode? = nil
        var head = head
        
        while head != nil {
            let tmp = head?.next 
            head?.next = newH
            newH = head
            head = tmp
       }
       return newH
    }
}
```