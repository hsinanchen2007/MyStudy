### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int sum=0;
        for(int i=0;i<costs.length;i++)
            sum+=costs[i][0];
        int [] a=new int[costs.length];
        for(int i=0;i<costs.length;i++)
            a[i]=costs[i][0]-costs[i][1];
        Arrays.sort(a);
        for(int i=a.length/2;i<a.length;i++)
            sum-=a[i];
        return sum;
    }
}
```