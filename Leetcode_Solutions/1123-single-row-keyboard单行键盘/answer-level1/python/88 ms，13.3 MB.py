### 解题思路
菜鸟思路
1，先循环一遍keyboard，将字母与下标录入进hashmap里
2，然后再循环查找字符串，对应hashmap里的下标的值，计算两两的距离(绝对值))
3，返回距离的总和
  ※注意点：起点から最初の文字の距離を結果に加えるように

計算量はよくわからないが、O(n+w)かな？

### 代码

```python3
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        keyboardMap = {}
        for k in range(len(keyboard)):
            keyboardMap[keyboard[k]] = k
        wordList = list(word)
        i = 0
        res = keyboardMap[wordList[0]]
        while i < len(wordList) -1 :
            res += abs(keyboardMap[wordList[i]] - keyboardMap[wordList[i+1]])
            i += 1
        return res

```