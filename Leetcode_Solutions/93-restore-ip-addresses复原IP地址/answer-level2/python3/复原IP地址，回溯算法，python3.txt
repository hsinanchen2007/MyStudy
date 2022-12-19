### 解题思路
*IP*总共分为**四段**，每段的取值范围是**[0, 255]**
回溯函数`backtrack`的参数有三个
1. `string`：待分配的数字
2. `temp`：按照*IP*格式已分配好的数字组合
3. `count`：当前还剩几段*IP*未分配

那么，在回溯函数`backtrack`中：
- **如果`count`等于0，并且`string`不为空**：说明`temp`已经为合法*IP*地址，但是还有剩余的未分配数字，不符合题意，返回
- **如果`count`等于0，并且`string`为空**：说明正好分配地合适，存下当前结果
- 进行到这里，说明`count`一定大于0，那么先看`string`
1. **如果`string`为空**：即*IP*地址尚未合法的情况下，已经没有剩余字符可分配了，不符合题意，返回
2. **如果`string`不为空**：继续分配。**如果`string`的第一个字符为0，那么当前*IP*段只能等于0，因为以0开头的非0整数并不合法，比如23不能写为023。**所以当前*IP*段直接取0，然后继续回溯分配下一段*IP*。否则，遍历`string`并递归调用回溯函数`backtrack`，参数为未分配字符`string[i:]`，已分配好的IP字符串前缀`temp + ('.'+string[:i])`，剩余未分配*IP*段数`count-1`，直到`string[:i]`不满足`0 <= int(string[:i]) <= 255`条件。

### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def backtrack(string, temp, count):
            if count == 0 and len(string) != 0:
                return
            if count == 0 and len(string) == 0:
                res.append(temp[1:])
            else:
                if not string:
                    return
                if string[0] == '0':
                    backtrack(string[1:], temp + ('.'+string[:1]), count-1)
                else:
                    for i in range(1, len(string)+1):
                        if 0 <= int(string[:i]) <= 255:
                            backtrack(string[i:], temp + ('.'+string[:i]), count-1)
                        else:
                            break
        res = []
        backtrack(s, '', 4)
        return res
```