Python3 基础写法
        执行用时 :56 ms, 在所有 python3 提交中击败了92.02%的用户
        内存消耗 :13.9 MB, 在所有 python3 提交中击败了100.00%的用户
```
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        """
        执行用时 :56 ms, 在所有 python3 提交中击败了92.02%的用户
        内存消耗 :13.9 MB, 在所有 python3 提交中击败了100.00%的用户
        :param keyboard: 
        :param word: 
        :return: 
        """
        index = 0
        count = 0
        for i in word:
            count += abs(index - keyboard.index(i))
            index = keyboard.index(i)
        return count
```
