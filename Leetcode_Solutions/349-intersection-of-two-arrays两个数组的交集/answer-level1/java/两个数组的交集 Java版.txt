```java
public class Solution{
	/*
	 * 使用内置函数retainAll(): oldCourses.retainAll(newCoures)
	 * 	如果存在相同元素，oldCourses中仅保留相同的元素；
	 * 	如果不存在相同元素，oldCourse会变为空。
	 */
	public static int[] intersectionInnerFunc(int[] nums1, int[] nums2) {
		HashSet<Integer> set1 = new HashSet<Integer>();
	    for (Integer n : nums1) {
	    	set1.add(n);
	    }
	    HashSet<Integer> set2 = new HashSet<Integer>();
	    for (Integer n : nums2) {
	    	set2.add(n);
	    }
	    
	    set1.retainAll(set2); //取交集方法retainAll()
	    
	    //将set里的元素赋值给数组
	    int[] res = new int[set1.size()];
	    int index = 0;
	    for(int s : set1) {
	    	res[index++] = s;
	    }
	    return res;
	}
	/*
	 * 使用Hashset存储其中一个数组中所有不重复的元素；
	 * 遍历另一个数组，如果当前元素存在于set中，就代表是相交，添加进res结果中，并从set中删除该元素
	 */
	public static int[] intersectionVio(int[] nums1, int[] nums2) {
		int[] res = new int[Math.min(nums1.length, nums2.length)];
		int index = 0;
		Set<Integer> set = new HashSet<>();
		//nums1中的元素存入set中，set存储的是无重复的元素
		for(int i = 0; i < nums1.length; i++) {
			set.add(nums1[i]);
		}
		//遍历nums2,如果当前元素存在于set中， 就将其添加到res中，并从set删去该元素
		for(int i = 0; i < nums2.length; i++) {
			if(set.contains(nums2[i])) {
				set.remove(nums2[i]);
				res[index++] = nums2[i]; 
			}
		}
		return Arrays.copyOf(res, index); //返回res中前index个元素
	}
}
```