### 解题思路
想了一下午才想清楚新数组下标迭代的解决方法，设置变量存一下啊！！！
我肯定是完了。

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
    	int len=0;
    	for (int i = 0; i < nums.length; i+=2) {
    		len+=nums[i];
		}
    	int[]arr=new int[len];
    	int index=0;      //设置arr数组的下标用于下标迭代！！！   
    	for (int i = 0; i < nums.length; i+=2) {
			for (int j = 0; j < nums[i]; j++) {
				arr[index++]=nums[i+1];
			}
		}
    	return arr;
    }
}
```