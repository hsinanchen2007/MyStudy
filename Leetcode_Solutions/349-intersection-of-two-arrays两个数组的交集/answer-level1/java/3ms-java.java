### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	 public static int[] intersection(int[] nums1, int[] nums2)
	 {
		 //第一个思路就是利HashMap的不可重复、
		 /*
		  * 大致的思路如下：第一步将第一个数组放到一个HashMap里面
		  * 在用一个循环，依次比较第二个数组在HashMap里面是否存在，如果存在放到结果数组里面
		  * 如果不存在则不做操作
		  */
		 Map<Integer,Integer> map = new HashMap<>();
		 for(int i=0;i<nums1.length;i++)
		 {
			 map.put(nums1[i], i);
		 }
		 List<Integer> list = new ArrayList<>();
		 int count=0;
		 for(int j=0;j<nums2.length;j++)
		 {
			 if(map.containsKey(nums2[j]))
			 {
				 list.add(nums2[j]);
				 map.remove(nums2[j]);
				 count++;
			 }
		 }
		 int answer[] = new int[count];
		 for(int i=0;i<count;i++)
		 {
			 answer[i]=list.get(i);
		 }
		
		 return answer;
     }
 
}
```