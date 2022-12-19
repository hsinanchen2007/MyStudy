```
class Solution {
    func distributeCandies(_ candies: Int, _ num_people: Int) -> [Int] {
        var candies = candies
        var n = 0
        var res = [Int].init(repeating: 0, count: num_people)
        while candies > 0 {
            let i = n % num_people
            res[i] += min(n + 1, candies)
            candies -= (n + 1)
            n += 1
        }
        return res
    }
}

```