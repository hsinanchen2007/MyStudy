
这个题目有个特点,只包含英文小写字母,所以只会有26个小写字母,那么可以用长度为26的数组来存储每一个字母出现的次数

题目思路
1：charsArray[26] 用来存储给定的chars里面每一个字母出现的次数
2：遍历word里面每一个单词element，
     a:如果单词的长度比chars长度大,那么肯定是不能满足条件的
     b:遍历每一个element的字符,并且统计每一个出现的次数,如果出现的次数大于该字符的个数,那么就是不满足的


class Solution {
    


    func countCharacters(_ words: [String], _ chars: String) -> Int {
        var res: Int = 0
        var charsArray: [Int] = [Int] (repeating: 0, count: 26)
        let charsElements: Array<Character> = Array.init(chars)
        for c: Character in charsElements {
            let index: Int = Int(c.asciiValue!-Character("a").asciiValue!)
            charsArray[index] = charsArray[index]+1
        }
        for element in words {
            var isContain = true
            if (element.count > chars.count){
                continue
            }else{
                var elementArray: [Int] = [Int] (repeating: 0, count: 26)
                for c: Character in element {
                    let index: Int = Int(c.asciiValue!-Character("a").asciiValue!)
                    elementArray[index] = elementArray[index]+1
                    if (elementArray[index] > charsArray[index]){
                        isContain = false
                        break
                    }
                }
            }
            if (isContain){
                res = res + element.count
            }
        }
        return res;
    }
}