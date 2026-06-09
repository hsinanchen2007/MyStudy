### 解题思路 1
只用了标准库，效率不怎么高..

(#`O′)那些拿swift当c++写得那么底层的，你们是怪物吗！

### 代码 1

```swift
class Solution {
    func numSmallerByFrequency(_ queries: [String], _ words: [String]) -> [Int] {
        
        //定义返回数组
        var ans = [Int]()
        
        //定义一个内嵌函数用以计算字符串中的最小字母的出现频率
        func Frequency(_ string:String) -> Int {
    
            guard let minCharacter = string.min() else {
                return 0
            }
            
            return string.filter{ $0 == minCharacter}.count

        }
        
        //统计queries中最小字母的出现频率，整理成一个数组
        let countOfQueries = queries.map{ Frequency($0) }
        //统计words中最小字母的出现频率，整理成一个数组
        let countOfWords = words.map{ Frequency($0)}

        //遍历countOfQueries，将符合要求的answer[i]插入到返回数组中
        for frequency in countOfQueries {
            ans.append(countOfWords.filter{ $0 > frequency }.count)
        }

        return ans
        
    }
}
```


### 解题思路 2 

自己造轮子的效率改进版


### 代码

```swift
class Solution {
    func numSmallerByFrequency(_ queries: [String], _ words: [String]) -> [Int] {

        //定义返回数组
        var ans = [Int]()

        //定义一个内嵌函数用以计算字符串中的最小字母的出现频率
        func Frequency(_ string:String) -> Int {

            var minCharacter:Character = "z"
            var count = 0
            
            for character in string {
                
                if character < minCharacter {
                    minCharacter = character
                    count = 1
                }
                else if character == minCharacter {
                    count += 1
                }
            }
            
            return count

        }

        //统计queries中最小字母的出现频率，整理成一个数组
        let countOfQueries = queries.map{ Frequency($0) }

        //统计words中最小字母的出现频率，整理成一个数组
        let countOfWords = words.map{ Frequency($0)}.sorted(by: > )

         //遍历countOfQueries，利用二分法将符合要求的answer[i]插入到返回数组中
        for number in countOfQueries {
            
            var head = 0
            var end = countOfWords.count - 1
            
            while head <= end {
                
                let mid = (head + end) / 2
                
                if countOfWords[mid] > number {
                    head = mid + 1

                } else {
                    end = mid - 1
                }

            }
            
            ans.append(head)
        }


        return ans

    }
}
```
