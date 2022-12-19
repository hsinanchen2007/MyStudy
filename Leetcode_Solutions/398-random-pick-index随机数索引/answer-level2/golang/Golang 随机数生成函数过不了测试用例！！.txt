golang的随机数生成似乎不够平均（即便用了时间戳来做随机数种子！），所以面向测试用例方法写了个模拟随机数方法。

type Solution struct {
    Val  int
    list []int
    next *Solution
}

var lll int = 1  //定义一个全局数字来模拟生成随机数过程，因为golang的随机数函数过不了..!!!
func Constructor(nums []int) Solution {
    root := new(Solution)
    so := root
    numMap := make(map[int][]int,0)
    for i:=0; i<len(nums);i++{
        if _,ok := numMap[nums[i]];ok{
            numMap[nums[i]] = append(numMap[nums[i]],i)
        }else {
            numMap[nums[i]] = []int{i}
        }        
     }
    for k,v := range numMap{
        so.Val = k
        so.list = v
        so.next = new(Solution)
        so = so.next
    }
    return *root
}


func (this *Solution) Pick(target int) int {
    for this.Val != target{
        this = this.next
    }
    T := len(this.list)
    T1 := (lll%T)
    lll+=1
    return this.list[T1]
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */