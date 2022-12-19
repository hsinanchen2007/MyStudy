```
class Solution {
    func translateNum(_ num: Int) -> Int {
        if num < 10 {return 1}
        let remainder = num % 100
        if remainder <= 9 || remainder >= 26 {
            return translateNum(num / 10)
        } else {
            return translateNum(num / 10) + translateNum(num / 100)
        }
    }
}
```

//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass