### 解题思路
 数学问题
 n个人, 数组长度为 n ,
 如果糖果充足,则第一轮发出的糖果为  N = (1+n)*n/2 
 每一轮的糖果量: N , N + n^2 , N + 2*n^2 ... .N + (k-1) * n^2
 总轮数需要的糖果总量 为 N*k + n^2*k(k-1)/2 = candies(整)
 解二次方程得正整数k, 再通过k算总量得到剩余糖果m, m是第k+1轮以此分发

 数组位置 0,1,2,3,4, n-1 的各个位置的糖果量为
 i位置每一轮: i+1 , i+1 +n, i+1 +2n,...,(i+1) + (k-1)n
 i位置总量:  => (i+1)*k + n*(0+k-1)*k/2
 还需要考虑到第一轮都没有发完的情况, 这时候k=0,直接跳过
### 代码

```swift
class Solution {
    func distributeCandies(_ candies: Int, _ num_people: Int) -> [Int] {
        var result = [Int](repeatElement(0, count: num_people))
        
        let N = (1+num_people)*(num_people)/2
        let k = { () -> Int in
            let a = 1.0
            let b = (2.0*Double(N)/Double(num_people*num_people) - 1.0)
            let c = -2.0*Double(candies)/Double(num_people*num_people)
            let k = (-b + pow(b*b-4*a*c,0.5))/(2*a)
            return Int(k)
        }()
        
        let indexRange = 0..<num_people
        
        if k>0 {
            for i in indexRange {
                result[i] = (i+1)*k + num_people*(k-1)*k/2
            }
        }
        
        
        var left = candies - (N*k + num_people*num_people*k*(k-1)/2)
        // let currentK = k + 1
        
        for i in indexRange {
            let neededCandies = (i+1)+k*num_people
            if left >= neededCandies {
                result[i] += neededCandies
                left -= neededCandies
            }else {
                result[i] += left
                break
            }
        }
        
        return result
    }
}
```