### 解题思路

A重复多少次可以包含B？首先我们先比较两个字符串的长度，无非两种情况（下面将A.length简写为A，B类同）

- B<A，B/A 为0 这样的话只有三种结果 1，2，或者-1
- B>A，B/A 为 t，这个时候需要注意，B/A==t，说明B至少由t个A叠加而成，否则根本凑不够B的字符串长度，那么至多呢？至多也就是 t+2 个A叠加而成，所以只用三种情况：t，t+1，t+2；这样的话判断的次数就少了很多，很多其他解答都是暴力匹配，不如精确制导

注释：StringBuilder append 函数执行速度比 A+A（字符串相加）要快，故使用了StringBuilder，直接使用 String 也是可以的。

特别注释：特别搞不懂，为什么缩进很标准的代码发布题解之后就变成了胡乱缩进，气死个人

### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
		StringBuilder reslut = new StringBuilder(A);
		String temp = A;
		int t = B.length()/A.length();
		if(t==0) {
			if(A.contains(B)) return 1;
			else if ((A+A).contains(B)) return 2;
			else {
				return -1;
			}
		}
		for(int i=0;i<t-1;i++) {
			reslut.append(temp);
		}
		//现在的A是tA
        for(int i = t;i<t+3;i++){     
        	if(reslut.toString().contains(B)){
                return i;
            }
        	reslut.append(temp);
        }
        return -1;
    }
}
```