```
/**
 * 抢座位法
 * a，b，c，d，e => a抢了c，c抢了e，e抢了b，b抢d，d抢了a 绕了一圈。
 * 1. 转换 K => k%len(nums)
 * 2. 记录移动元素的次数
 * 3. 临时记录初始变量 oldData
 * 4. 记录当前位置 current
 * 5. 记录要移动的位置 moveTo
 * 6. 终止条件：所有元素都移动了一遍
 *
 * 注意：
 * 第一个循环的写法
 */

func rotate(nums []int, k int)  {
    l := len(nums)
    k = k % l 
    count := 0
    for i:=0;count<l;i++{
        var moveTo,tmp int
        current := i
        oldData := nums[i]
        for {
            moveTo = (current+k)%l
            tmp = nums[moveTo]
            nums[moveTo] = oldData
            oldData = tmp
            current = moveTo
            count++
            if moveTo == i {
                break
            }
        }
    }
}
```
