### 解题思路
开始没有想到，参考了官方的解题思路，并对程序进行了些许的改良，我们首先重新定义一个数组，该数组存放排序后的结果，将原数组和排序后的数组进行逐个数字比较，相同继续执行，直到不相等，取出当前索引，然后从后往前遍历找到不相等的索引，二者相减再加1，就是我们需要的值。

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int i = 0;
        for(i = 0;i<nums.length;i++) {
            if(nums[i]!=arr[i]) {
                break;
            }
        }
        if(i==nums.length) {
            i=1;
        }
        int j = nums.length-1;
        for(;j>=0;j--) {
            if(nums[j]!=arr[j]) {
                break;
            }
        }
        if(j==-1) {
            j=0;
        }
        return j-i+1;

    }
}
```