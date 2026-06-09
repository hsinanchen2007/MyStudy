![2020010901.PNG](https://pic.leetcode-cn.com/df2432e1c1bcb579d9c7ab1c8c2e970eaee4420e4a225489c1fda33fb91e8c90-2020010901.PNG)

### 解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    	Map<Integer,Integer> map = new HashMap<>();
    	Deque<Integer> deque = new LinkedList<>();
    	for(int i=0;i<nums2.length;i++) {
    		while(!deque.isEmpty()&&deque.peek()<nums2[i]) {
    			int temp = deque.pop();
    			map.put(temp, nums2[i]);
    		}
    		deque.push(nums2[i]);
    	}
    	while(!deque.isEmpty()) {
    		int temp = deque.pop();
			map.put(temp, -1);
    	}
    	// System.out.println("map:"+map);
    	for(int k = 0;k<nums1.length;k++) {
    		nums1[k] = map.get(nums1[k]);
    	}
        return nums1;
    }
}
```