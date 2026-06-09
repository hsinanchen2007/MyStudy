思路：
递归模拟整个操作过程，每一次的操作总是分为两种情况：
第一种情况，先copy,再paste
第二种情况，直接paste

总结：递归易于理解，但是性能不是很好！

```
func minSteps(n int) int {
    // 记录最终的最小值，初始设置为最大的整数
    min := int(^(uint(1)<<63))
    handle(1,0,-1,n,&min)
    return min
}

// op 操作次数
// cp 当前粘贴板A的数
// cur当前已经有的A的数
// n 目标值
// min 记录达到目标的最小的op次数
func handle(cur int, op int, cp int, n int, min *int) {
    
    // 已经完成，看操作次数是否小于当前的最小次数
    if cur == n {
        if op < *min {
            *min = op
        }
        return
    }
    // 当前数超过n，说明按照此法不能够凑成n个A
    if cur > n {
        return 
    }
    // 1、第一种情况，先copy,再paste
    handle(cur*2,op+2,cur,n,min)
    if cp != -1 {
        // 2、第二种情况，直接paste
         handle(cur+cp,op+1,cp,n,min)
    }
}
```
