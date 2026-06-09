```
import sys
count= input('输入一个数字：').strip()
while len(str(count))>1:
    zero = 0
    for i in str(count):
        zero+=int(i)
        print(i,zero)
    count=zero
    if len(str(zero))==1:
        break
print(zero)
#注意len（）不能是int格式

