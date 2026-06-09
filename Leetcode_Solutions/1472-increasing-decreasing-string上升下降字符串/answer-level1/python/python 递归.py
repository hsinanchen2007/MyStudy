### 解题思路
递归
但是时长有点可怕

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        #递归
        res = []
        if s == '':
            return ''
        s = list(s)
        for i in range(len(s)):
            s[i] = ord(s[i])   
        def min_func(letter_list,last_min = -float('inf')):
            if letter_list == []:
                return 
            min_ = float('inf')
            for i in range(len(letter_list)):
                if letter_list[i] > last_min:
                    min_ = min(min_,letter_list[i])
            if min_ == float('inf'):
                #说明该进入最大的选择了
                max_func(letter_list,last_max = float('inf'))
            else:
                res.append(min_)
                letter_list.remove(min_)
                min_func(letter_list,min_)
        
        def max_func(letter_list,last_max = float('inf')):
            if letter_list == []:
                return 
            max_ = -float('inf')
            for i in range(len(letter_list)):
                if letter_list[i] < last_max:
                    max_ = max(letter_list[i],max_)
            if max_ == -float('inf'):
                min_func(letter_list,last_min = -float('inf'))
            else:
                res.append(max_)
                letter_list.remove(max_)
                max_func(letter_list,max_)
        
        min_func(s)
        res = [chr(res[i]) for i in range(len(res))]
        res = ''.join(res)
        return res

            
            
            

            

```