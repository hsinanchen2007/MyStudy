```
func largestNumber(_ nums: [Int]) -> String {
    
    var sorted = nums.map { (num) -> String in
        return String(num)
    }
    
    sorted = sorted.sorted { (s1, s2) -> Bool in
        return s1 + s2 > s2 + s1
    }
    
    if sorted.count > 0 {
        if (sorted[0] as NSString).isEqual(to: "0") {
            return "0"
        }
    }
    
    return (sorted as NSArray).componentsJoined(by: "")
}
```
