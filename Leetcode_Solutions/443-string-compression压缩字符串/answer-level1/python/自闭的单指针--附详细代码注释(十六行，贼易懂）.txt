
### 思路
只用一个i做指针，应该算单指针吧？cnt只是用来计数的

我受不了我这个弱智代码了。

为什么计数超过10的，要！裂！开！来！输！出？

我  裂  开  了  ！

思路就是直接while循环，cnt计数，指针i，仙人指路
碰到cnt为1的，直接跳过去
碰到chars[i] == chars[i+1]的，cnt += 1,pop掉后面这个重复值
碰到chars[i] != chars[i+1]的，插入一个cnt在i+1处，然后重置cnt=1
（逐个字符插入嗷，超过1个的，把指针更新一位i+=1）
最后一个，如果cnt==1：直接输出
如果cnt > 1: 把cnt逐个字符的插入在i+1位置

### 代码
```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        cnt, i  = 1, 0    #指针初始化
        while i < len(chars)-1:
            if chars[i]==chars[i+1]:
                cnt += 1    #重复就计数加1
                chars.pop(i+1)    #并且把重复的元素pop掉
            elif  chars[i]!= chars[i+1]:
                if cnt==1:i+=1    #如果是单元素，就忽略，指针后移1位
                else:     #否则就把计数cnt， 字符列表化，逐位插入到后面
                    for cnt in list(str(cnt)):
                        chars.insert(i+1,str(cnt))
                        i +=1     #每插入一个数字，指针后移一位
                    cnt, i = 1, i+1    #初始化计数，cnt=1, 插入所有的cnt后，指针后移一位
        if cnt != 1:    #处理最后一组计数，如果不是1，逐位插入cnt字符
            chars.extend([str(x) for x in list(str(cnt))])
            return len(chars)
        else: return len(chars)    #最后一组cnt=1，省略计数字符
```