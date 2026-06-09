## 通用解法
不能纠结于快乐数，而是着手于非快乐数，非快乐数必然会进入死循环，如果进入了死循环，那必然会出现重复的数！
那么通用的解法就是保存已计算的平方和，存入结果集中，每次计算平方和去结果集中取，如果有重复的结果集则就是非快乐数，如果结果为1就是快乐数。




    func isHappy(_ n: Int) -> Bool {
        var allSums = [n] // 先把n放入结果集中
        func sumNumber(number: Int) -> Bool {
            var num = number
            var sum = 0
            while num > 0 { // 计算平方和
                let val = num % 10
                sum += val * val
                num /= 10
            }
            if sum == 1 {
                return true
            } else if allSums.contains(sum) {
                return false
            }else {
                allSums.append(sum)
                return sumNumber(number: sum)
            }
        }
        return sumNumber(number: n)
    }

执行用时 :12 ms, 在所有 Swift 提交中击败了100.00%的用户

内存消耗 :20.8 MB, 在所有 Swift 提交中击败了6.67%的用户
### 另外的解法
比如10以内的数，只有1和7是快乐数，如果不是快乐数，最终的计算结果肯定会掉入10以内非1和7的数字当中，可以直接用递归实现。但是该解法依赖于先找到1-9的数字中的快乐数，成本较高，上方的实现更加通用，不用考虑额外的人工计算成本。