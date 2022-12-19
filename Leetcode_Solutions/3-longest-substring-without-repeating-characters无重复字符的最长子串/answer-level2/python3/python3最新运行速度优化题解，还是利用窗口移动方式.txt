速度和占用内存最优： 还是利用移动窗口 但是取消了字典或者set的定义，用python3 的切片来代替

```
def lengthOfLongestSubstring(self, s:str) -> int:
        length,j = 0,-1
        for i,x in enumerate(s):
            if x in s[j+1:i]:
                length = max(length,i-j-1)
                j = s[j+1:i].index(x)+j+1
        return max(length,len(s)-1-j)
```
[源码储存在github上，欢迎来提bug哦！-点击访问](https://github.com/Freen247/leetcode)
如果觉得不错请给我一个star谢谢了Stray_Camel(＾Ｕ＾)ノ~ＹＯ