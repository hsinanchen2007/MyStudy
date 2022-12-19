这个题目主要的思路是统计每个字符串的个数,
1：如果是偶数,那么能够构成回文. 
2:如果是基数,所有字符串为基数的个数减1求和，最后在加1.

使用的数组存储的，因为只包含大小写共52个字母，所以可以用52个元素的数组统计每一个元素出现的次数，最后求和
使用数组的思路有点类似于下面这个题
[https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/]()


    class Solution {
        func longestPalindrome(_ s: String) -> Int {
            var charList: [Int] = [Int](repeating: 0, count: 26*2)
            var res: Int = 0
            for character in Array(s) {
                var index = 0
                if (Int(character.asciiValue!) <= 90){
                    index = Int(character.asciiValue! - Character("A").asciiValue!)
                }else{
                    index = Int(character.asciiValue! - Character("a").asciiValue!) + 26
                }
                charList[index] = charList[index] + 1
            }
            
            var isTrue: Bool = false
            for val in charList {
                if (val%2 == 0){
                    res = res + val
                }else{
                    //基数只算一次
                    isTrue = true
                    res = (val-1) + res
                }
            }
            res = isTrue ? res+1:res
            return res
        }
    }