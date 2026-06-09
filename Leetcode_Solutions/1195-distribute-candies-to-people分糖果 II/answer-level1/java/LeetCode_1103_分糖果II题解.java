### 解题思路

从cnt = 1开始给第一个孩子发糖，之后cnt+=1表示每次都比之前的多1个糖。之后把数组转为循环数组，再判断一下还剩多少糖，如果不够，就把剩下的全给了即可。

### 优化

可以判断从哪个孩子开始糖不够了在取最小值，不用每个循环都判断。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if (num_people == 0) return null;

        int[] arr = new int[num_people];

        for (int i = 1; candies >= 0; i++) {

            arr[(i - 1) % num_people] += (Math.min(candies, i));
            candies -= i;

        }

        return arr;
    }
}


```