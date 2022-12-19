class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ln=list()
        for i in range(1,(n+1)):
            ln.append(str(i))
            if i%3==0 and i%5!=0:
                ln[i-1]="Fizz"
            elif i%3!=0 and i%5==0:
                ln[i-1]="Buzz"
            elif i%3==0 and i%5==0:
                ln[i-1]="FizzBuzz"
  
        return ln


通过循环将数字写入新建列表，同时将符合条件的列表元素直接替换