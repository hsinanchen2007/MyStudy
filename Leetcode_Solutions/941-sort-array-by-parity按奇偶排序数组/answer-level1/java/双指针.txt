![2020010801.PNG](https://pic.leetcode-cn.com/a6fd1f3a585de4ce90ca7230fa92dda94f35f2f4dc5deedcbd8d9ea879eb3920-2020010801.PNG)

### 解题思路
设置左指针(leftIndex,初始为0)和右指针(rightIndex,初始为A.length-1)

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        // int[] out = new int[A.length];
    	// int rightIndex = A.length-1;
    	// int leftIndex = 0;
    	// for(int i=0;i<A.length;i++) {
    	// 	if(A[i]%2==0) {
    	// 		out[leftIndex]=A[i];
    	// 		leftIndex++;
    	// 	}else {
    	// 		out[rightIndex]=A[i];
    	// 		rightIndex--;
    	// 	}
    	// }
        // return out;
        //###########
        int rightIndex = A.length-1;
    	int leftIndex = 0;
    	int temp = 0;
    	while(leftIndex<rightIndex){
    		if(A[leftIndex]%2==0) {
    			leftIndex++;
    		}else {
    			temp = A[rightIndex];
    			A[rightIndex]=A[leftIndex];
    			A[leftIndex] = temp;
    			rightIndex--;
    		}
    	}
        return A;
    }
}
```