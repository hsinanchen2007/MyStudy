解题思路：
首先思考是先找palindrome再判断是不是prime，还是先找prime再判断是不是palindrome？
根据先验知识，可以知道一定大的范围内，palindrome的数量是少于prime的，因此应该先找prime再判断是不是palindrome。
所以先找到离N最近的palindrome，然后只要满足两个条件：1.大于N， 2.是prime 就可以return

解题步骤：
1. N是不是palindrome：
    - yes：是不是prime：
        - yes：return
        - no：pass
    - no：寻找离N最近的palindrome

2. 离N最近的palindrome是不是大于N：
    - yes：是不是prime：
        - yes：return
        - no：pass
    - no：pass

3. 寻找最近的比N大的palindrome，并判断是不是prime：
    - yes：return
    - no：继续执行步骤3


```
class Solution:
    def primePalindrome(self, N: int) -> int:
        def is_prime(n):        #check whether n is prime
            if n==1:
                return False
            if n==2 or n==3:
                return True
            for i in range(2,int(n**0.5)+1):
                if n%i==0:
                    return False
            return True
        
        def is_palindrome(n):        #check whether n is palindrome
            s=str(n)
            for i in range(int(len(s)/2)):
                if s[i]!=s[len(s)-i-1]:
                    return False
            return True

        def length_is_even(n):      #check whether the length of n is even
            return len(str(n))%2==0

        def change_s(s,i,c):        #replace s[i] with c
            return s[:i]+c+s[i+1:]

        def char_add_one(s,i):      #add one to s[i]
            return change_s(s,i,str(int(s[i])+1))

        def find_next_palindrome(n):        #n is palindrome and find next palindrome greater than n
            s=str(n)
            if not length_is_even(n):
                i=int(len(s)/2)
                if s[i]!='9':
                    s=char_add_one(s,i)
                    return int(s)
                else:
                    s=change_s(s,i,'0')
                    i+=1
            else:
                i=int(len(s)/2)
            
            while i<len(s):
                if s[i]!='9':
                    s=char_add_one(s,i)
                    s=char_add_one(s,len(s)-i-1)
                    return int(s)
                else:
                    s=change_s(s,i,'0')
                    s=change_s(s,len(s)-i-1,'0')
                    i+=1
            
            return 10**len(s)+1

        def find_nearest_palindrome(n):     #n is not palindrome and find the nearest palindrome near n
            s=str(n)
            if len(s)%2==0:
                i=int(len(s)/2)
            else:
                i=int(len(s)/2)+1
            
            while i <len(s):
                s=change_s(s,i,s[len(s)-i-1])
                i+=1
            
            return int(s)

        if is_palindrome(N):
            if is_prime(N):     #if N is palindrome and prime, return N
                return N
        else:
            n=find_nearest_palindrome(N)        #if N is not palindrome, find the nearest palindrome-n
            if n>N and is_prime(n):     #if n is greater than N and is prime, return n
                return n
            else:
                N=n

        N=find_next_palindrome(N)
        while not is_prime(N):      #always find next palindrome until it is prime
            N=find_next_palindrome(N)

        return N
```
