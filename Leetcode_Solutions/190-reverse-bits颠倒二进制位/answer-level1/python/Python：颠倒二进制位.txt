### 解题思路
想偷个懒，但是Python太难调了
1、输入居然会自动转为十进制
2、bin开头还会添加0b二进制识别
3、[::-1]翻转居然自动删掉0,还得补齐

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        #print(bin(n))
        #print(bin(n)[2:][::-1])
        return int('0b'+bin(n)[2:].zfill(32)[::-1],2)
```