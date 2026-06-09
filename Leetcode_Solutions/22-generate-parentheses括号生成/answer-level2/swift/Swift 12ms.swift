```swift
class Solution {
  
  func generateParenthesis(_ n: Int) -> [String] {
    var result: [String] = []
    generate(n, left: 0, right: 0, current: "", result: &result)
    return result
  }

  private func generate(_ n: Int, left: Int, right: Int, current: String, result: inout [String]) {
    if left == n && right == n {
      result.append(current)
      return
    }

    if left < n {
      generate(n, left: left + 1, right: right, current: current + "(", result: &result)
    }

    if left > right {
      generate(n, left: left, right: right + 1, current: current + ")", result: &result)
    }
  }

}
```
