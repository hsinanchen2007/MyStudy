class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic:[Int:String] = [:]
        for (i,value1) in nums.enumerated() {
            let v = target - value1
            if let key = dic[v] {
                if let key1 = Int(key){
                    return [key1,i];
                }
            }
            dic[value1] = String(i)
        }
        return []
    }
    
}