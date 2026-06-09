1. 创建一个Dictionary，查找key对应的value为o(1)
2. 创建一个优先队列。使用Array，根节点为Array的第一个元素
3. 取出Array中的第一个元素也就是最高频的元素，然后调整堆，继续取第一个元素直到取完k个元素
4.提交的时候 **[5,3,1,1,1,3,73,1] 1** 这个test case 报错 应输出为[1]，实际输出为[3]。我在自己的电脑上运行是[1],不知道为什么，没有使用全局变量。。。代码放下面了，发现问题的希望能帮我指正，多谢了
```swift []
class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        
        var countDic = [Int: Int]()
        for num in nums {
            countDic[num] = (countDic[num] ?? 0) + 1
        }
        var heap = [Int]()
        //build heap
        for num in countDic.keys {
            heap.append(num)
            var i = heap.count - 1
            //build heap
            while i > 0 {
                guard countDic[heap[i]]! > countDic[heap[(i-1)/2]]! else {
                    break
                }
                heap.swapAt(i, (i-1)/2)
                i = (i-1)%2
            }
        }
        print(heap)
        var results = [Int]()
        //ajust heap
        for _ in 0..<k {
            guard let first = heap.first, let last = heap.popLast() else {
                return results
            }
            //get the first item
            results.append(first)
            guard !heap.isEmpty else {
                return results
            }
            heap[0] = last
            //ajust heap
            var i = 0
            while i < heap.count {
                guard 2*i+1 < heap.count else {
                    break
                }
                guard 2*i+2 < heap.count else {
                    if countDic[heap[i]]! < countDic[heap[2*i+1]]! {
                        heap.swapAt(i, 2*i+1)
                    }
                    break
                }
                if countDic[heap[2*i+1]]! > countDic[heap[2*i+2]]! {
                    heap.swapAt(i, 2*i+1)
                    i = 2*i+1
                } else {
                    heap.swapAt(i, 2*i+2)
                    i = 2*i+2
                }
            }
        }
        
        return results
    }
}
```


