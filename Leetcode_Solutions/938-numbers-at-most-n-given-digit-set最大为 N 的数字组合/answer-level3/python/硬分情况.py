### 解题思路
分情况,一种是位数小于他的,直接相当于len(D)**位数
另一种,从第一位开始扫,如果这一位可以小于他,等于这一位小于他的个数+剩下位数的任意组合
      如果这一位可以等于,则继续循环
最后根据是否可能相等进行+1

### 代码

```python
class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        #位数小于他的,统计一下个数
        N=str(N)
        l=len(N)
        result=0
        for i in range(1,l):
            result+=len(D)**i
            print '位数为{}的有{}个'.format(i,len(D)**i)
            
        
        #接下来就是位数等于他的.从头开始.
        #一种是从头开始相等,直到有一位小于它,然后剩下的都任意
        #一种是从头就小于它,然后剩下的任意

        for i in range(len(N)):
            # print [x for x in D if x < N[i]]
            #一种是这里就比他小了
            if len([x for x in D if x < N[i]]):
                for _ in [x for x in D if x < N[i]]:
                    # print N ,len(N)
                    # print len(D),len(N),i,1
                    result+=len(D)**(len(N)-i-1)
            #另一种是这里还和他保持一样,否则直接break
            if N[i] in D :
                continue
            else:
                break
        if not [x for x in set(N) if x not in D]:
            print '相等的还有一个'
            result+=1
        return result

```