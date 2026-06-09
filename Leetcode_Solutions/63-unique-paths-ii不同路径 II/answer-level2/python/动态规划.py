1、 对于第一行，如果存在1，则将其和后面的全都置为0；
2、 对于第一列，如果存在1，则将其和后面的全都置为0；
3、 对于s[i][j];这里，i,j>0
    1）如果其为1，则将其置为0，s[i][j] = 0；
    2）如果不为1，则s[i][j] = s[i-1][j] + s[i][j-1]
```
class Solution(object):
    
    def uniquePathsWithObstacles(self, s):  #
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if s == [] or s[0][0] == 1 or s[-1][-1] == 1:
            return 0
        m = len(s)
        n = len(s[0])
        i = 0
        while i < n:
            if s[0][i] == 0:
                s[0][i] = 1
            else:
                while i < n:
                    s[0][i] = 0
                    i += 1
            i += 1
        j = 1
        while j < m:
            if s[j][0] == 0:
                s[j][0] = 1
            else:
                while j < m:
                    s[j][0] = 0
                    j += 1
            j += 1
        begin = s[0]
        print(s)
        for i in range(1, m):
            for j in range(1, n):
                if s[i][j] == 1:
                    s[i][j] = 0
                else:
                    s[i][j] = s[i-1][j] + s[i][j-1] 
        return s[-1][-1]
```
