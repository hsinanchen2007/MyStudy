### 解题思路
扩展中心： 回文字符串，一定有个中心的，向两边扩散的元素都相同， 长度为n的字符串，可能有2n+1-2(去掉头尾)个中心点
执行用时 : 380 ms , 在所有 swift 提交中击败了 58.09% 的用户
内存消耗 : 20.8 MB , 在所有 swift 提交中击败了 7.41% 的用户

### 代码

```swift
func expandAroundCenter(_ strArr: [String.Element], l: Int, r: Int) -> (l:Int, r:Int ,len: Int) {
        //获取每个中心，对应的最长的回文串
        var left = l, right = r;
        while left>=0 && right<strArr.count && strArr[left] == strArr[right] {
            left -= 1
            right += 1
        }
        return (left+1, right-1, right - left - 1)
    }
    
    func longestPalindrome(_ s: String) -> String {
        if s.count == 0 {
            return ""
        }
        let strArr = Array(s)
        var start=0, end=0
        for i in 0..<s.count { // 遍历每一个可能的中心
            let len1 = expandAroundCenter(strArr, l: i, r: i)
            let len2 = expandAroundCenter(strArr, l: i, r: i+1)
            if max(len1.len, len2.len) > end - start + 1 {
                if len1.len > len2.len {
                    start = len1.l
                    end = len1.r
                }else{
                    start = len2.l
                    end = len2.r
                }
            }
            // 优化：剩下的回文长度，不可能超过当前最大的，则直接结束 // 优化后 执行用时 : 180 ms
            if curLen > (len - i) * 2{
                break
            }
        }
     
        return String(strArr[start...end])
    }
```