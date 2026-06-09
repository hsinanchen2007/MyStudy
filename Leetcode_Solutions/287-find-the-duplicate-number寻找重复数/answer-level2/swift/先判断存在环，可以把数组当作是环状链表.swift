1. 第一个while循环试图让兔子(hare)追上乌龟(tortoise)，由于打破循环的条件是判断链表的next元素相等：
    1.若为同个链表节点，则还需进一步求证
    2.若链表的不同节点，则结果为相同元素
2. 不关以上属于哪种情况，让tortoise留在原处，兔子回到0节点，单步执行，总能在重复数字（即环的入口处）汇合。
```
func findDuplicate(_ nums: [Int]) -> Int {
        var tortoise = nums[0]
        var hare = nums[0]
        repeat {
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
        } while(tortoise != hare)
        
        hare = nums[0]
        while hare != tortoise {
            hare = nums[hare]
            tortoise = nums[tortoise]
        }
        return tortoise
    }
```
下图是绘制了一个测试用例为[2,5,9,6,9,3,8,9,7,1]的环链表图形。
![IMG_6060.JPG](https://pic.leetcode-cn.com/984403150c2d34b7d1b4f6ec7275b4eeb448347061db4e462d4f0bd969c1d375-IMG_6060.JPG)
