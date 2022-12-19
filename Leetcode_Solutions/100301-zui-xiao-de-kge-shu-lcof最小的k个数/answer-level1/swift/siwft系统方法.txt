class Solution {
    func getLeastNumbers(_ arr: [Int], _ k: Int) -> [Int] {
        let sorted = arr.sorted()
            return Array.init(sorted.prefix(k))
    }
}