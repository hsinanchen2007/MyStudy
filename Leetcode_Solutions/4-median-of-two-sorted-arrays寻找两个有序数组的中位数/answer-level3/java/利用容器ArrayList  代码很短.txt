### 解题思路
用一个ArrayList容器，两个for循环吧数组中的数加进来，，利用Collections的sort方法对容器arr进行排序，这样arr里的就是  数组nums1和nums2  排序好的数据

### 代码

```java
class Solution {
   public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		ArrayList<Integer>arr = new ArrayList<>();	
		
		for (int i = 0; i < nums2.length; i++) {
			arr.add(nums2[i]);
		}
		for (int i = 0; i < nums1.length; i++) {
			arr.add(nums1[i]);
		
		}
		Collections.sort(arr);
		if(arr.size()%2==0)    //如果arr里数据是偶数个
		{  
			
		double sum = arr.get(arr.size()/2)+arr.get((arr.size()/2)-1);
		//获得最中间两个数据的和，并且存到double sum中，这里得先存到double中再除以二才行，不然int会舍去小数位
		double mid = sum/2;			
		return mid;						
		
		}else {   
			 //如果arr里数据是奇数个，返回数组长度/2处，索引的值   例如			  	数组中有[1,2,3]， arr.size=3， 3/2 会得出1，int自动舍弃了小数位，然后就会返回0,1,2  中间1索引的值	
			return  arr.get(arr.size()/2);  
				}
	 }	
}
```