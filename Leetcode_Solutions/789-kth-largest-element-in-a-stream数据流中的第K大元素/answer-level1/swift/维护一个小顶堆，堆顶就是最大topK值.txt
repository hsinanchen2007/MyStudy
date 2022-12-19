### 解题思路
此处撰写解题思路

### 代码

```swift
class KthLargest {

    private var heap: [Int] = []
    private var k = 1

    init(_ k: Int, _ nums: [Int]) {
        self.k = k
        for num in nums {
            add(num)
        }
        //print("建堆完毕：\(heap)")
    }
    
    func add(_ val: Int) -> Int {
        if heap.count < k {
            heap.append(val)
            siftUp(&heap, index: heap.count - 1)
        }
        else if val > heap[0] {
            heap[0] = val
            siftDown(&heap, index: 0)
        }
        //print(heap)
        return heap.first!
    }
    
    // 上滤
    func siftUp(_ nums: inout [Int], index: Int) {
        var index = index
        let element = nums[index]
        while index >= 0 {
            let parentIndex = (index - 1) >> 1
            guard parentIndex >= 0 && parentIndex < nums.count else { break }
            if element < nums[parentIndex] {
                nums[index] = nums[parentIndex]
                index = parentIndex
            } else {
                break
            }
        }
        nums[index] = element
    }

    /// 下滤，适用小顶堆
    func siftDown(_ nums: inout [Int], index: Int) {
        guard index < nums.count else {
            return
        }
        var index = index
        // 备份待下滤元素
        let element = nums[index]
        let half = nums.count >> 1
        // index要指向非叶子节点，不断下移
        while index < half {
            // 取出左节点
            var childIndex = index << 1 + 1
            var childValue = nums[childIndex]
            // 如果右节点值比左小，指向右节点
            if childIndex + 1 < nums.count && nums[childIndex + 1] < childValue {
                childIndex += 1
                childValue = nums[childIndex]
            }
            guard element > childValue else {
                break
            }
            // 子节点移到父节点处
            nums[index] = childValue
            index = childIndex
            
        }
        nums[index] = element
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * let obj = KthLargest(k, nums)
 * let ret_1: Int = obj.add(val)
 */
```