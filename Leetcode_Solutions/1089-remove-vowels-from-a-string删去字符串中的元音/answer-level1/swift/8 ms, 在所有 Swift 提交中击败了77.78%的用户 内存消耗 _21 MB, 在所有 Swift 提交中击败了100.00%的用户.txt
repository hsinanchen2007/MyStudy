class Solution {
    func removeVowels(_ S: String) -> String {
        let compare = "aeiou"
        var newStr = ""
        S.forEach { (char) in
            if !compare.contains(char){
                newStr.append(char)
            }
        }
        return newStr
    }
}