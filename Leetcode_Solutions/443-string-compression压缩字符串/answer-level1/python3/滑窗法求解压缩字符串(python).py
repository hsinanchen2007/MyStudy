## 变量说明
- 本解题方法使用滑窗法，窗口数量为2，窗口值分别赋值到变量l和m
- 计数器cnt用于一次计数过程中，连续出现变量l中字符的个数，初始值为0
- 变量pointer用于记录下一次写入chars数组字符时的位置
## 执行状态
执行状态分为计数状态分为：计数状态（l==r)和计数结束状态（l!=r）
### 计数状态
在遍历chars数组的过程中，当l==m时，说明变量l中的字符连续出现，计数器cnt自加1，直到*计数结束状态*  
当l = chars[len(chars) - 1]时意味着对chars的遍历结束，此时令r = None，必有l!=r, 从而强制进入*计数结束状态*  
### 计数结束状态
在遍历chars数组的过程中，当l!=m时，说明对变量l中的字符计数结束，此时需要将计数数据写入chars中  
当cnt为0时，不需要将cnt的值写入chars中，只需写入变量l即可  
每一次计数结束状态后，cnt需要置0  
## 遍历结束
遍历chars数组结束后，需要把多余的数据弹出  
## 上代码
```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        cnt = 0                             #计数器cnt用于一次计数过程中，连续出现变量l中字符的个数
        pointer = 0                         #pointer是下一次写入chars数组字符时的位置
        if len(chars) == 1:                 #如果chars数组元素只有一个
            return len(chars)               #那么，直接返回chars长度，无需修改
        else:                               #如果chars数组元素个数大于1
            for i in range(len(chars)):     #遍历循环数组chars
                l = chars[i]                #将滑窗左侧的字符赋值l
                r = chars[i + 1] if i < len(chars) - 1 else None    #将滑窗右侧的字符赋值r，如果数组越界则赋值None
                if l == r:                  #如果l==r，则计数+1
                    cnt += 1
                else:                       #如果遇到l!=r，则停止计数
                    chars[pointer] = l      #将字符l写进pointer所在的位置
                    pointer += 1            #写入后，更新pointer，pointer自加1
                    if cnt != 0:            #如果有连续的字符，则还需在此字符后面写入该字符的数量
                        for idx, val in enumerate(list(str(cnt + 1))):
                            chars[pointer] = val
                            pointer += 1    #每写一次chars数组，更新一次位置
                    cnt = 0                 #一次计数结束后，cnt置0
        for i in range(pointer, len(chars)):#将多余的数据删除
            chars.pop(-1)
        return len(chars)
```
![屏幕快照 2019-07-18 08.21.45.png](https://pic.leetcode-cn.com/06dbf04f4d3c931c85a7570549cb2100a70de05facc959e7390bd90958e78459-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-18%2008.21.45.png)
