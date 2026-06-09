对比常规写法 其实不用每次都进行max判断 只有在出现了负数的时候才需要关心数值变化 其他时候可以做简单的数值叠加即可 Swift版本实现：

```Swift []
// 优化一部分
    func maxSubArray(_ nums: [Int]) -> Int {
        var maxV: Int = nums[0];
        var temp: Int = nums[0];
        
        var ls: Int = 0

        for index in 1..<nums.count {
            let num = nums[index]
            if temp > 0 {
                ls = temp + num
            }else {
                ls = num
            }

            if num <= 0 {
                maxV = max(temp, maxV)
            }
            temp = ls
        }

        maxV = max(temp, maxV)
        
        return maxV
    }
```

关于分治：
我的想法是通过非0的数字 当做间隔 将原本问题变为正负数交替的一串数字（多个负数等情况都需要处理）如
2 1 -3 7 -2 9 1 7 -6 3 将其转化为
3 -3 7 -2 17 -6 3
对于所有间隔数字 如果该数字的绝对值比左边和右边都要小 那么就将这个数组融合到其中
如上文中的3下标对应的-2 
而-3 和 -6 则不满足条件 
融合之后变为
3 -3 22 -6 3
思路如上

但是其实真写起来很费劲 而且速度和空间优势并没有 不知道是思路出问题了还是代码没写对