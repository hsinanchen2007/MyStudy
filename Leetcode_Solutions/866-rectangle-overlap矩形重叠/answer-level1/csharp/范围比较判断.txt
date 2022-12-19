### 解题思路
这题在业务系统中有个应用，就是比较两个时间段是否有重合点。
用于排班检索等业务。

时间段A有两个点 a1、a2。时间段B也有两个点 b1、b2。
若是这两个时间段有重合点则必定满足 a1<b2 且 b1<a2。

放在这里也是一样，横坐标判断，纵坐标判断。
就可以判断是否重合。

### 代码

```csharp
public class Solution {
    public bool IsRectangleOverlap(int[] rec1, int[] rec2)
        {

            if (rec2[2] > rec1[0] && rec2[0] < rec1[2])
            {
                if (rec2[3] > rec1[1] && rec2[1] < rec1[3])
                {
                    return true;
                }
            }

            return false;
        }
    }
```