# 滑动窗口真的香
关于代码的一些说明：
1.首先用left，right两个指针表示s字符串[left,right)内的字符，right表示还在探索，注意边界
2.用window和need作为哈希表，存储滑动窗口内和字符串T的字符及其数目
3.当window内字符不满足need需要时，right指针向右移动
4.当window内字符满足need需要时，left指针向右移动
5.步骤是 3 -> 4 -> 3 -> 4 ...这样子像毛毛虫一样前进，直到right到达s末尾
6.边界处理细节不能出错，ans赋初值正无穷
```
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def judge(need,window):
            for key in need:
                if window.get(key,0)<need[key]:
                    return False
            return True

        ans=float('inf')
        need={}
        window={}
        res_left=res_right=-1
        for char in t:
            need[char]=1+need.get(char,0)

        left=right=0
        #滑动窗口内是否满足了
        satisfy=False
        #由于是right不取，所以是符号是<=
        while right<=len(s): #维护区间[left,right)
            #首先判断window是否满足need
            #没满足就right右移
            if satisfy==False:
                if right<len(s) and s[right] in need.keys():
                    window[s[right]]=window.get(s[right],0)+1
                    satisfy=judge(need,window)
                right+=1
            #满足了就left右移
            else:
                #更新，并且记录
                if right-left<ans:
                    ans=right-left
                    res_left=left
                    res_right=right
                if s[left] in need.keys():
                    window[s[left]]=window.get(s[left],0)-1
                    satisfy=judge(need,window)
                left+=1
        
        return s[res_left:res_right]


```
