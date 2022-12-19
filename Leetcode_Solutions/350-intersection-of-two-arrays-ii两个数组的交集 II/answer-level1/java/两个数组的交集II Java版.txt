```java
public class Solution{
    /*
	 * 双指针 + 排序
	 * 	对两个数组从小到大排序
	 * 	使用两个索引i和j，依次比对数组中的元素：
	 * 		如果两个索引指向的元素相等，添加该元素到res中，i和j都后移一位；
	 * 		如果nums1[i] < nums2[j]，则i后移一位；
	 * 		如果nums1[i] > nums2[j]，则j后移一位。
	 */
	public static int[] intersectionSort(int[] nums1, int[] nums2) {
		//对两个数组排序
		Arrays.sort(nums1);
		Arrays.sort(nums2);
		
		int[] res = new int[Math.min(nums1.length, nums2.length)];
		int index = 0;
		int i = 0; //指向nums1的开头
		int j = 0; //指向nums2的开头
		while(i < nums1.length && j < nums2.length) {
			if(nums1[i] == nums2[j]) { //如果两个索引指向的元素相等
				res[index++] = nums1[i]; //添加该元素到res中，i和j都后移一位
				i++;
				j++;
			}else if(nums1[i] < nums2[j]) { //如果nums1[i] < nums2[j]，则i后移一位
				i++; 
			}else {	//如果nums1[i] > nums2[j]，则j后移一位
				j++;
			}
		}
		return Arrays.copyOf(res, index);
	}
	
	/*
	 * 使用HashMap存储
	 * 	HashMap存储nums1的元素和对应出现的次数；
	 * 	如果nums2中的元素存在于map，并且次数大于0，则表示有交集，存入res，同时map中对应的次数减一
	 */
	public static int[] intersectionHashMap(int[] nums1, int[] nums2) {
		int[] res = new int[Math.min(nums1.length, nums2.length)];
		int index = 0;
		//将nums1中的元素和对应出现的次数存入map中
		Map<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i < nums1.length; i++) {
			map.put(nums1[i], map.getOrDefault(nums1[i],0)+1);
		}
		//遍历nums2数组，如果该元素存在于map中，并且次数大于0，则表示是交集，存入res中，同时map中对应的元素次数减一
		for(int i = 0; i < nums2.length; i++) {
			if(map.containsKey(nums2[i]) && map.get(nums2[i])>0) {
				res[index++] = nums2[i];
				map.put(nums2[i], map.getOrDefault(nums2[i], 0)-1);
			}
		}
		return Arrays.copyOf(res, index);
	}
	
	/*
	 * 使用LinkedList存储其中一个数组中所有元素，包括重复的元素；
	 * 遍历另一个数组，如果当前元素存在于list中，就代表是相交，添加进res结果中，并从list中删除该元素
	 */
	public static int[] intersectionVio(int[] nums1, int[] nums2) {
		int[] res = new int[Math.min(nums1.length, nums2.length)];
		int index = 0;
		List<Integer> list = new LinkedList<>();
		//使用LinkedList存储nums1中的所有元素，包括重复的元素
		for(int i = 0; i < nums1.length;i++) {
			list.add(nums1[i]);
		}
		//遍历nums2数组，如果当前元素存在于list中，则将该元素添加进res，并在list删除
		for(int i = 0; i < nums2.length; i++) {
			if(list.contains(nums2[i])) {
				res[index++] = nums2[i];
				list.remove((Integer)nums2[i]);
			}
		}
		return Arrays.copyOf(res, index);
	}
}
```