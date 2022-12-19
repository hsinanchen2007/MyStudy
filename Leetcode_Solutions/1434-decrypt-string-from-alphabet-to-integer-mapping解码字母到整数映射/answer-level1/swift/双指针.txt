### 解题思路
两个指针，一个指向字符串当前索引，一个指向2个身位后的索引

### 代码

```swift
class Solution {
    func freqAlphabets(_ s: String) -> String {
        
        //建立字典确定映射关系（当然你也可以利用Unicode的值）
        let code:[String:String] = [
            "1":"a","2":"b","3":"c","4":"d","5":"e","6":"f","7":"g","8":"h","9":"i","10#":"j",
            "11#":"k","12#":"l","13#":"m","14#":"n","15#":"o","16#":"p","17#":"q","18#":"r",
            "19#":"s","20#":"t","21#":"u","22#":"v","23#":"w","24#":"x","25#":"y","26#":"z"
        ]
        
        //定义返回字符串
        var ans = ""
        
        //定义探索字符串的步调
        var step = 0
        let length = s.count
        
        //建立遍历字符串的循环
        while step  < length {
            
            //定义一个临时空字符串用于记录需要从字典中求value的key
            var temp = ""
            
            //如果当前找到的字符的下下个索引对应的字符是“#”，则当前字符到“#”为止的整个字符串作为key保存，同时step+=2
            if (step + 2) < length && s[s.index(s.startIndex, offsetBy: step + 2)] == "#" {

                let startIndex = s.index(s.startIndex, offsetBy: step)
                let endIndex = s.index(s.startIndex, offsetBy: step + 2)
                
                let substring = s[startIndex...endIndex]
                temp.append(String(substring))
                step += 2

            } else {//否则就把当前找到的字符作为key保存
                
                let index = s.index(s.startIndex, offsetBy: step)
                temp.append(s[index])
            }

            //将找到的key在字典中求得的value依次加入到返回值中
            if let temp2 = code[temp] {
                
                ans.append(temp2)
            }

            //每经历一次查找，步调+1
            step += 1
            
        }

        return ans
    }
}
```