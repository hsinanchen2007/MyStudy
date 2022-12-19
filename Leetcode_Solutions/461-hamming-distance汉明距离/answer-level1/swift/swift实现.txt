```
class Solution {
    func hammingDistance(_ x: Int, _ y: Int) -> Int {
      var count = 0
      var result = x^y
      while result>0 {
          count += result&1
          result /= 2
      }
      return count
  }

}
```