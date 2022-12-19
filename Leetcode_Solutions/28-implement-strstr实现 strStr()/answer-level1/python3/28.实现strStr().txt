如果needle是空字符，返回0，
如果needle可以在haystack中找到，则对haystack根据needle字符串进行分割，
needle的开始位置便是haystack根据needle分割的第一个list的长度。
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle :
            return 0

        return len(haystack.split(needle)[0]) if needle in haystack else -1
```
![image.png](https://pic.leetcode-cn.com/1ede5fa3355229283e3e7085904be6288fbdcd005665f197604f685e8262edfe-image.png)


评论里看到的切片法，觉得挺好：
```
# 切片法
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle :
            return 0
        
        for i in range(0,len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)] == needle:
                return i
            
        return -1

```

![image.png](https://pic.leetcode-cn.com/d94d7bb320099fd78f8ca01e9555682a07d5478e19ee79c4ad58fc8f74cb697a-image.png)


如果把切片法的len取出来，不用每次计算len，则性能会大大提高：
```
def strStr(self, haystack: str, needle: str) -> int:
        if not needle :
            return 0

        hay_len = len(haystack)
        need_len = len(needle)
        end_num = hay_len - need_len + 1

        for i in range(0,end_num):
            if haystack[i:i+len(needle)] == needle:
                return i
            
        return -1
```

![image.png](https://pic.leetcode-cn.com/fcb3be49f04d84234e872cbe29f4abaddcd01efcf7643559334e6d638117c9fa-image.png)
