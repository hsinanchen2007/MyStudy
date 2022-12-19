解题思路：

1. 记录开头连续0个数count1;
2. 记录结尾连续0个数count2;
3. 计算中间连续0个数的最大值countmax;
4. count1、count2、(countmax+1)/2 三者中最大值即为结果.

虽然代码中分三段循环，实际合起来只有一次完整循环，时间复杂度为O(n)

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int count1 = 0;
        int count2 = 0;
        int i = 0, j = seats.length-1;
        // count1记录开头连续0的个数
        while(seats[i] == 0){
            count1++;
            i++;
        }
        // count2记录结尾连续0的个数
        while(seats[j] == 0){
            count2++;
            j--;
        }
        // countmax记录从第一个1到最后一个1之间，连续0的最大值
        int countmid = 0, countmax = 0;
        for(int k = i+1; k <= j; k++){
            if(seats[k] == 0){
                countmid++;
            }else{
                countmax = Math.max(countmax, countmid);
                countmid = 0;
            }
        }
        // 返回count1, count2, (countmax+1)/2三者中最大值
        return Math.max(Math.max(count1, count2), (countmax+1)/2);
    }
}
```