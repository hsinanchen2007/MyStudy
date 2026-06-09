![image.png](https://pic.leetcode-cn.com/5ddc9b5bfd4ff7ec2c70586588375bd6506f38ad5a914abae0f71e10b0c6b8e5-image.png)


方法一：朴素方法（192ms）

累加 [i,j] 的和，如果有 k 次查询，时间复杂度就是 O(kn)

```
type NumArray struct {
    data []int
}


func Constructor(nums []int) NumArray {
    a := NumArray{nums}
    return a
}


func (this *NumArray) SumRange(i int, j int) int {
    sum := 0
    for ;i<=j; i++ {
        sum += this.data[i]
    }
    return sum
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
```

方法二：求和数组相减（48ms）

提前计算出前 i 个数的和，即 a[i] 等于区间 [1,i] 的和，消耗时间为 O(n)

区间 [i,j] 的和求法为：sum(i,j) = a[j] - a[i-1]，每次查询消耗时间为 O(1)，k 次查询时间复杂度为 O(k)

总的来说，时间复杂度为 O(n+k)
```
type NumArray struct {
    presum []int    // 存储 [0,i] 的和
}


func Constructor(nums []int) NumArray {
    a := NumArray{}
    a.presum = append(a.presum, 0)  // 初始化 presum 数组
    for i:=1; i<=len(nums); i++ {
        t := a.presum[i-1] + nums[i-1]
        a.presum = append(a.presum, t)
    }
    return a
}


func (this *NumArray) SumRange(i int, j int) int {
    return this.presum[j+1] - this.presum[i]
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
```

方法三：树状数组（52ms）

树状数组专门用来求前 n 个数的和，区间和求法和上述一样：sum(i,j) = a[j] - a[i-1]

但是这道题仅查询，不用修改，没有发挥出树状数组的优势，查询上时间复杂度和方法二差不多。
```
type NumArray struct {
    a []int                                 // 树状数组
}

func lowbit(x int) int {                    // 取 x 的低位 1
    return x&(-x)
}

func (this *NumArray) getsum(i int) int {   // 利用树状数组求前 i 个数的和
    sum := 0
    for ; i>=1; i-=lowbit(i) {
        sum += this.a[i]
    }
    return sum
}

func (this *NumArray) update(i, x int) {     // 更新树状数组的第 i 个数为 x
    for ; i<len(this.a); i+=lowbit(i) {
        this.a[i] += x
    }
}


func Constructor(nums []int) NumArray {      // 生成树状数组
    t := NumArray{make([]int, len(nums)+1)}
    for i:=1; i<=len(nums); i++ {       
        t.update(i, nums[i-1])
    }
    return t
}


func (this *NumArray) SumRange(i int, j int) int {  // 求区间 [i,j] 的和
    return this.getsum(j+1) - this.getsum(i)
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
```
