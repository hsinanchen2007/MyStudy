### 解题思路：
相似的查找算法有 **KMP，BM，Horspool**，挑了一个在实际情况中效果较好且理解简单的算法，即 **Sunday 算法**。

#### 一、Sunday 匹配机制

匹配机制非常容易理解：

- 目标字符串``String`` 
- 模式串   ``Pattern``
- 当前查询索引 ``idx`` （初始为 $0$）

- 待匹配字符串 `str_cut` : `String [ idx : idx + len(Pattern) ]`

每次匹配都会从 **目标字符串中** 提取 **待匹配字符串**与 **模式串** 进行匹配： 

- 若匹配，则返回当前 ``idx``

- 不匹配，则查看 **待匹配字符串** 的后一位字符 ``c``：
    1. 若``c``存在于``Pattern``中，则 `idx = idx + 偏移表[c]`
    
    2. 否则，`idx = idx + len(pattern)`
    
Repeat Loop 直到 `idx  + len(pattern) > len(String)`

---

#### 二、偏移表

偏移表的作用是存储每一个在 **模式串** 中出现的字符，在 **模式串** 中出现的最右位置到尾部的距离 $+1$，例如 aab：

- a 的偏移位就是 `len(pattern)-1 = 2`
- b 的偏移位就是 `len(pattern)-2 = 1`
- 其他的均为 `len(pattern)+1 = 4`

综合一下：

![截屏2019-10-0715.55.49.png](https://pic.leetcode-cn.com/4df9b74fb5ccb6e1e4b5c3877356d97806e998c1e751f667f4f9e587d92809bd-%E6%88%AA%E5%B1%8F2019-10-0715.55.49.png){:width=500}
{:align=center}

---

#### 三、举例

String: `checkthisout`
Pattern: `this`

#### Step 1:
![截屏2019-10-0716.15.15.png](https://pic.leetcode-cn.com/3d311ba9ddbb37487a475b95875f49351750aa89cea6b77d974cde45603cf63d-%E6%88%AA%E5%B1%8F2019-10-0716.15.15.png){:width=400}
- $idx = 0$
- 待匹配字符串为：`chec`
- 因为 `chec != this`
- 所以查看 `chec` 的下一个字符 `k`
- `k` 不在 Pattern 里 
- 所以查看 偏移表，`idx = idx + 5`

#### Step 2:
![截屏2019-10-0716.16.44.png](https://pic.leetcode-cn.com/c959fe5147959af3cb32a98183ac430a1145ae4341fe7620105ccd5b88d77b59-%E6%88%AA%E5%B1%8F2019-10-0716.16.44.png){:width=400}

- $idx = 5$
- 待匹配字符串为：`this`
- 因为 `this == this`
- 匹配，所以返回 $5$

---

#### 四、算法分析
最坏情况：$O(nm)$
平均情况：$O(n)$

---

#### 五、代码

```python [-Python]
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
    
        # Func: 计算偏移表
        def calShiftMat(st):
            dic = {}
            for i in range(len(st)-1,-1,-1):
                if not dic.get(st[i]):
                    dic[st[i]] = len(st)-i
            dic["ot"] = len(st)+1
            return dic
        
        # 其他情况判断
        if len(needle) > len(haystack):return -1
        if needle=="": return 0
       
        # 偏移表预处理    
        dic = calShiftMat(needle)
        idx = 0
    
        while idx+len(needle) <= len(haystack):
            
            # 待匹配字符串
            str_cut = haystack[idx:idx+len(needle)]
            
            # 判断是否匹配
            if str_cut==needle:
                return idx
            else:
                # 边界处理
                if idx+len(needle) >= len(haystack):
                    return -1
                # 不匹配情况下，根据下一个字符的偏移，移动idx
                cur_c = haystack[idx+len(needle)]
                if dic.get(cur_c):
                    idx += dic[cur_c]
                else:
                    idx += dic["ot"]
            
        
        return -1 if idx+len(needle) >= len(haystack) else idx
```


