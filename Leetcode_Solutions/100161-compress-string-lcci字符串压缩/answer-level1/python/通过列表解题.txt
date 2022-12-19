### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str):
        list1 =[]
        for ch in S:
            list1.append(ch)
        len1 =len(list1)
        k =1
        list2 =[]
        new_S =""

        for i in range(len1):
            if (i ==(len1-1)):
                list2.append(list1[i])
                list2.append(str(k))
                break      #当字符运行到最后一个时，结束循环，避免出错
            elif (list1[i] ==list1[i+1]):
                k +=1       #计数
            else:
                list2.append(list1[i])
                list2.append(str(k))
                k =1
        
        len2 =len(list2)
        for item in list2:       #判断新字符和原字符长度
            new_S +=item

        if len2 <len1:
            return new_S
        else:
            return S


            
        
                
            


```