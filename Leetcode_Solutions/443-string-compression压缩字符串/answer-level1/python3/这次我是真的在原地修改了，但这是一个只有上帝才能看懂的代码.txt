### 解题思路
![QQ截图20200215143740.png](https://pic.leetcode-cn.com/4145e6eb337ee6ac5c1e71e87b0b1f4d5ba923af71e83fc72f2c8f6415ae1b4f-QQ%E6%88%AA%E5%9B%BE20200215143740.png)


### 代码

```python3
class Solution:
    def compress(self,chars: List[str]) -> int:
        if len(chars)==1:
            return 1
        i=0
        where_replace=i+1
        while  i < len(chars) - 1 and chars[i]!=None:
            nums_of_temp=0
            if chars[i]==chars[i+1]:
                temp=chars[i]
                nums_of_temp=2
                j=i+2
                while j < len(chars)  and chars[j]!=None:
                    if chars[j]==temp:
                        nums_of_temp+=1
                        j+=1
                        continue
                    else:
                        break
                nums_str=str(nums_of_temp)
                where_replace=i+1
                for each_num in nums_str:
                    chars[where_replace]=each_num
                    where_replace+=1
                m=j
                n=where_replace
                while m < len(chars) and chars[m]!=None:
                    chars[n]=chars[m]
                    n+=1
                    m+=1
                if n < len(chars) :
                    chars[n] = None
                i = where_replace
            else:
                i+=1
                if chars[i] == None:
                    where_replace=i
                else:
                    where_replace = i+1
        if where_replace==len(chars)-1:
            where_replace+=1
        if chars[where_replace-1]==None:
            where_replace-=1
        return where_replace





```