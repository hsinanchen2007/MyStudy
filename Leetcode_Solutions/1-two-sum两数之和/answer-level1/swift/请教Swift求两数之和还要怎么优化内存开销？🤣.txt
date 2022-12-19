class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic = [Int: Int]()
        for (index, value) in nums.enumerated() {
            let newValue = target - value;
            if dic.keys.contains(newValue) {
                let newIndex = dic[newValue]!
                if( newIndex != index) {
                    dic.removeAll()
                    return [index, newIndex]
                }
            }
            dic[value] = index
        }
        return []
    }
}

显示：
执行用时 :48 ms, 在所有Swift提交中击败了98.34%的用户
内存消耗 :22.4 MB, 在所有Swift提交中击败了5.12%的用户