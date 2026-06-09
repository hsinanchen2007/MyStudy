##  排序后暴力求解  

```swift
 class Solution {
    typealias State = [Int:Int]
    func canPartitionKSubsets(_ nums: [Int], _ k: Int) -> Bool {
        guard k != 1  else {
            return true
        }
        guard k != nums.count else {
            return Set<Int>(nums).count == 1
        }
        let sum = nums.reduce(0) {$0 + $1}
        guard sum % k == 0 else {
            return false
        }
        let targetSum = sum / k
        let sortedNums = nums.sorted().reversed()
        guard sortedNums.last! <= targetSum else {
            return false
        }
        let startState: State = [0:k]
        var states = [State]()
        states.append(startState)
        for num in sortedNums {
            var nextLevel = [State]()
            for state in states {
                for (sum,count) in state {
                    let nextSum = sum + num
                    if nextSum <= targetSum {
                        var temp = state
                        if count == 1 {
                            temp.removeValue(forKey: sum)
                        } else {
                            temp.updateValue(count - 1, forKey: sum)
                        }
                        temp.updateValue((temp[nextSum] ?? 0)  + 1, forKey: nextSum)
                        nextLevel.append(temp)
                    }
                }
            }
            states = nextLevel
        }
        for state in states {
            if state.count == 1 {
                for (sum,count) in state {
                    if sum ==  targetSum &&  count == k {
                        return true
                    }
                }
            }
        }
        return false
    }
 }
```
## 回溯

```swift
 class Solution {
    typealias State = [Int:Int]
    func canPartitionKSubsets(_ nums: [Int], _ k: Int) -> Bool {
        guard k != 1  else {
            return true
        }
        guard k != nums.count else {
            return Set<Int>(nums).count == 1
        }
        let sum = nums.reduce(0) {$0 + $1}
        guard sum % k == 0 else {
            return false
        }
        let targetSum = sum / k
        let sortedNums = nums.sorted { $0 > $1}
        guard sortedNums.last! <= targetSum else {
            return false
        }
        let startState: State = [0:k]
        let N = sortedNums.count
        var ans = false
        
        func backtracking(state: State, nextIndex currentIndex: Int) {
            guard !ans else {
                return
            }
            guard currentIndex < N  else {
                if state.count == 1, let c = state[targetSum],  c ==  k {
                    ans = true
                }
                return
            }
            for (sum,count) in state {
                let nextSum = sum + sortedNums[currentIndex ]
                if nextSum <= targetSum {
                    var temp = state
                    if count == 1 {
                        temp.removeValue(forKey: sum)
                    } else {
                        temp.updateValue(count - 1, forKey: sum)
                    }
                    temp.updateValue((temp[nextSum] ?? 0)  + 1, forKey: nextSum)
                    backtracking(state: temp, nextIndex: currentIndex + 1)
                }
            }
        }
        
        backtracking(state: startState, nextIndex: 0)
        
        return ans
    }
 }
```
