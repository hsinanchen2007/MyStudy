### 解题思路
此处撰写解题思路
采用二分法思想提高算法效率。由于硬币排列是依次递增的，所以利用n*(n-1)/2来计算当前如果有mid行则一共会有多少个硬币，根据硬币总数与其值得比较，来改变l与h的值，最后如果不能找到一个mid值使mid(mid-1)/2刚好等于n,那么就在退出循环使返回h.

### 代码
```java
class Solution {
    public int arrangeCoins(int n) {
        int l=0,h=n;
        while(l<=h){
            int mid=l+(h-l)/2;
            long x=mid*(mid+1L)/2;
            if(x==n) return mid;
            if(x<n) l=mid+1;
            else h=mid-1;
        }
        return h;
    }
}
```
