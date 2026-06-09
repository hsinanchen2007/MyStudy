### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int len=coordinates.length;
        if(len==2)  return true;
        int x0=coordinates[0][0], x1=coordinates[1][0];
        int y0=coordinates[0][1], y1=coordinates[1][1];
        for(int i=2;i<len;i++)
        {
            int a=(y1-y0)*(coordinates[i][0]-x0);
            int b=(x1-x0)*(coordinates[i][1]-y0);
            if(a!=b)
                return false;
        }
        return true;
    }
}
```