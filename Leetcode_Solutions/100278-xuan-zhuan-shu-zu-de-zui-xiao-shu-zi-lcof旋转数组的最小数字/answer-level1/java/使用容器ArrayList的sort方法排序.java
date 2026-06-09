### 解题思路
遍历 numbers中的数据，添加到ArrayList中，sort方法排序
return arr中第一个数，即为最小数

### 代码

```java
class Solution {
   public int minArray(int[] numbers) {
        int min =0;
       ArrayList<Integer> arr = new ArrayList<Integer>();
       for (Integer integer : numbers) {
		arr.add(integer);
    	   
	}
    arr.sort(null);
	
	return  arr.get(0);
    }
}
```