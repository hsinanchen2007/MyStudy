### 解题思路

洗牌算法的思路，是通过每次从下标范围为[0, index]位置中随机选取一个元素，与当前index下标位置的元素进行交换。

### 执行消耗
![image.png](https://pic.leetcode-cn.com/347a351e6abcf1a0906de9c0554af289001081300b4f86c587e05dd26022c4c2-image.png)


### 代码

```golang
type Solution struct {
    arr []int
}


func Constructor(nums []int) Solution {
    
    return Solution{nums}
}


/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
    return this.arr
}


/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
    n := len(this.arr)
    res := make([]int, n)
    copy(res, this.arr)
    for i := n-1; i >= 0; i-- {
        rand := rand.Intn(i+1)    // math.rand中的Intn(i+1)返回[0, i]范围的整数，每次数组在下标index为[0, i]范围内随机找一个下标对应的元素与当前位置i处的元素进行交换
        res[i], res[rand] = res[rand], res[i]   // 对应位置元素交换，也可以使用如下代码
        // tmp := res[i]
        // res[i] = res[rand]
        // res[rand] = tmp
    } 
    return res
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */
```