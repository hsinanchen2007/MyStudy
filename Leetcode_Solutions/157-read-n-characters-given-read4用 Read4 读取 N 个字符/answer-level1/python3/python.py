```
class Solution:
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        #first way
        tmp=["","","",""]
        cnt = 0
        read4(tmp)
        while tmp!=["","","",""]:
            for i in range(4):
                if tmp[i] is not None:
                    buf[cnt] = tmp[i]
                    cnt+=1
                    if cnt==n+1:
                        return n
            tmp=["","","",""]
            read4(tmp)
        return cnt

        #second way
        '''
        cur = 0
        while n>0:
            cache = [' ']*4
            r = read4(cache)
            print("r=",r)
            print("cache=",cache)
            buf[cur:cur+r] = cache
            print("buf[cur:cur+r]",buf[cur:cur+r])
            print("cur=",cur)
            cur+=r
            print("cur=",cur)
            if r<4:
                break
        return min(cur,n)
        '''
```
