### 解题思路
时间复杂度：O(m*n)
唉，代码写的太杂了！！！

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if not num1 or not num2:
            return

        if int(num1)==0 or int(num2)==0:
            return '0'

        res=[]
        index=0   #位数相乘的进位

        for i in range(len(num1)-1, -1, -1):
            temp2=0      #乘法进位
            s=''
            for j in range(len(num2)-1, -1, -1):
                mult = int(num1[i])*int(num2[j])
                mult+=temp2
                temp1=x%10
                s=str(temp1)+s 
                temp2=temp1//10
            if temp2!=0:
                s=str(temp2)+s
            for _ in range(index):  #位数相乘的进位
                s=s+'0'
            res.append(s)
            index+=1
        maxLen=max([len(num) for num in res])
        ans=[]
        for num in res:
            temp=maxLen-len(num)
            ans.append('0'*temp+num)

        temp2=0   #加法进位
        s=''
        for i in range(maxLen-1, -1, -1):
            Sum=sum([int(num[i]) for num in ans])
            Sum+=temp2
            temp1=Sum%10
            s=str(temp1)+s 
            temp2=Sum//10
        if temp2!=0:
            s=str(temp2)+s
        return s


```