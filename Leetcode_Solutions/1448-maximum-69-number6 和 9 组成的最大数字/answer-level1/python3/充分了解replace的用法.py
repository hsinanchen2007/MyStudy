### REPLACE说明
1  str.replace(old, new[, max])
2  Python replace() 方法把字符串中的 old（旧字符串）替换成 new(新字符串)，如果指定第三个参数max，则替换不超过 max次
3  原str不被更改，使用需由新的变量接收
4  replace调用C的接口，无python源码
5  经测试，str里不存在old时返回原str，不会报错的
### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6','9',1))
```