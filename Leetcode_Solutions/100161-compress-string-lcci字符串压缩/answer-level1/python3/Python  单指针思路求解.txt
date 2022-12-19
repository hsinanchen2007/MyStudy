### 解题思路
从左往右遍历字符串，cur代表当前正在进行统计的字母，一旦字母发生改变，先将之前统计的字母与频次进行编码压缩，再将cur指向新的需要统计的字母，最后比较长短，返回短的，应注意，当相等时返回原字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        cur = S[0]
        count = 1
        compress_str = ""
        for i in range(1,len(S)):
            if S[i] == cur:
                count += 1
            else:
                compress_str += (cur + str(count))
                cur = S[i]
                count = 1
        
        # 加入最后统计的那个字母的压缩编码
        compress_str += (cur + str(count))
        return S if len(S) <= len(compress_str) else compress_str 

```