### 解题思路
从第一个字符开始构造子串，如果直到末尾都没有出现相同字符，直接return长度。否则就记下长度tem，再从第二个字符开始，如果第二个到末尾都没有出现相同字符，判断该长度是否大于或等于长度tem，是的话直接return，否则继续...
执行用时 :40 ms, 在所有 Go 提交中击败了17.70%的用户
内存消耗 :2.6 MB, 在所有 Go 提交中击败了92.73%的用户
### 代码

```golang

func lengthOfLongestSubstring(s string) int {
    length:=1
    tem:=1
    if(len(s)==0){
        return 0
    }
    for i:=0;i<len(s);i++{
        for j:=i+1;j<len(s);j++{
           if(strings.Index(s[i:j], string(s[j]))>-1){
                tem=1
                break;
            }else{
               tem++ 
               if(j==len(s)-1){
                   //当前子串到达末尾时还没有重复字符，并且长度大于之前，return结束
                   //（之后的长度已经不可能超过该长度）
                   if(tem>=length){
                        return tem
                   }else{
                       tem=1;
                   }
                }
               if(length<tem){
                   length=tem
                }
            }
        }
    }
    return length
}
```