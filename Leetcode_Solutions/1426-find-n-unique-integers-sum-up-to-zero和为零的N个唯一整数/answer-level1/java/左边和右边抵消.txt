### 解题思路
此处撰写解题思路
让左边和右边的数抵消，当为n为奇数是中间默认为0
时间复杂度：O(n/2)，取决于n的大小
空间复杂度：O(4)
### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int [] a=new int[n];
        int l=0,r=n-1;
        int i=1;
        while(l<r){
            a[l++]=i;
            a[r--]=-i;
            i++;
        }
        return a;
    }
}
```