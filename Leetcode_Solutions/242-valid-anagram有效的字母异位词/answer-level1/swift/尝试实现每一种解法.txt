### 解题思路
首先异位词表示相同的字母按照不同的顺序组成，那么可以对字符串s和t重新排列成一个顺序相同的字符串来比较是否相同，如相同则互为异位词，反之则不是；如果传入字符串长度不同，则直接返回false。

### 代码

```swift
class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if s.count != t.count{
            return false;
        }
        let sArray = s.sorted();
        let tArray = t.sorted();

        if sArray == tArray {
            return true;
        }
        return false;
    }
}
```


####  解题思路
首先异位词表示相同的字母按照不同的顺序组成，根据题目说明，假设只包含小写字母，那么首先创建一个长度为26，初始化为0的数组table，然后遍历s字符串，字符对应的table数组下标的值+1，然后遍历t字符串，字符对应的table数组下标的值-1，最后遍历数组table，判断是否有不等于0的值，即可判断，字符串s和t 是否存在不同的字母以及次数。

### 代码

```swift
class Solution {
        
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if s.count != t.count{
            return false;
        }
        var table = Array(repeating: 0, count: 26);
        let sMap = s.map{$0};
        let tMap = t.map{$0};
        let charAIndex = Int("a".unicodeScalars.first!.value);
        for (index,chart) in sMap.enumerated(){
            let sChartIndex = Int(chart.unicodeScalars.first!.value);
            let tChartIndex = Int(tMap[index].unicodeScalars.first!.value);
            table[sChartIndex - charAIndex]+=1;
            table[tChartIndex - charAIndex]-=1;
        }
        for i in table {
            if i != 0 {
                return false;
            }
        }
        return true;
    }
}
```