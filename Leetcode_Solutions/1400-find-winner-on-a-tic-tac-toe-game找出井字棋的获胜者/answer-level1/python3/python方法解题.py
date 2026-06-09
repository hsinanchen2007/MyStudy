### 解题思路
采用近乎暴力的解决方法 100% 100%

### 代码

```python3
class Solution:
    def judge_result(self,moves1):
        if len(moves1)<3:
            return False
        else:
            for i in range(len(moves1)-2):
                for j in range(i+1,len(moves1)-1):
                    for z in range(j+1,len(moves1)):
                        list1=sorted([moves1[i],moves1[j],moves1[z]])
                        if moves1[i][0]==moves1[j][0]==moves1[z][0] or moves1[i][1]==moves1[j][1]==moves1[z][1] :
                            return True
                        if list1==[[0, 2], [1, 1], [2, 0]] or list1 == [[0,0],[1,1],[2,2]]:
                            return True
            return False
    def tictactoe(self, moves):
        odd=[]
        even=[]
        for i in range(len(moves)):
            if i%2==1:
                even.append(moves[i])
            else:
                odd.append(moves[i])
        if self.judge_result(odd):
            return 'A'
        if self.judge_result(even):
            return 'B'
        if len(moves)==9:
            return 'Draw'
        else:
            return 'Pending'
s1=Solution()
print(s1.tictactoe([[0,0],[1,1]]))
```