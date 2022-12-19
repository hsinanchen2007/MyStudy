![image.png](https://pic.leetcode-cn.com/69bb47f641f64cd179c4c3c4961cc7e303c3bbe2bd0ca476ce194a60da4a0fc6-image.png)


```
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        m = {}      # 字符到位置的映射
        for i in range(26):
            m[chr(ord('a') + i)] = (i // 5, i % 5)

        pos_i, pos_j = 0, 0
        path = []
        for ch in target:
            t_i , t_j = m[ch]
            move_i, move_j = t_i - pos_i, t_j - pos_j

            # 左下必须先先往左走，然后往下走，右上必须先往上走，然后往上走
            p1, p2 = [], []
            if move_j > 0:
                p1 = ['R'] * int(move_j)
            elif move_j < 0:
                p1 = ['L'] * int(-move_j)

            if move_i > 0:
                p2 = ['D'] * int(move_i)
            else:
                p2 = ['U'] * int(-move_i)

            if move_j > 0 and move_i < 0:
                p1, p2 = p2, p1

            path.extend(p1)
            path.extend(p2)
            path.append('!')

            pos_i, pos_j = t_i, t_j

        return ''.join(path)
```
