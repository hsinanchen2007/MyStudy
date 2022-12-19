```swift
class Solution {
    func subdomainVisits(_ cpdomains: [String]) -> [String] {
        var set: [String: Int] = [:]
        for cpdomain in cpdomains {
            let cpdomainArray = cpdomain.split(separator: " ")
            let cpdomainCount = Int(cpdomainArray[0])!
            let cpdomainParts = cpdomainArray[1].split(separator: ".")
            let cpdomainPartsCount = cpdomainParts.count
            for index in 0..<cpdomainPartsCount {
                let cpdomainStr = cpdomainParts[index..<cpdomainPartsCount].joined(separator: ".")
                if set.keys.contains(cpdomainStr) {
                    set[cpdomainStr]! += cpdomainCount
                } else {
                    set.updateValue(cpdomainCount, forKey: cpdomainStr)
                }
            }
        }
        return set.map({ "\($0.value) \($0.key)" })
    }
}
```