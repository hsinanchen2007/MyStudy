### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
		
		if(nums==null || nums.length==0)
			return new ArrayList<List<Integer>>();
		
		result.add(new ArrayList<>());
		System.out.println(result); //[[]]
		
		for(int i = 0;i < nums.length;i ++) {
			int size = result.size();
//			System.out.println(size);
			for(int j = 0;j < size;j ++) {
				List<Integer> tmp = new ArrayList<>(result.get(j));
//				System.out.println(tmp.toString());
				tmp.add(nums[i]);
//				System.out.println(tmp);
				result.add(tmp);
//				System.out.println(result);
			}
		}
		return result;
    }
}
```
![image.png](https://pic.leetcode-cn.com/28d25ad6698f68d2935c864fbaa48232bdf3cdc9339a9fbc0943e6e1ddb5a69e-image.png)
