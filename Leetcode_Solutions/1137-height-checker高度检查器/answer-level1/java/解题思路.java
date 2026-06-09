### 解题思路
1.先将数组进行小到大排序
2.将排序后的数组和原数组位置值进行比较，值不想等则加1
3.返回最后结果

### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] sortArray = Arrays.copyOf(heights,heights.length);
        Arrays.sort(sortArray);
        int count = 0;
        for(int i = 0;i < heights.length;i++){
            if(heights[i] != sortArray[i]){
                count++;
            }
        }
        return count;
    }
}
```