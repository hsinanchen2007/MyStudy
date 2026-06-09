### 解题思路
执行用时 : 104 ms, 在所有 golang 提交中击败了88.85%的用户
内存消耗 : 7.2 MB, 在所有 golang 提交中击败了100.00%的用户

1. 排序，使用的是库带的排序，相对来说比较快。因为这里明显不是在考排序
2. 顺序选数v， 然后对该数之后位置的切片使用双指针left， right（贪心）
3. 优化： 这里加了一个叫resultFlag的东西，在对result查重时不是从头到尾的，因为已经排序过了，所以只要从比v大或者等于的位置开始比较就行了（从执行来看优化了60%的速度）
这里的复杂度为O(nlog(n))

### 代码

```golang
func threeSum(nums []int) [][]int {
    if len(nums) < 3 {
        return [][]int{}
    }
    var result [][]int = make([][]int, 0, 10)
    
    ns := nums
    if !sort.IntsAreSorted(ns) {
		sort.Ints(ns)
	}
    flag := 0
    resultFlag := flag         // 因为是顺序结构，所以可以记录从何处开始查重
    for i, v := range ns {
        goal := 0 - v
        if i != 0 && ns[i-1] != v {
           // 如果与之间的不同辣么resultFlag就发生改变，，，，，，优化速度
           resultFlag = flag 
        }
        for left, right := i+1, len(ns)-1; left < right; {
            sum := ns[left] + ns[right]
            if sum > goal  {
                right--
            } else if sum < goal {
                left++
            } else {
                // 找到了， 但是要查重   这里的三元组都是从小到大的
                ca := []int{v, ns[left], ns[right]}
                if !isSame(result[resultFlag:], ca) {
                    result = append(result, ca)
                    flag = len(result)
                }
                right--
                left++
            }
        }
    }

    return result
}

// as中是否存在a   as和a都有基本的顺序结构
func isSame(as [][]int, a []int) bool {
    for _, vs := range as {
        if vs[0] == a[0] && vs[1] == a[1] && vs[2] == a[2] {
            return true
        }
    }
    return false
}




/**
    排序
    双指针从后往前
    查重

*/
```