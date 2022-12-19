```
class Solution {
    func numUniqueEmails(_ emails: [String]) -> Int {
        var result:Set<String> = Set<String>()
        var email = ""
        var suffix = ""
        var prefix = ""
        var comp:[String.SubSequence] = []
        emails.forEach {
            comp = $0.split(separator: "@")
            prefix = String(comp.first!)
            suffix = String(comp.last!)
            if let index = prefix.firstIndex(of: "+"){
                prefix = String(prefix.dropLast(prefix.count - index.utf16Offset(in: "Swift 5")))

            }
            prefix = prefix.filter { $0 != "." }
            email = prefix + "@" + suffix
            result.insert(email)
        }
        return result.count
    }
}
```