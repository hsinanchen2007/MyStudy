### 解题思路
https://blog.csdn.net/u011500062/article/details/72855826
讲的很明白
约瑟夫环——公式法（递推公式）
f(N,M)=(f(N−1,M)+M)%N

### 代码

```csharp
public class Solution {
    public int LastRemaining(int n, int m) {
    
   
        int p=0;
	for(int i=2;i<=n;i++)
	{
		p=(p+m)%i;
	}
    return p;
    }


    
}
```