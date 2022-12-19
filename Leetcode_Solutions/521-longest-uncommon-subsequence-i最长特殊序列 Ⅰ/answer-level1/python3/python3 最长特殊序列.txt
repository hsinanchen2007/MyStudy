这题我读了3遍才理解要做什么。。。实际上就是找字符串A的子串，该子串不是B的子串，输出的是子串的最大长度。（A，B反过来也行）
思路：A,B如果完全一样，输出就是 -1，如果不一样，那直接输出A,B中较长的字符串即可
```
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return max(len(a), len(b)) if a!=b else -1
```
