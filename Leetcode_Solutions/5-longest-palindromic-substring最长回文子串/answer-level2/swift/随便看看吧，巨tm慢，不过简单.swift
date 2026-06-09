```swift []
func longestPalindrome(_ s:String) ->String {
    let unreverseString = s
    let reversedString = s.reversed()
    let unreverseArray = Array(unreverseString)
    let reversedArray = Array(reversedString)
    let nums = s.count
    if nums == 0 {
        return ""
    }
    var helpArray = [[Int]](repeating: [Int](repeating: 0, count: nums) , count: nums)      //定义一个nums行nums列的数组
    var maxLen = 0
    var maxEnd = 0
    for i in 0..<nums{
        for j in 0..<nums{
            if unreverseArray[i] == reversedArray[j]{
                if i == 0 || j == 0{
                    helpArray[i][j] = 1
                }else{
                    helpArray[i][j] = helpArray[i-1][j-1] + 1
                }
            }
            if(helpArray[i][j] > maxLen){
                let beforeRev = nums - 1 - j           //用于判断下标是否对应，如果不对应不是回文
                if beforeRev + helpArray[i][j] - 1 == i {
                    maxLen = helpArray[i][j]
                    maxEnd = i
                }
            }
        }
    }
    //swift 获取子字符串巨tm中二，需要使用String.Index来指定索引范围
    let startIndex = s.index(s.startIndex, offsetBy: maxEnd - maxLen + 1)
    let endIndex = s.index(s.startIndex, offsetBy: maxEnd + 1)
    let resultStr = String(s[startIndex..<endIndex])
    print(resultStr)
    return resultStr
}

longestPalindrome("abac")

```
