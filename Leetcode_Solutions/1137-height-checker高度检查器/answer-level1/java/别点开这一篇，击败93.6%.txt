### 解题思路
分析了一下是比较与排序后，元素不一致的数量
于是偷懒用了sort

官方用技计数的方式也很有趣，因为不需要真的知道排序后是什么样子。

### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {

        int[] temp =  heights.clone();
        Arrays.sort(heights);
        int sum = 0;

        for(int i = 0; i < heights.length; i++){
            if(temp[i] != heights[i]) sum++;
        }
        return sum;
    }
}
```

PS：最近做起了审计的工作，作为甲方给乙方尾款，给钱之前需要再核查项目的情况。