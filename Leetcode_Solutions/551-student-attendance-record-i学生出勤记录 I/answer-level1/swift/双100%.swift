class Solution {
    func checkRecord(_ s: String) -> Bool {
        var aCount = 0
        var pCount = 0
        for c in s {
            switch c {
            case "A":
                aCount += 1
                pCount = 0
            case "L":
                pCount += 1
            default:
                pCount = 0
            }
            if aCount > 1 || pCount > 2 {
                return false
            }
        }
        return true
    }
}