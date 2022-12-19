方法三：一遍哈希表

    事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

    class Solution {
        func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
            var result = [Int]()
            var container = Set<Int>()
            for (index, value) in nums.enumerated() {
                let match = target - value
                if container.contains(match) {
                    let first  = nums.firstIndex(of: match)!
                    result.append(first)
                    result.append(index)
                    break
                }
                container.insert(value)
            }
            return result
        }
    }

    题解说明:
    1.创建Hash Container,解决时间复杂度问题.
    2.在Hash Container中查找match.
        2.1 查找成功，找到value和match的索引index.
    3.查找失败，将value1存入Hash Container.
    4.继续遍历数组.