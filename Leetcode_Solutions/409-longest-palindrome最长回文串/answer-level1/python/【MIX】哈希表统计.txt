### 解题思路
建立哈希表处理长度为奇数和偶数的字符

### 代码

```java []
class Solution {
    public int longestPalindrome(String s) {
        // 贪心模式
        // 直接存储128个ASCII码字符
        int []rec = new int[128];
        char []A = s.toCharArray();
        for(int i=0; i<s.length(); ++i)
            rec[A[i]]++;

        int L = 0;
        for(int v: rec){
            L += v/2*2;
            if((v & 0x01)==1 && (L & 0X01)==0){
                L += 1;
            }
        }

        return L;
    }
}
```
```python []
class Solution:
    def longestPalindrome(self, s: str) -> int:
        N = len(s)
        if N<= 1:
            return N
        
        rec = dict()
        for c in s:
            if c not in rec.keys():
                rec[c] = 1
            else:
                rec[c]+=1
        
        L = 0
        maxO = -1
        for v in rec.keys():
            if rec[v] & 0x01 == 1:
                L += (rec[v]-1)
                maxO = max(maxO, rec[v])
            else:
                L += (rec[v])

        if maxO != -1:
            L += 1

        return L
```
```c++ []
class Solution {
public:
    int longestPalindrome(string s) {
        // 建立统计字符出现次数的哈希表
        unordered_map<char, int> rec;
        int N = s.size();
        if(N <= 1)
            return N;

        for(int i=0; i<N; ++i){
            rec[s[i]]++;
        }

        return oddPanlinTest(rec);

    }

    // 构成回文的方式检测
    // 1.odd 奇数串
    int oddPanlinTest(const unordered_map<char, int>& rec){
        int L = 0;
        int OD = -1;
        for(auto it = rec.begin(); it!=rec.end(); ++it){
            if(it->second % 2){
                OD = max(OD, it->second);
                L += it->second-1;
            }else{
                L += it->second;
            }
        }
        if(OD != -1)
            L += 1;
        return L;
    }
};
```