### 解题思路
1.一开始的思路是，从1开始，一个一个算，如果取模不为0，则跳过。如果当前组合的差值小于前一个的差值，就覆盖一下。
2. 第一个代码69ms，就觉得太久了，思考了一下。 既然是求L-W的差值最小，那最小肯定是相等的时候，直接从area开平方的数开始算起，如果刚好能开平方，那直接就返回。  而且也是判断如果L-W差值为0，那么就直接返回结果。 执行用时一下就降下来了  1ms。

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
         if(area == 0)
            return new int[] {};
        int w = 1, l = area;
        for(int i = (int)Math.sqrt(area); i > 0; i--){
            if(area % i != 0)
                continue;
            else {
                if(i > (area / i))
                    break;
                int tmpW = i;
                int tmpL = area / i;
                if(tmpW - tmpL == 0)
                    return new int[] {tmpL, tmpW};
                if( (tmpL - tmpW) < (l - w)){
                    w = tmpW;
                    l = tmpL;
                }
            }
        }
        return new int[] {l ,w};
    }
}
```