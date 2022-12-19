首先我们根据数组的值和索引新建一个数据结构Node
```
type Node struct {
	val int
	idx int
}
```
然后对[]node进行排序，方便我们快速查找到下一跳
```
sort.Slice(n, func(i, j int) bool {
  if n[i].val == n[j].val {
    return n[i].idx < n[j].idx
  }
  return n[i].val < n[j].val
})
```
首先对于奇数跳很简单，就从当前的idx的往后找，找到第一个node.idx 大于当前idx的就可以直接进行下一跳了，我们通过odd和even两个map维护这些索引的最终状态。下次走到这一跳时可以直接返回结果。
```
for i := idx + 1; i < len(n); i++ {
    if n[i].idx < n[idx].idx {
        continue
    }
    odd[idx] = jump(i, flag+1, n, odd, even)
    return odd[idx]
}
```
偶数跳稍复杂。因为题目要求值可以相等，所以我们需要先往后找，是否有相等的值，如果有相等的值，直接用相等的值。如果没有，那么我们需要往前搜索，找到第一个node.idx 大于当前idx时，说明我们找到那个值，但是对应的索引并不是最优的，所以我们还需要再往前找，是否有相同的值索引更小。
```
  		for i := idx + 1; i < len(n); i++ {
			if n[i].val == n[idx].val {
				even[idx] = jump(i, flag+1, n, odd, even)
				return even[idx]
			}
		}
		for i := idx - 1; i >= 0; i-- {
			if n[i].idx < n[idx].idx {
				continue
			}
			for j := i - 1; j >= 0; j-- {
				if n[j].idx < n[idx].idx {
					continue
				}
				if n[j].val != n[i].val {
					break
				}
				i = j
			}
			even[idx] = jump(i, flag+1, n, odd, even)
			return even[idx]
		}
```

完整代码
```
type Node struct {
	val int
	idx int
}

func oddEvenJumps(A []int) int {
	n := make([]Node, len(A))
	for i := 0; i < len(A); i++ {
		n[i] = Node{A[i], i}
	}
	sort.Slice(n, func(i, j int) bool {
		if n[i].val == n[j].val {
			return n[i].idx < n[j].idx
		}
		return n[i].val < n[j].val
	})
	ret := 0
	odd, even := make(map[int]bool), make(map[int]bool)
	for i := 0; i < len(n); i++ {
		if success, ok := odd[i]; ok {
			if success {
				ret++
			}
			continue
		}
		if jump(i, 1, n, odd, even) {
			ret++
		}
	}
	return ret
}

func jump(idx, flag int, n []Node, odd, even map[int]bool) bool {
	if idx >= len(n) {
		return false
	}
	if n[idx].idx == len(n)-1 {
		return true
	}
	if flag%2 == 1 {
		if ret, ok := odd[idx]; ok {
			return ret
		}
		for i := idx + 1; i < len(n); i++ {
			if n[i].idx < n[idx].idx {
				continue
			}
			odd[idx] = jump(i, flag+1, n, odd, even)
			return odd[idx]
		}
		odd[idx] = false
		return odd[idx]
	} else {
		if ret, ok := even[idx]; ok {
			return ret
		}
		for i := idx + 1; i < len(n); i++ {
			if n[i].val == n[idx].val {
				even[idx] = jump(i, flag+1, n, odd, even)
				return even[idx]
			}
		}
		for i := idx - 1; i >= 0; i-- {
			if n[i].idx < n[idx].idx {
				continue
			}
			for j := i - 1; j >= 0; j-- {
				if n[j].idx < n[idx].idx {
					continue
				}
				if n[j].val != n[i].val {
					break
				}
				i = j
			}
			even[idx] = jump(i, flag+1, n, odd, even)
			return even[idx]
		}
		even[idx] = false
		return even[idx]
	}
	return false
}

```