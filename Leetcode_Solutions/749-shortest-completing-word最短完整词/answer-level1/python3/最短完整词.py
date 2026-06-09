### 解题思路
利用字典，判断是否包含licensePlate中的全部元素，最后利用sort(key = len)返回长度最短的完整词。

### 代码

```python3
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        licensePlate = licensePlate.lower()
        up, down = ord('z'), ord('a')
        set_, sum_ = {}, 0
        for i in range(len(licensePlate)):
            temp = ord(licensePlate[i])
            if down <= temp <= up:
                if chr(temp) not in set_:
                    set_[chr(temp)] = 1
                else:
                    set_[chr(temp)] += 1
                sum_ += 1
        ret = []
        for i in words:
            tempSet, tempSum = set_.copy(), sum_
            for j in range(len(i)):
                if i[j] not in tempSet:
                    pass
                elif tempSet[i[j]] > 0:
                    tempSet[i[j]] -= 1
                    tempSum -= 1
                elif tempSet[i[j]] == 0:
                    pass
                if j == len(i) - 1 and tempSum == 0:
                    ret.append(i)
        ret.sort(key = len)
        return ret[0]

```