### 解题思路
    其实这个题不用查找，由于heights数组中的数据都在100之内，我们可以设计一个数组arr统计height中每一种元素有多少个。然后比较。审题：统计的是需要移动的人数，而不是次数。
### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {
        int [] arr=new int[101];
        for(int i:heights)
            arr[i]++;
        int count=0;
        for(int i=1,j=0;i<arr.length;i++)
        {
            while(arr[i]-->0)
                if(i!=heights[j++])
                    count++;
        }
        return count;
    }
}
```