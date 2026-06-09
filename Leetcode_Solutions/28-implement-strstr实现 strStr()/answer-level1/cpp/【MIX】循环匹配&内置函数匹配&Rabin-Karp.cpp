### 解题思路
循环匹配或者Rabin-Karp

### 代码

```java []
class Solution {
    public int strStr(String haystack, String needle) {
        // Rabin-Karp 算法实现
        // 时间复杂度O(M+N)

        int M = haystack.length();
        int N = needle.length();

        if(M == 0 && N == 0)
            return 0;

        if(M == 0)
            return -1;

        if(N == 0)
            return 0;

        if(M < N)
            return -1;

        int power = 1;
        for(int i=0; i<N; ++i){
            power = (power*B) % P;
        }
        
        // 将目标字符串进行编码
        int nCode = 0;
        for(int i=0; i<N; ++i){
            nCode = (nCode * B + needle.charAt(i))%P;
        }

        // 文本串进行编码&匹配
        int hCode = 0;
        for(int i=0; i<M; ++i){
            // add char
            hCode = (hCode*B + haystack.charAt(i))%P;
            if(i < N-1)
                continue;
            // remove char
            if(i >= N){
                hCode = hCode - (haystack.charAt(i-N)*power)%P;
                if(hCode < 0)
                    hCode += P;
            }

            // 防止哈希冲撞
            if(hCode == nCode){
                if(haystack.substring(i-N+1, i+1).equals(needle))
                    return i-N+1;
            }
        }
       
        return -1;
    }

    private int P = (int)Math.pow(10, 6)+7;
    // 设置编码中的magic number
    private int B = 29;
}
```
```python []
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # 内置函数startswith()
        N, M = len(haystack), len(needle)
        if N==0 and M==0:
            return 0
        i = 0
        for i in range(N):
            if haystack.startswith(needle, i, i+M):
                return i

        return -1
```
```python []
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # 使用内置函数find()
        return haystack.find(needle)
```
```c++ []
```