### 解题思路
特殊处理‘0’开头的时间，其实还不如全部转换成分钟来得快
### 代码

```python3
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints = sorted(timePoints)
        for i in range(len(timePoints)):
            if timePoints[i].split(':')[0].startswith('0'):
                a = timePoints[i].split(':')[0].lstrip('0')
                if not a :
                    timePoints.append('24:'+timePoints[i].split(':')[1])
                else:
                    timePoints.append(str(24 + int(a))+':'+timePoints[i].split(':')[1])
            else:
                break
        ans = float('inf')
        for i in range(len(timePoints)-1):
            a_hour = int(timePoints[i].split(':')[0].lstrip('0')) if timePoints[i].split(':')[0] != '00' else 0
            a_minute = int(timePoints[i].split(':')[1]) if timePoints[i].split(':')[1] != '00' else 0
            b_hour = int(timePoints[i+1].split(':')[0].lstrip('0')) if timePoints[i+1].split(':')[0] != '00' else 0
            b_minute = int(timePoints[i+1].split(':')[1]) if timePoints[i+1].split(':')[1] != '00' else 0
            ans = min(ans,(b_hour - a_hour) * 60 + (b_minute - a_minute))
        return ans
```