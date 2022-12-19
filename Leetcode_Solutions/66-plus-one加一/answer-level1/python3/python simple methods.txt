### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        '''
        num_str=''
        for i in range(len(digits)):
            num_str += str(digits[i])
        num_int = int(num_str)+1
        return [int(x) for x in str(num_int)]
        '''
        '''
        num_str=""
        for i in digits:
            num_str = num_str+str(i)
        num_int = int(num_str)+1
        res=[]
        for i in str(num_int):
            res.append(int(i))
        return res
        '''
        
        return [int(j) for j in str(int("".join([str(i) for i in digits])) + 1)]
        
        '''
        return list(map(int, str(int("".join(map(str, digits))) + 1)))
        '''
        '''
        return  [*map(int, [*str(int(''.join([*map(str, digits)]))+1)])]
        '''
        '''
        for i in range(len(digits))[::-1]:
        #for i in range(1,len(digits)+1):
            if digits[i]!=9:
            #if digits[-1]!=9:
                digits[i]+=1
                #digits[-1]+=1
                return digits
            else:
                # 若是 9 则为 0，全是 9 则全为 0
                digits[i]=0
                #digits[-1]=0
        # 全是 9 则在首位插入 1
        digits.insert(0,1)
        return digits
        '''
        '''
        i = 0
        while i<len(digits):
            if digits[len(digits)-1-i]==9:
                digits[len(digits)-1-i]=0
                i+=1
            else:
                break
        if i==len(digits):
            digits.insert(0,1)
            return digits
        else:
            digits[len(digits)-1-i]+=1
            return digits
        '''
        '''
        # 先加 1
        digits[-1]+=1
        # 针对首位不是九
        for i in range(len(digits)-1,0,-1):
            if digits[i]==10:
                digits[i]=0
                digits[i-1]+=1
                if digits[i-1]!=10:
                    return digits
        # 针对首位为 9
        if digits[0]==10:
            digits[0]=0
            digits.insert(0,1)
            return digits
        # 个位数且不为 9
        return digits
        '''
        '''
        sum=0
        for i in range(1,len(digits)+1):
        #for i in range(len(digits)):
            sum+=digits[-i]*10**(i-1)
            #sum+=10**(len(digits)-1-i)*digits[i]
        return [int(x) for x in str(sum+1)]
        '''
        '''
        sum=0
        for i in digits:
            sum=sum*10+i
        return [int(x) for x in str(sum+1)]
        #return map(int,list(str(sum+1)))
        '''
        '''
        sum = 0
        for i,v in enumerate(digits[::-1]):
            sum+=v*10**i
        return list(map(int,str(sum+1)))
        '''
        digits,k = digits[::-1],1
        for i,v in enumerate(digits):
            if v+k<10:
                digits[i]=v+k
                k = 0
                break
            else:
                k,digits[i]=1,0
        if k==1:
            digits.append(1)
        return digits[::-1]
        '''
        temp = 1
        for i in range(len(digits)-1,-1,-1):
            if temp==0:
                break
            if i==0 and digits[i]+temp==10:
                digits[i]=(digits[i]+temp)%10
                digits=[1]+digits
                continue
            cur = digits[i]+temp
            digits[i]=cur%10
            temp=cur//10
        return digits
        '''
        '''
		num = 0
		#先将输入的数组转化成int变量
		for i in range(len(digits)):
			num+=digits[i]*pow(10,len(digits)-i-1)
		#按照题目要求，将结果直接加1
		num = num+1
		tmp = num
		count = 0 #count用来记录加一之后的结果有几位数
		#计算加一后的结果有几位
		while(tmp!=0):
			tmp = tmp//10
			count+=1
		new_digits = []
		#将整数型结果每一位放入数组中，最后反转数组即可
		for i in range(count):
			new_digits.append(num%10)
			num = num//10
		new_digits = new_digits[::-1]
		return new_digits
        '''
        '''
        return self.addOne(digits,len(digits)-1)

    def addOne(self,digits,index):
	    if index == -1:
		    digits.insert(0,1)
		    return digits
	    digits[index] = digits[index] + 1
	    if digits[index] == 10:
		    digits[index] = 0
		    return self.addOne(digits, index - 1)
	    return digits
        '''
```