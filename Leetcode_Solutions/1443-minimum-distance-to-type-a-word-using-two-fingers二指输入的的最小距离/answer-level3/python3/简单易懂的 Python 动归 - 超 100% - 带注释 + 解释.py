## 解题思路
我自己没做出来，学习了比赛排行榜上第一页的 suibianfahui 的代码。这个代码是我理解以后自己写的。原来和原代码相同。

### 准备
定义一个字母位置表，再定义一个函数 find_distance 查找任意两个字母间距离

### 动规

mapx[f1, f2] = setp
mapx 是一个字典，
  f1 代表当前状态第一个手指的位置，f2 是第二个手指的位置， None 代表这个手指还没用过
  setp 是现在一共移动了多少距离。

#### 初始状态
mapx[单词第一个字母，None] = 0    代表我用第一个手打了第一个字母，第二个手没动，一共移动 0 步

#### 状态转移方程

从第二个字母开始遍历单词，
对每一个字母要检查**上一步**所有的状态（因为只需要上一步，所以不用 dp 数组，每次都覆盖上一次的结果就可以了）
对每个状态，尝试用第一个手指打当前字母和用第二个手指打当前字母

#### 结果
最后返回 map 中最小值就可以了。



欢迎来[我的博客](https://codeplot.top/)，看我刷的其他题目：[刷题记录](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)
### 代码

```python
class Solution:
    def minimumDistance(self, word: str) -> int:
        if len(word) == 2: # 如果只有两个字母，不需要移动
            return 0
        # 字母位置表
        pos = {}
        ch = ord('A')
        for i in range(5):
            for j in range(6):
                pos[chr(ch)] = (i, j)
                if ch == ord('Z'): break
                ch += 1
        #print(pos)
        # {'A': (0, 0), 'B': (0, 1), 'C': (0, 2), 'D': (0, 3), 'E': (0, 4), 'F': (0, 5), 'G': (1, 0), 'H': (1, 1), 'I': (1, 2), 'J': (1, 3), 'K': (1, 4), 'L': (1, 5), 'M': (2, 0), 'N': (2, 1), 'O': (2, 2), 'P': (2, 3), 'Q': (2, 4), 'R': (2, 5), 'S': (3, 0), 'T': (3, 1), 'U': (3, 2), 'V': (3, 3), 'W': (3, 4), 'X': (3, 5), 'Y': (4, 0), 'Z': (4, 1)}
        def find_distance(a, b): # 求 a， b 两个字母距离
            if a == None: 
                return 0
            return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1])
        
        mapx = {}
        mapx[(word[0], None)] = 0 # map[(a, b)] = setp 代表 第一个手指目前在 a 上， 第二个手指在 b 上， 步数为 setp
                                  # None 代表这个手指还没用过
        for cur in word[1:]:
            next_map = {}
            for finger1, finger2 in mapx:
                f1_dis = find_distance(finger1, cur) # 手指 1 到当前字母的距离
                f2_dis = find_distance(finger2, cur) # 手指 2 到当前字母的距离
                new_state1 = (cur, finger2) # 第一个手指按当前字母（当然第二个手指的状态不变）
                new_state2 = (finger1, cur) # 第二个手指按当前字母
                for new_state, dis in ((new_state1, f1_dis), (new_state2, f2_dis)):
                    if new_state in next_map:
                        next_map[new_state] = min(mapx[(finger1, finger2)] + dis, next_map[new_state])
                    else:
                        next_map[new_state] = mapx[(finger1, finger2)] + dis
            mapx = next_map
        return min(mapx.values())
```