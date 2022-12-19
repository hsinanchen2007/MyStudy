### 解题思路
此处撰写解题思路
因为是一个有序数组,表明相同的数会连续出现,
所以,只需遍历一遍数组，在遍历过程中,设置三个记录器:count记录连续出现数字的次数(每当出现不同数字是,count置为0),max记录当前出现相同数字最多的次数,
value记录当前出现次数最多的值.
遍历一遍后,返回value值即可.

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        int count = 0;
    	int max = 0;
    	int value = arr[0];
    	int i=1;
    	while(i<arr.length) {
    		if(arr[i]==arr[i-1]) {
    			count ++;
    			i++;
    		}else if(arr[i]!=arr[i-1]) {
    			if(count>max) {
    				max = count;
    				value = arr[i-1];
    			}
    			count =0;
    			i++;
    		}
    		
    	}
    	if(count>max) {
    		value = arr[i-1];
    	}
    	return value;
    }
}
```