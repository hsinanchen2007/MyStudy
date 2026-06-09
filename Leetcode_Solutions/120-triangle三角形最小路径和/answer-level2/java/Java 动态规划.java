### 解题思路
这道题可以用动态规划解决，对于triangle[i][j]来说，如果它是答案中的一个点，那么它一定要从下一行的相邻两个元素中选较小的一个，保证这条路径是最小的。

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()==0 || triangle.get(0).size()==0){
            return 0;
        }
        int l = triangle.size();
        // System.out.println(l);
        int[] res = new int[l+1];
        for(int row = l-1;row>=0;row--){
            List<Integer> data = triangle.get(row);
            for(int j = 0;j<=row;j++){
                res[j] = Math.min(res[j],res[j+1])+data.get(j);
            }
        }
        return res[0];
    }

}
```