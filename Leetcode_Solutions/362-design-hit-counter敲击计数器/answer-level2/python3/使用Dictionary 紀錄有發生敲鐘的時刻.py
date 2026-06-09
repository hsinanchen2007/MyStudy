### 解题思路
使用Dictionary 紀錄有發生敲鐘的時刻
在需要get的時候 統計在時間內發生敲擊的總和

### 代码

```python3
class HitCounter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.record = {}
        

    def hit(self, timestamp: int) -> None:
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        if timestamp not in self.record:
            self.record[timestamp] = 0
        self.record[timestamp] += 1     
        

    def getHits(self, timestamp: int) -> int:
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        start = timestamp - 300
        count = 0
        for key in self.record:
            if start < key <= timestamp:
                count += self.record[key]
        return count        


        


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
```