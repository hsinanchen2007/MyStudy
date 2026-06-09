第一个数组保存字符，第二个数组保存相应字符出现的次数

遍历字符串，若字符s[i]与字符数组最后一个字符相同，则第一个数组保持不变，第二个数组相应位置次数+1（若次数为k，则两数组都pop()）
若字符s[i]和字符数组最后一个字符不相同，则将该字符添加到字符数组中，且第二个数组相应位置置位1，继续遍历
遍历完字符串后，结果只需在遍历一遍两数组，将字符拼接起来即可

例：s = "abbecc", k = 2
遍历完后
第一个数组：['a','e']
第二个数组：[1,1]
输出："ae"

```python []
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        
        stack=[]#第一个数组，保存字符
        cout=[]#第二个数组，保存字符出现的次数
        right=-1#索引，指向上面两个数组的最后一个位置
        index=0#字符串s的索引
        l=len(s)
        
        while index<l:
            if right<0:#若两数组为空
                stack.append(s[index])
                cout.append(1)
                right=0
            else:
                if stack[right]==s[index] and cout[right]==k-1:#s[index]和数组最后一个字符相等，且出现了k-1次
                    stack.pop()
                    cout.pop()
                    right-=1
                elif stack[right]==s[index]:#相等，但出现次数不到k-1
                    cout[right]+=1
                else:#s[i]和数组最后一个字符不相等
                    stack.append(s[index])
                    cout.append(1)
                    right+=1
            index+=1
        
        ans=""
        for i in range(len(stack)):#拼接新字符串
            ans=ans+stack[i]*cout[i]
        
        return ans


```

