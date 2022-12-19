### 解题思路
类似于杀人游戏，到你的时候就把下一个人干掉，争取本轮的先发优势。然后把本轮存活的人重新遍历，直到只剩下一方。
![image.png](https://pic.leetcode-cn.com/7acacf2ad36d8637dc6ef06dca96675bed7fa517bcc9cb2d10bb81c02909ed18-image.png)

### 代码

```python3
S_MAP = {
    'R': 'Radiant',
    'D': 'Dire'
}


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        senate_list = list(senate)
        r_count = 0
        while 'R' in senate_list and 'D' in senate_list:
            tmp_list = []
            for i, v in enumerate(senate_list):
                if v == 'R':
                    if r_count >= 0:
                        tmp_list.append(v)
                    r_count += 1
                elif v == 'D':
                    if r_count <= 0:
                        tmp_list.append(v)
                    r_count -= 1
            
            senate_list = tmp_list
        
        if 'R' in senate_list:
            return 'Radiant'
        
        return 'Dire'
```