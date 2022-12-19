![image.png](https://pic.leetcode-cn.com/a79eb314e8c628477f59e2db4cbb2e329d33708ecb229913c1840ad53dd08c60-image.png)

```cgo
输入两个串s1,s2,
    设MaxLen(i,j)表示:  s1的左边i个字符形成的子串，与s2左边的j个字符形成的子串的最长公共子序列的长度(i,j从0开始算）
    MaxLen(i,j) 就是本题的“状态”
    假定len1 = len(s1),len2 = len(s2）
    那么题目就是要求MaxLen(len1,len2)
显然：
    MaxLen(n,0)  = 0  ( n= 0...len1）
    MaxLen(0,n)  = 0  ( n=0...len2）
递推公式：
    if ( s1[i-1] == s2[j-1] ) //s1的最左边字符是s1[0]
        MaxLen(i,j) = MaxLen(i-1,j-1) + 1
    else
        MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) )
```
- 证明

```cgo
S1,S2表示表示长度为i,j的序列
S1[:i-1]表示长度为i-1的序列
S2[:j-1]表示长度为j-1的序列
S1[i-1]表示S1的第i-1个字符
S2[j-1]表示S2的第j-1个字符

在S1[i-1] != S2[j-1]情况下:
MaxLen(S1,S2)不会比MaxLen(S1,S2[:j-1])和MaxLen(S1[:i-1],S2)两者之中任意一个小,也不会比两者都大.
	证明:
采用反证法:
    若MaxLen(S1,S2) 比 MaxLen(S1,S2[:j-1])和MaxLen(S1[:i-1],S2) 都大,
    情况1: MaxLen(S1,S2) > MaxLen(S1,S2[:j-1]
    则,S1[i-1] 必定是 MaxLen(S1,S2)的子序列的关键元素,且为最后一个元素.
    同理:S2[j-1] 必定是 MaxLen(S1,S2)的子序列的关键元素,且为最后一个元素.
    故而S1[i-1]==S2[j-1],
    与假设矛盾,从而假设不成立. 证毕~

```