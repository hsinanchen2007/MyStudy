用数组做记录，已经计算过的直接返回，避免大量重复调用计算
```
class Solution {
    func tool(_ nums:inout [Int], n:Int) -> Int{
        if n == 0 {
            return 0
        }
        if n == 1 || n == 2 {
            return 1
        }
        if nums[n] != 0{
            return nums[n]
        }
        nums[n] = tool(&nums, n: n-1) + tool(&nums, n: n-2)
        return nums[n]
    }
    func fib(_ N: Int) -> Int {
        var nums = [Int](repeating: 0, count: N+1)
        return tool(&nums, n: N)
    }
}
```
动态规划，自底向上
```
func fib2(_ N: Int) -> Int {
    var arr = [Int](repeating: 0, count: N+1)
    arr[1] = 1
    arr[2] = 1
    for i in 3..<arr.count{
        arr[i] = arr[i-1]+arr[i-2]
    }
    return arr[N]
}
```