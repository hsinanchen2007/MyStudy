### 解题思路
遍历一次，每个循环在之前所有子集的基础上增添一个新的数

### 代码

```java
import java.util.*;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> res = new ArrayList<>();
		List<Integer> tmp0 = new ArrayList<>();
		int oldSize;

		Arrays.sort(nums);
		res.add(new ArrayList<Integer>(tmp0));

		for(int i=0;i<nums.length;i++){
			oldSize = res.size();
			for(int j=0;j<oldSize;j++){
				List<Integer> tmp1 = new ArrayList<>(res.get(j));
				tmp1.add(nums[i]);
				res.add(new ArrayList<Integer>(tmp1));
			}
		}

		return res;
    }
}
```