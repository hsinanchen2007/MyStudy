### 解题思路
暴力求解，前缀和和单调栈思路好难理解

### 代码

```java
class Solution {
     public int longestWPI(int[] hours) {
        //遍历一遍数组将数据变成1或-1
        for (int i = 0; i < hours.length; i++) {
            if (hours[i] > 8){
                hours[i] = 1;
            }else {
                hours[i] = -1;
            }
        }

        int sum, dis, res = 0;
        for (int i = 0; i < hours.length; i++) {
            sum = 0;
            dis = 0;
            for (int j = i; j < hours.length; j++) {
                sum+=hours[j];
                if (sum > 0){
                    dis = j - i + 1;
                    res = Math.max(dis, res);
                }
            }
        }
        return res;
    }
}
```