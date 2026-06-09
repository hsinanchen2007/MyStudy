1. 二进制只有 0 和 1 两种状态，可以用位运算来模拟元素的组合，比如第 i 个元素和第 u 个元素的组合，用位运算表示为 1 << i | 1 << u，假设 i = 3, u = 9，得到的二进制集合就是 1000001000
2. 动态规划算法的基本要素：最优子结构性质和重叠子问题。
    - 最优子结构性质：问题的最优解包含着它的子问题的最优解。即不管前面的策略如何，此后的决策必须是基于当前状态（由上一次的决策产生）的最优决策。
    - 重叠子问题：在用递归算法自顶向下解问题时，每次产生的子问题并不总是新问题，有些问题被反复计算多次。对每个子问题只解一次，然后将其解保存起来，以后再遇到同样的问题时就可以直接引用，不必重新求解。
``` swift
class Solution {
    func smallestSufficientTeam(_ req_skills: [String], _ people: [[String]]) -> [Int] {
        // 技能全集 (eg: count = 3 -> 二进制 111; count = 0 -> 二进制 0)，reqSkillBinary 为二进制集合的十进制表示
        let reqSkillBinary = 1 << req_skills.count - 1
        // 所有可能组合的数量，包含空集 0 (eg: count = 0 -> reqSkillCount = 1)
        let reqSkillCount = 1 << req_skills.count
        // 给 req_skills 里的技能编号，以便后面用于位运算
        var reqSkillDic = [String:Int]()
        for i in 0 ... req_skills.count - 1 { reqSkillDic[req_skills[i]] = i }
        // 声明一个固定长度数组，Int 为某个组合的人员数，默认值 -1，数组下标为某个技能的二进制组合的十进制，数组长度为所有可能组合的数量
        var peopleDP = [Int](repeating: -1, count: reqSkillCount)
        peopleDP[0] = 0 // 初始值，技能组合为空集时 (下标为 0)，人员数为 0
        // [Int] 为某个组合的人员在 people 中的下标，teamDP 作为 peopleDP 的人员存储器
        var teamDP = [[Int]](repeating: [], count: reqSkillCount)
        
        // peopleDP 存储着所有技能组合，一开始只有空集 0，通过下面的遍历产生新组合填满 peopleDP
        // 通过人数比较不断更新"已有的组合"，等遍历完了就能得到最优的组合之一
        for peopleIndex in 0 ... people.count - 1 {
            // 把某个人的技能通过 reqSkillDic 转换成二进制集合的十进制表示
            var peSkillBinary = 0
            for skill in people[peopleIndex] { peSkillBinary |= 1 << reqSkillDic[skill]! }
            // 把每个人的技能组合和"已有的组合"进行组合产生新组合
            for oldSkillBinary in 0 ... reqSkillBinary {
                // 此位置不是默认值 -1，即"已有的组合"，最开始"已有的组合"只有空集 0，后面会逐渐增多
                if peopleDP[oldSkillBinary] != -1 {
                    // 把某个人的技能组合和"已有的组合"进行组合产生新组合
                    let newSkillBinary = peSkillBinary | oldSkillBinary
                    // 此位置是默认值 -1 或"已有的组合"的人数比新组合人数多，则丢弃"已有的组合"，采用新组合
                    if peopleDP[newSkillBinary] == -1 || peopleDP[newSkillBinary] > peopleDP[oldSkillBinary] + 1 {
                        peopleDP[newSkillBinary] = peopleDP[oldSkillBinary] + 1
                        // 丢弃老的人员组合，采用新的人员组合
                        teamDP[newSkillBinary] = teamDP[oldSkillBinary]
                        teamDP[newSkillBinary].append(peopleIndex)
                    }
                }
            }
        }
        // 遍历完了，返回"技能全集"对应的"最少人员组合"
        return teamDP[reqSkillBinary]
    }
}
```
