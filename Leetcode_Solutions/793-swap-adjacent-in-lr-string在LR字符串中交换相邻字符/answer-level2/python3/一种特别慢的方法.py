### 解题思路
我来说一个运行特别慢的方法。
不停的重复：
  首先去掉start和end里面相同的部分。
  如"RXXX"和"LXXX"，则变成"R"和"L"。
  然后如果start里有"RX"，且end在该位置上是"XR"，就把start里的"RX"就把它变成"XR"。
  同理，如果start里有"XL"，且end在该位置上是"LX"，就把start里的"XL"变成"LX"。
  如果新的start不为空，就继续执行循环，为空的话就返回True

如果上面的循环超过了500000，就返回false

### 代码

```python3
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        if len(start) != len(end):
            return False
        i = 0
        start_new = ''
        end_new = ''
        n = 0
        while True:
            n+=1
            if n==500000:
                return False
            try:
                if start[i] != end[i]:
                    start_new = start_new + start[i]
                    end_new = end_new + end[i]
                i += 1
            except:
                if start_new == '':
                    break
                i = 0
                start = start_new
                end = end_new
                while True:
                    if start.find('RX')!=-1 and end.find('XR')==start.find('RX'):
                        start = start[0:start.find('RX')] + start[start.find('RX')+2:]
                        end = end[0:end.find('XR')] + end[end.find('XR')+2:]
                        continue
                    if start.find('XL')!=-1 and end.find('LX')==start.find('XL'):
                        start = start[0:start.find('XL')] + start[start.find('XL')+2:]
                        end = end[0:end.find('LX')] + end[end.find('LX')+2:]
                        continue
                    break
                start_new = ''
                end_new = ''
                continue
        return True
```