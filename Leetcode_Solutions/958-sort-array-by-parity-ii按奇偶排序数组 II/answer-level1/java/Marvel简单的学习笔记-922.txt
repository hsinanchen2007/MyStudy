### 解题思路
采用双指针的方法，不需要额外的内存空间。定义两个指针i、j，分别指示偶数和奇数，i从下标0开始，j从下标1开始，遍历数组。若i指向的元素是偶数，将i向后移两位；若j所指的元素是奇数，同样向后移两位。直到i指向奇数，j指向偶数，将两者交换，继续向后遍历，直到数组边界。
时间复杂度：O(n)。需要遍历数组一次。
空间复杂度：O(1)。不需要额外空间。

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int i=0,j=1;
        while(i<A.length)
        {
            while(i<A.length && A[i]%2==0)
            {
                i += 2;
            }
            while(j<A.length && A[j]%2==1)
            {
                j += 2;
            }
            if(i>=A.length) break;
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
        return A;
    }
}
```