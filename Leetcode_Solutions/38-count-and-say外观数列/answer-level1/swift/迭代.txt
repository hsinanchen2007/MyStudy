### 解题思路

迭代

### 代码

```swift
class Solution {
    func countAndSay(_ n: Int) -> String {

        //初始化返回字符串
        var ans:String = "1"

        
        //外部循环，探访下一层序列直到第n层
        var n = n - 1
        while n > 0 {
            
            var temp = String()
            var countOfElement = 0              //上一层序列当前指向的元素个数
            var element = ans[ans.startIndex]   //上一层序列的当前指向元素
            
            //内部循环，对n-1层序列进行检算，生成第n层序列
            for index in ans.indices {
                
                //如果现在指向的元素和上一个指向的元素一致，则计数+1
                if ans[index] == element {
                    countOfElement += 1
                }
                else {//如果现在指向的元素是一个新元素，则返回上一个元素的值和它的个数到临时数组，同时reset计数器
                    temp.append(String(countOfElement) + String(element))
                    countOfElement = 1
                    element = ans[index]
                }
                
                //如果上一层序列已经探索完成，则把当前指向的元素和它的个数返回到临时数组
                if index == ans.index(before: ans.endIndex) {
                    temp.append(String(countOfElement) + String(element))
                }
            }
            
            n -= 1
            ans = temp  //将上一层的序列信息作为新一层的序列返回
        }

        return ans

    }
}
```