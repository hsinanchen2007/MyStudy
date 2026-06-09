### 解题思路
这题用双端思路的话，主要是要创建两条队列，一个双端队列用来存放最大值的索引，一个最终队列用来添加每次遍历时的最大值。
*在遍历的时候，我们需要想象一下，脑海里面有一个k大小的框跟着一起滑动。当我们开始遍历的时候，此时index=0，这时我们暂时不要往最终队列中存放值，我们等到k大小的框完全覆盖数组的时候，我们再开始往最终队列中加数字。
* 我们在遍历数组的时候，我们没遍历一下就要去更新双端队列，双端队列怎么处理呢？我们将nums[index]的值跟双端队列的末尾那个nums[queue.last!]做比较，如果nums[index]大的话就把双端队列的末尾值删除掉，然后一直循环到末尾的值对应nums里面的值比nums[index]大，或者双端队列是空的了，这时的才能将nums[index]的值加到队列末尾去。
* 在这个时候，我们还要去判断一下双端队列的头对应的index值是不是已经超过了滑动窗口覆盖的面，也就是判断index- (k + 1)是不是大于maxCountIndex,如果大于的话，就要去删除掉双端队列的第一个值，maxCountIndex要在每次遍历的时候，都把双端队列的头值附给它，这样下次遍历的时候就能直接取到。
* 上面说的在k大小的框开始完全覆盖数组的时候，也就是index + 1 >= k的时候，我们在每次遍历的时候，就要更新finalQueue的值，就是每次在后面加上nums[maxCountIndex]，也就是双端队列的头结点对应的最大值。
* 这样在遍历完数组之后就得到了最大值的数组了。


### 代码

```swift
class Solution {
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        var queue = [Int]()
        var finalQueue = [Int]()
        var maxCountIndex = 0
        for index in 0..<nums.count {
            if index - k + 1 > maxCountIndex {
                queue.removeFirst()
            }
            while !queue.isEmpty && nums[queue.last!] < nums[index] {
                queue.removeLast()
            }
            queue.append(index)
            maxCountIndex = queue[0]
            if index + 1 >= k {
                finalQueue.append(nums[maxCountIndex])
            }
            
        }
        return finalQueue
    }
}
```