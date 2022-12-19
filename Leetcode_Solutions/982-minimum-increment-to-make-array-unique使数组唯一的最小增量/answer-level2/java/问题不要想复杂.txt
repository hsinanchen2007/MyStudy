### 解题思路
1.将数组进行排序，便于后面的比较操作。
2.开始利用步骤1中的有序排出无重复数字的数组，这个数组我们只需要记录末位数(用end代替)即可，不需要记录整个数组。
3.将有序数组的第i位于无重复数组的end比较。
	若大于末位数字end，则将end=A[i];
	若小于末位数字end，则将end++，move操作增加（end-A[i]+1）

时间复杂度为nlog(n)。


### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length ==0){
            return 0;
        }
        int result = 0;
		   Arrays.sort(A);
		   int end = A[0];
		   for(int i =1;i<A.length;i++) {
			   if(A[i]<=end) {
				   result+=end-A[i]+1;
				   end++;
			   }else {
				   end = A[i];
			   }
		   }
		   return result;
    }
}
```