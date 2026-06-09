### 解题思路
比较连续两个字符的情况，得到一个result，根据result调整数字区域的left和right。
例如num->num  return 1（right右移）
空格->空格，+-，num  return 0（如果right=0，即还未检测到数字串的时候，left右移。如果right>0，说明已检测到数字串，所以left不变）
'A'->数字 return -1（退出循环）
数字->其余情况 return 2（说明数字部分结束，所以right右移的同时需要break）

注：
考虑到空串的情况，原字符串前后都增加一个空格

### 代码

```python3
class Solution:
    def myAtoi(self, string: str) -> int:
        string = ' ' + string + ' '
        def judge(chari,charj):
            if(ord(chari)>=48 and ord(chari)<=57):
                if(ord(charj)>=48 and ord(charj)<=57):
                    return 1
                else:
                    return 2
 
            elif((ord(chari)==43 or ord(chari)==45)):
                if((ord(charj)>=48 and ord(charj)<=57)):
                    return 1
                else:
                    return -1
            elif(ord(chari)==32):
                if(ord(charj)==32 or ord(charj)==43 or ord(charj)==45 or(ord(charj)>=48 and ord(charj)<=57)):
                    return 0
                else:
                    return -1
            else:
                return -1

        right = 0
        left = 0
        for i in range(len(string)-1):
            result = judge(string[i],string[i+1])            
            if(result==0):
                if(right==0) :                   
                    left = i+1
            elif(result==1):              
                right += 1  
            elif(result==2) :
                right += 1  
                break          
            else:
                break
        if (right == 0):
            return 0
        else:
            right += left
            new_int = int(string[left:right])
            if(new_int<-2147483648):
                return -2147483648
            elif(new_int>2147483647):
                return 2147483647
            else:
                return new_int
            
                
            


       
   


```