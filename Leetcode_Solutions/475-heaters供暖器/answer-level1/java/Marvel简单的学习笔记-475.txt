### 双指针
双指针的思想就是用两个指针分别扫描houses[]和heaters[]，计算每座房子离供暖器的最近距离，这些距离的最大值就是答案半径。
需要将两个数组排序。
时间复杂度：O(nlogn)。排序。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int i=0,j=0;
        int dis,r=0;
        while(i<houses.length)
        {
            if(houses[i]<=heaters[j])    dis=heaters[j]-houses[i];
            else if(houses[i]>heaters[j] && j<heaters.length-1)
            {
                dis=Math.min(houses[i]-heaters[j],heaters[j+1]-houses[i]);
                if(heaters[j+1]<houses[i])  
                {
                    j++;
                    i--;
                }
            }
            else    dis=houses[i]-heaters[j];
            r=Math.max(dis,r);
            i++;
        }
        return r;
    }
}
```
### 二分法
用二分法查找每座房子在供暖器数组中的位置，计算其到供暖器的最近距离。重复该过程得到所有房子离供暖器的最近距离后，取这些距离中的最大值就是答案半径。二分查找需要数组有序，故需要将heaters[]排序，houses[]则不用。
时间复杂度：O(nlogn)。用于排序。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    private int binarySearch(int k,int[] a) {
        int lo=0,hi=a.length;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(a[mid]>=k)   hi=mid;
            else            lo=mid+1; 
        }
        return lo;
    }
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int dis=0,r=0;
        for(int i=0;i<houses.length;i++)
        {
            int pos=binarySearch(houses[i],heaters);
            if(pos==0)  dis=heaters[0]-houses[i];
            else if(pos<heaters.length)
                dis=Math.min(heaters[pos]-houses[i],houses[i]-heaters[pos-1]);
            else        dis=houses[i]-heaters[pos-1];
            r=Math.max(dis,r);
        }
        return r;
    }
}
```