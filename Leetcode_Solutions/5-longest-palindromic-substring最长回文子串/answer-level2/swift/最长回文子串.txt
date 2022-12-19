从第二个元素开始遍历，分三种情况查找，分别是：1、当前位置元素跟右边相邻的位置元素为中心，向两边扩开查找；2、当前位置元素跟左边相邻的位置元素为中心，向两边扩开查找；3、当前位置元素为中心，向两边扩开查找。查找的过程中，比较查找到的最大回文子串的长度和剩下元素中可能存在最大回文长度，决定是否需要继续查找，去掉不必要的重复.

```
class Solution {
    func longestPalindrome(_ s: String) -> String {
        let strA = Array(s)
        if s.count == 0 {return ""}
        let count = s.count
        var maxL = 0 ///最长回文长度
        var cache :[Int:(Int , Int)] = [:]///最长回文对应的长度为key，开始结束下标元组为value
        
        
        var i = 1
        
        while i < count {
            if maxL >= min(i*2, (count - i)*2) {///最长回文长度大于剩下可能最长回文，结束查找
                
                break
            }
            var left = 0
            var right = 0
            
                
            if i+1 < count && strA[i] == strA[i+1]{//当前位置元素跟右边相邻的位置元素为中心，向两边扩开查找
                left = i
                right = i+1
                while left >= 0 && right < count && strA[left] == strA[right]{
                    if maxL < right - left{
                        cache.removeValue(forKey: maxL)
                        maxL = right - left
                        cache[maxL] = (left , right)
                        
                    }
                    left -= 1
                    right += 1
                }
            }
            if i-1 >= 0 && strA[i-1] == strA[i]{//当前位置元素跟左边相邻的位置元素为中心，向两边扩开查找
                if maxL >= min(i*2, (count - i)*2) {///最长回文长度大于剩下可能最长回文，结束此轮查找
                     i += 1
                    continue
                }
                left = i-1
                right = i
                while left >= 0 && right < count && strA[left] == strA[right]{
                    if maxL < right - left{
                        cache.removeValue(forKey: maxL)
                        maxL = right - left
                        cache[maxL] = (left , right)
                        
                    }
                    left -= 1
                    right += 1
                }
            }
            if i+1 < count && i-1 >= 0 && strA[i-1] == strA[i+1] {//当前位置元素为中心，向两边扩开查找
                if maxL >= min(i*2, (count - i)*2) {///最长回文长度大于剩下可能最长回文，结束此轮查找
                     i += 1
                    continue
                }
                left = i-1
                right = i+1
                while left >= 0 && right < count && strA[left] == strA[right]{
                    if maxL < right - left{
                        cache.removeValue(forKey: maxL)
                        maxL = right - left
                        cache[maxL] = (left , right)
                        
                    }
                    left -= 1
                    right += 1
                }
            }
           
            i += 1
        }
        
        let left = cache[maxL]?.0
        let right = cache[maxL]?.1
        let leftI = s.index(s.startIndex, offsetBy: left ?? 0)
        let rightI = s.index(s.startIndex, offsetBy: right ?? 0)
        
        return String(s[leftI...rightI])
        
    }
}
```
