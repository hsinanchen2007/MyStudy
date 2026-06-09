### 1.运行结果
![image.png](https://pic.leetcode-cn.com/e8bb7e529f70190c417d88bf8fc373fc819d15143a8395ebf4703630d1f4a1fc-image.png)

### 2.思路讲解
**2.1 总体原则：拒绝复杂化，只建立最小映射集合：**
1. 根据题干信息，建立哈希map映射表（实质是字典），只映射题干涉及的转化关系，这是最小的集合。这样保证代码的简洁和灵活。
2. 从高位到低位，[1000, 100, 10, 1]，数字num依次除以列表中的4个数字
3. 具体实例，找出转化关系，本来有10种情况，可以合并为4种情况。

**2.2 备注：python小知识**
![image.png](https://pic.leetcode-cn.com/c83d3f257ef7968b45dec8130548e416d4b6e7112f3026912b87a200c920d062-image.png)

**2.3 代码**
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        map_ = {
            1 : 'I',
            5 : 'V',
            10 : 'X',
            50 : 'L',
            100 : 'C',
            500 : 'D',
            1000 : 'M'
        }
        list_ = [1000, 100, 10, 1]
        result = ''
        
        for i in list_:
            a = num//i
            if a == 9:
                result += map_[i]
                result += map_[i*10]
            elif a == 4:
                result += map_[i]
                result += map_[i*5]
            elif a < 9 and a > 4 :
                result += map_[5*i]
                result += int(a-5)*map_[i]
            else:
                result += int(a)*map_[i]
            num %= i
            
        return result
                
```


