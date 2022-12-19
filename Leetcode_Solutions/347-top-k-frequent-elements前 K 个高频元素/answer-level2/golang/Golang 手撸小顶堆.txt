![image.png](https://pic.leetcode-cn.com/82bd1ab31169ca4553f6ee954513d93bbafc8cad250a753486afe952d5237a87-image.png)

首先 复习一下堆的概念
1. 堆是一颗完全二叉树
2. 大顶堆的父节点大于两个子节点，小顶堆的父节点小于两个子节点

求前K高频元素，维护一个有K个元素的小顶堆即可
求解步骤：
1. 统计每个元素出现的频率
2. 初始化小顶堆，取前10个元素，放入堆中
3. 更新堆，因为是小顶堆，所以堆顶元素一定是最小的，当有一个新的元素出现，和堆顶元素比较，如果大于堆顶元素，则替换堆顶元素，替换后的堆顶元素不一定是堆中最小的，这不满足小顶堆的条件，向下进行堆化。
4. 最终这个有K个元素的小顶堆中的元素就是前K高频的元素


```
type heapNode struct {
    value int
    count int
}

var sHeap []heapNode

func topKFrequent(nums []int, k int) []int {
	// 申请一个小顶堆
	sHeap = make([]heapNode, k + 1, k + 1)
	counter := counting(nums)

	sum := 0
	for value, count := range counter {
		node := heapNode{value, count}
		if sum < k {
			buildHead(sum + 1, node)
			sum++
		} else if sHeap[1].count < count {
			sHeap[1] = node
			heapify(k)
		}
	}

	res := make([]int, k, k)
	for i := 1; i <= k; i++ {
		res[i - 1] = sHeap[i].value
	}
	return res
}

// 统计每个元素的出现频率
func counting(nums []int) map[int]int {
	counter := make(map[int]int, 0)
	for i := 0; i < len(nums); i++ {
		counter[nums[i]]++
	}
	return counter
}

// 生成大小为k的小顶堆
func buildHead(index int, node heapNode) {
	sHeap[index] = node
	pIndex := index / 2
	for pIndex > 0 {
		if sHeap[pIndex].count > sHeap[index].count {
			sHeap[pIndex], sHeap[index] = sHeap[index], sHeap[pIndex]
		} else {
			return
		}
		index = pIndex
		pIndex = index / 2
	}
}

// 更换堆顶元素，进行堆化处理
func heapify(k int) {
	index := 1
	for {
		minPos := index
		if k < index * 2 {
			return
		} else if k < index * 2 + 1 {
			minPos = index * 2
		} else if sHeap[index * 2].count > sHeap[index * 2 + 1].count {
			minPos = index * 2 + 1
		} else {
			minPos = index * 2
		}

		if sHeap[index].count > sHeap[minPos].count {
			sHeap[index], sHeap[minPos] = sHeap[minPos], sHeap[index]
		} else {
			return
		}
		index = minPos
	}
}
```


