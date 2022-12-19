![2020010701.PNG](https://pic.leetcode-cn.com/f0f457d661fef2d2dd8cd0f7b9aff0a69f2321893f629062f594d35f742d9579-2020010701.PNG)
### 解题思路
设置双指针为:leftIndex=0,rightIndex=n-1,从两端开始添加相反数(开始添加的数为n,之后n--)
### 代码
```java
class Solution {
    public int[] sumZero(int n) {
    	int[] out = new int[n];
    	int leftIndex = 0;
    	int rightIndex = n-1;
    	while(leftIndex < rightIndex) {
    		out[leftIndex] = -n;
    		out[rightIndex] = n;
    		leftIndex++;
    		rightIndex--;
    		n--;
    	}
   		return out;
    }
}
```