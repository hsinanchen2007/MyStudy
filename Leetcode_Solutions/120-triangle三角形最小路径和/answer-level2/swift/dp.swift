第n-1行有n个元素，创建长度为n的数组，存放到达该行每一个元素的最小路径。那么，创建长度为n+1的数组用来保存第n行的各个路径值，数组内第i个元素的值 = n-1行的i和i-1的最小值 + 三角形第n行的第i个元素
```
class Solution {
    func minimumTotal(_ triangle: [[Int]]) -> Int {
        let n = triangle.count
        if n == 0 {
            return 0
        }else if n == 1 {
            return triangle[0][0]
        }
        var dp = [triangle[0][0]]
        return dpMin(triangle, &dp)
    }
    func dpMin(_ triangle: [[Int]], _ dp: inout [Int]) -> Int {
        var tmp = Array(repeating: 0, count: dp.count + 1)
        var res = 0
        for i in 0...dp.count {
            if i==0 {
                tmp[i] = dp[i] + triangle[dp.count][i]
                res = tmp[i]
            }else if i == dp.count {
                tmp[i] = dp[i-1] + triangle[dp.count][i]
            }else{
                tmp[i] = min(dp[i], dp[i-1]) + triangle[dp.count][i]
            }
            res = min(res, tmp[i])
        }
        dp = tmp
        if triangle.count > dp.count {
            res = dpMin(triangle, &dp)
        }
        return res
    }
}
```