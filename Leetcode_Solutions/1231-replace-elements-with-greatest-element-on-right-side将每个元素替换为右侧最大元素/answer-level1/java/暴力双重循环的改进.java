![2020010801.PNG](https://pic.leetcode-cn.com/d508b6ee9ab36c2f42112631d866ae7929d9b75341eb801e121c05ac8939a6e2-2020010801.PNG)

### 解题思路
双重循环---1)外层循环遍历数组arr,内存循环寻找当前位置右侧数组的最大值,并记录该最大值的索引为(index)
2)把index之前的数组元素替换为arr[index],并把arr[index]置为0;
3)外层循环的索引i每次增加(index-i)

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
    	int i =0;
    	int index = 0;
    	while(i<arr.length-1) {
    		int j=i+1;
    		index = j;
    		int max=arr[j];
    		while(j<arr.length) {
    			if(max<arr[j]) {
    				max = arr[j];
    				index = j;
    			}
    			j++;
    		}
    		for(int k =i;k<index;k++) {
    			arr[k] = arr[index];
    		}
    		arr[index] = 0;
    		i += (index-i);
    	}
    	arr[arr.length-1] = -1;
    	return arr;
    }
}
```