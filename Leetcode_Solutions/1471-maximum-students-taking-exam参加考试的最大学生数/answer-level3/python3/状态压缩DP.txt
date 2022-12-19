假设座位的行数为m，列数为n。
首先，每一行的座椅选择可以有2^n种，对于每一种状态，需要判断这种状态是否合法，从3个方面考虑：
（1）首先要满足坏的椅子上不能坐人
（2）其次要满足同一行之间的同学不能互相抄袭
（3）最后要满足不能抄袭到前一行的同学
暂且可以考虑每一行的结果只与上一行有关，那么可以用dp来做，由于题目限制了列数最大为8，所以状态数最多为2^8，不是很大。
递推公式为dp[i][j] = max(dp[i,j], dp[i-1][k]+状态j所占有的椅子数 for k in 上一行可取状态)
大体思路是这样了，还有一些细节需要考虑：
（1）可以用二进制数来表示状态，0可以用来表示对于这一行所有位置都不安排考生，5表示第1个位置和第3个位置安排考生；
（2）可以只使用一维dp，因为我只需要记录上一行的结果，即: (上一行可取那些状态, 在这些状态下对应的目前可安排的最大考生数)，在这里需要考虑一种特殊情况，即有可能对于某一行来说，这一行不安排任何考生，可使最终结果最大，所以我们在考虑每一行的时候，需要把这种情况考虑进去，即都要从0状态开始考虑，这一点很重要；
（3）对于dp保存的结果，只需要保存那些有效的状态，其余无效的状态可以不予考虑，这样可以提高速度和节省空间。
代码如下：
```
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m = len(seats)
        n = len(seats[0])
        temp = [(0, 0)]
        ans = 0
        i = 0
        for i in range(m):
            tmp = []
            for j in range(1<<n):
                a = bin(j)[2:]
                flag = 0
                for idx in range(-1, -min(n, len(a))-1, -1):
                    if seats[i][idx] == '#' and a[idx] == '1':
                        flag = 1
                        break
                if flag:
                    continue
                elif (j & (j << 1)) or (j & (j >> 1)):
                    continue
                else:
                    r = 0
                    for l in range(len(temp)):
                        k, res = temp[l]
                        if ((j << 1) & k) or ((j >> 1) & k):
                            continue
                        else:
                            r = max(r, res + a.count('1'))
                    tmp.append((j, r))
                    ans = max(ans, r)
            temp = tmp
        return ans
```
