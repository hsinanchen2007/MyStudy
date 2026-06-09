class Solution {
    func compressString(_ S: String) -> String {
  
        /// 空字符串的判断
        if S == "" { return S }

        /// 获取第一个字符
        var lastElement: Character = S.first!

        /// 记录相同字符串的长度
        var count: Int = 1
        
        /// 记录转换后的字符串
        var result = ""
        
        let locationIndex = S.index(S.startIndex, offsetBy: 1)
        let range = locationIndex..<S.index(locationIndex, offsetBy: S.count - 1)
        let str = String(S[range])
 
        for item in str {
            if item == lastElement {
                count += 1
            } else {
                result += String(lastElement) + String(count)
                lastElement = item
                count = 1
            }
        }
        
        result += String(lastElement) + String(count)

        /// 转换后 和 转换前 的长度比较
        result = result.count >= S.count ? S : result
        
        return result
    }

}