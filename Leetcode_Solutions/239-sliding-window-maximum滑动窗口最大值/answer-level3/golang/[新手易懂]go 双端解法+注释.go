
思路：
用示例 nums = [1,3,-1,-3,5,3,6,7] k= 3
用双端Queue实现，保持下标右移，window存下标，每增加一个下标，值比前面的值大就将前面的下标删除，确保最左值最大。

window = []  #存下标
过程：
下标|植|window
0 1 [0]
1 3 [1] #3>1 把下标0删掉
2 -1 [1,2] #3 > -1 把下标加进去  res [3]
3 -3 [1,2,3] #3 > -3 把下标加进去  res [3,3]
4 5 [4] # 首先窗口右移，先把 坐标1 去掉   然后5最大，把前面的下标都去掉   res [3,3,5]
5 3 [4,5] #5 > 4 把下标加进去  res [3,3,5,5]
6 6 [6] #6最大 res [3,3,5,5,6]
7 7 [7] #7最大 res [3,3,5,5,6,7]

### 1 滑动窗口 （用下标实现)
0 1 2 3 4 5 6 7
如上题k = 3
一开始 [0 1 2]  然后是[1 2 3] ，因为我们会将最大值前面的下标都去掉，所以有时向后增加并不一定要去掉最左的下标，比如这里的下标3，但是去到i=4时就必须将它移除，框下一个元素，所以这里是 <= i - k
```
if i >= k && window[0] <= i - k{
    window = window[1:]
}
```

### 2 然后用循环 对比 window 里的**最后一个元素**，比x小的都将其移除，永远确保最左的是最大值的下标 （所以双端，移动删除第一个元素，对比最后一个元素决定是否要删除）

### 3最后再添加 i 到window 中

### 4从第k - 1开始，只要i >= k - 1   可以将最左元素添加到结果

下面代码
```
func maxSlidingWindow(nums []int, k int) []int {
    if nums == nil{
        return []int{}
    }
    
    window, res := []int{},[]int{}
    for i,x := range(nums){
        
        if i >= k && window[0] <= i - k{
            window = window[1:]
        }
        for len(window) > 0 && nums[window[len(window) - 1]] <= x{
            window = window[:len(window) - 1]
        }
        window = append(window,i)
        fmt.Println(i,x,window)
        if i >= k - 1{
            res = append(res,nums[window[0]])
        }
    }
    return res
}
```
