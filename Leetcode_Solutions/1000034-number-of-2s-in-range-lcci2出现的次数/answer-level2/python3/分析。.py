### 解题思路

分开看位数。
只看个位  n//10    
十位的2  n//100*10   每100有20-30  个位出现2  特殊情况是20-30之间
百位的2  n//1000*100  每1000有200-300  个位出现2  特殊情况是200-300之间(即需要当前位数判断情况再结合余数算入count)

如果有边上的比如 22
十位数比较明显如 22 就要算 (22-20)+1
如果达到30就直接 +10

同理百位千位。所以用i表示10，100，1000
cur表示当前位数


### 代码

```python3
class Solution:
    def numberOf2sInRange(self, n: int) -> int:        
        ans=0;
        i=1
        while i<=n:
            temp= (n//i) ##一般count计数
            cur=temp%10  ##当前位数
            temp1=temp//10 ##一般count计数
            temp2=n%i      ##边界count
            ans+=temp1*i   
            if(cur==2): ans+=temp2+1   
            if(cur>2): ans+=i
            i=i*10
        return ans

                         

            

```