### 解题思路
Python递归的简单解法：用list来存放每个数字对应的字母挺方便；
简单来说其实就是，先遍历digits中的每个数字，然后再组合每个数字对应的字母，读一遍代码即可理解

### 代码

```

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ##递归算法
        ##首先定义每个字符对应的字母
        nums = [" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]  ##表示从0——9的数字表示的字母含义
        res  = []
        if digits=="":
            return res
        
        def recurion(digits,index,s): ##s:没此遍历digits[index]的结果
            if index==len(digits):
                res.append(s)
                return 
            letter = nums[int(digits[index])]
            for i  in range(0,len(letter)):
                recurion(digits,index+1,s+letter[i])
            return
        
        recurion(digits,0,"")
        return res

```