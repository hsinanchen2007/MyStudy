
这道题试了好几个方法，下面分享我的代码改进思路。

方法一：朴素方法，两重循环（532 ms）
```
func sum(a []int) int {
	length := len(a)
	sum := 0
	for i := 0; i < length; i++ {
		sum += a[i]
	}
	return sum
}

func fairCandySwap(A []int, B []int) []int {
    len1,len2 := len(A),len(B)
    sum1,sum2 := sum(A),sum(B)
    for i := 0; i < len1; i++ {
    	for j := 0; j < len2; j++ {	// 交换 i 和 j 的位置
    		if sum1-A[i]+B[j] == sum2-B[j]+A[i] {
    			return []int{A[i], B[j]}
    		}
    	}
    }
    return []int{A[0],B[0]}
}
```

两重循环方法实在太粗暴，我们用 hash 表改进一下！

方法二：hash 表记录，一重循环（100ms）

使用 hash 表记录出现过的 A[i] 的值，然后遍历一遍 B[i]，每次计算出需要的 A[i]。计算公式如下：
```
sum1+B[i]-A[x] == sum2-B[i]+A[x]
```
交换一下，得到：
```
sum1-sum2+2B[i] == 2A[x]
```
那么我们可以根据以上公式求出需要的 A[x]，再根据 hash 表查找需要的 A[x] 是否已存在即可。

代码：
```
func sum(a []int) int {
	length := len(a)
	sum := 0
	for i := 0; i < length; i++ {
		sum += a[i]
	}
	return sum
}

func fairCandySwap(A []int, B []int) []int {
    len1,len2 := len(A),len(B)
    sum1,sum2 := 0,sum(B)
    hash := map[int]bool{}
    for i := 0; i < len1; i++ {
        hash[A[i]*2] = true
        sum1 += A[i]
    }
    for i := 0; i < len2; i++ {
        if hash[sum1-sum2+2*B[i]] {  // 如果存在，说明找到交换的值
            return []int{(sum1-sum2+2*B[i])/2, B[i]}
        }
    }
    return []int{A[0],B[0]}
}
```

以上代码还有没有改进的空间呢？

我们看看消耗时间的操作，len() 是必须的，sum() 求和也是必须的，那么还有一个消耗时间的操作，就是 hash[x]。

Golang 中 hash 表的“查询操作”不是一个很快的操作，理论上不是 O(1) 复杂度。

所以我还试着开一个极大的数组，用下标代表值，类似这样：```hash := [99999999]bool{0}```，这样测试数据允许的话可以达到 O(1) 复杂度，可惜测试数组要么越界，要么超出内存限制，行不通。

那么可不可以将“查询操作”改进一下呢，于是我试着不用 hash 表，而是将 AB 数组排序，然后二分查找，发现提高也不大。

那么有没有办法将“查询操作”省掉呢？

我参考了 [LeonardZhang 的评论](https://leetcode-cn.com/problems/fair-candy-swap/comments/96865) ，这个方法用循环比较省却了“查找”过程，理论上会更快一些，代码见下：

```
func sum(a []int) int {
	length := len(a)
	sum := 0
	for i := 0; i < length; i++ {
		sum += a[i]
	}
	return sum
}


func fairCandySwap(A []int, B []int) []int {
    lenA,lenB := len(A),len(B)
    sumA,sumB := sum(A),sum(B)
    sort.Ints(A)
    sort.Ints(B)
    diff := sumA - (sumA+sumB)/2    // A 数组的和 和 平均值 的差
    i,j := 0,0
    for i<lenA && j<lenB {
        if A[i]-B[j] > diff {       // j++，以增大 B[j]
            j++
        } else if A[i]-B[j] < diff {// i++，以增大 A[i]
            i++
        } else {
            return []int{A[i],B[j]}
        }
    }
    return []int{A[0],B[0]}
}
```