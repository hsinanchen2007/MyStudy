### 解题思路
此处撰写解题思路
先读取数值和符号，再计算乘除法，再计算加减法。

### 代码

```python3
class Solution:
    def calculate(self, s: str) -> int:
        label=[]
        nums=[]
        falg=0
        s=s.replace(' ','')
        for i in range(len(s)):
            if s[i:i+1]=='-'or s[i:i+1]=='+' or s[i:i+1]=='*' or s[i:i+1]=='/':
                label.append(s[i:i+1])
                nums.append(s[falg:i])
                falg=i+1
        nums.append(s[falg:])
        label_length=len(label)
        i=0
        while i<label_length:
  
            if label[i]=="*":
                temp=int(nums[i])*int(nums[i+1])
                nums[:]=nums[:i]+[temp]+nums[i+2:]
                label[:]=label[:i]+label[i+1:]
                label_length-=1
                i-=1
            elif label[i]=="/":
                temp=int(int(nums[i])/int(nums[i+1]))
                nums[:]=nums[:i]+[temp]+nums[i+2:]
                label[:]=label[:i]+label[i+1:]
                label_length-=1
                i-=1
            i+=1
        if len(nums)==1:
            return int(nums[0])
        result=int(nums[0])
        
        for i in range(len(label)):
            if label[i]=='+':
                result+=int(nums[i+1])
            elif label[i]=='-':
                result-=int(nums[i+1])
        return result
```