### 解题思路
此处撰写解题思路
先遍历一遍找到所有不同的数，保存在一个list中。然后二重循环，找到出现次数最多的数即可。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
		int len = nums.length;
		ArrayList<Integer> list = new ArrayList<>();
		int index = 0;
		for (int i=0; i<len; i++) {
			if (!list.contains(nums[i])) list.add(nums[i]);
		}
		int size = list.size();
		int record = 0;
		int ans = 0;
		for (int i=0; i<size; i++) {
			int count = 0;
			for (int j=0; j<len; j++) {
				if (nums[j] == list.get(i)) count++;
			}
			if (count>record) {
				record = count;
				index = i;
				ans = list.get(i);
			}
		}
		return ans;

    }
}
```