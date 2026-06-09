### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int getDistance(int []a,int []b)
    {
        return Math.abs(a[0]-b[0])+Math.abs(a[1]-b[1]);
    }
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int ans=Integer.MAX_VALUE;
        int sum_dis=0;
        for(int [] nut:nuts)
        {
            sum_dis+=getDistance(nut,tree)*2;
        }
        for(int [] first_nut:nuts)   //时间复杂度为n，依次遍历
        {
            int cur=sum_dis-getDistance(first_nut,tree)+getDistance(squirrel,first_nut);
            ans=Math.min(ans,cur);
        }
        return ans;
    }
}
```