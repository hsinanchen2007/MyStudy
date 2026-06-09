![2020010801.PNG](https://pic.leetcode-cn.com/4363fcfb9712b08af14e76b8b8547d058c5ffccc0098a7a8622973212bbd6d30-2020010801.PNG)
### 解题思路
双指针:左指针(leftIndex,初始为0)从左边开始放置偶数,右指针(初始为A.length-1)从最右边开始放置奇数
最后，遍历一遍数组即可
### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] out = new int[A.length];
    	int rightIndex = A.length-1;
    	int leftIndex = 0;
    	for(int i=0;i<A.length;i++) {
    		if(A[i]%2==0) {
    			out[leftIndex]=A[i];
    			leftIndex++;
    		}else {
    			out[rightIndex]=A[i];
    			rightIndex--;
    		}
    	}
        return out;
    }
}
```