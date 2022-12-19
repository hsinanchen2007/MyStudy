### 解题思路
可暴力可散列，但由于数组是有序的，若要有效利用该条件，则双指针更佳。
定义两个指针i、j分别指示数组首尾两个元素，若两元素之和过大，j--；若两元素之和过小，i++；若两元素之和等于给定值，返回答案。
时间复杂度：O(n)。循环结束标志为i==j，则最坏情况下需要遍历数组一次，n为数组长度。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers==null)   return null;
        int i=0,j=numbers.length-1;
        while(i<j)
        {
            int sum=numbers[i]+numbers[j];
            if(sum>target)          j--;
            else if(sum<target)     i++;
            else
            {
                int[] output=new int[2];
                output[0]=i+1;
                output[1]=j+1;
                return output;
            }
        }
        return null;
    }
}
```