### 解题思路
利用桶式排序的思路，使用一个数组count[]大小为1001，表示1001个桶，每个桶存储的数为和下标相等的数的个数。遍历arr2，将在arr2中的桶中的数输出在arr1中，然后在遍历所有桶，将不在arr2中的桶中的数继续往后输出在arr1中。
时间复杂度：O(M+N+R)。M为arr1的长度，N为arr2的长度，R为桶的个数。相当于O(N)，线性级别。
空间复杂度：O(R)。R为桶的个数，若R为常数，则相当于O(1)。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] count=new int[1001];
        for(int i : arr1)
            count[i]++;
        int i=0;
        for(int j : arr2) 
        {
            while(count[j]>0)
            {
                arr1[i++]=j;
                count[j]--;
            }
        }
        for(int j=0;j<=1000;j++)
        {
            while(count[j]>0)
            {
                arr1[i++]=j;
                count[j]--;
            }
        }
        return arr1;
    }
}
```