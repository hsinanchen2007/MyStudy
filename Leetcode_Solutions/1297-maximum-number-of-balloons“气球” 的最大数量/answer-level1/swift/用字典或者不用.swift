// ### 解题思路 1
// 用字典

// ### 代码

// ```swift
class Solution {
    func maxNumberOfBalloons(_ text: String) -> Int {
        
        //定义一个能分别记录单词内各个字母出现次数的字典
        var balloonCount : [Character:Int] = ["b":0,"a":0,"l":0,"o":0,"n":0]

        //遍历输入字符串，统计🎈单词中各个字符的出现次数（因为构成🎈的"b","a","n"都需要两个，所以上述三个字母的统计增量要比其它字母慢一倍
        for character in text {
            
            switch character {
            case "b":
                balloonCount["b"]! += 2
            case "a":
                balloonCount["a"]! += 2
            case "l":
                balloonCount["l"]! += 1
            case "o":
                balloonCount["o"]! += 1
            case "n":
                balloonCount["n"]! += 2
            default:
                break
            }
        }

        
        return (balloonCount.values.min()! / 2)
    }
}
// ```

// ### 题解思路2 
// 不用字典

// ### 代码

// ```
class Solution {
    func maxNumberOfBalloons(_ text: String) -> Int {
        
        //定义五个能分别记录单词内各个字母出现次数的变量
        var bCount = 0
        var aCount = 0
        var lCount = 0
        var oCount = 0
        var nCount = 0

        //遍历输入字符串，统计🎈单词中各个字符的出现次数（因为构成🎈的"b","a","n"都需要两个，所以上述三个字母的统计增量要比其它字母慢一倍
        for character in text {
            
            switch character {
            case "b":
                bCount += 2
            case "a":
                aCount += 2
            case "l":
                lCount += 1
            case "o":
                oCount += 1
            case "n":
                nCount += 2
            default:
                break
            }
        }
        
        return (min(bCount,aCount,lCount,oCount,nCount) / 2)
    }
}
// ```
