### 解题思路
思路就在代码里了

### 代码

```java
class Solution {
   public int[] maxNumber(int[] nums1, int[] nums2, int k) {
		ArrayList<int[]> list = new ArrayList<>();
		for (int i = 0; i <= k; i++) {
			if (i > nums1.length || k - i > nums2.length) {
				continue;
			}
			list.add(merge(func(nums1, i), func(nums2, k - i)));
		}
		list.sort(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				for (int i = 0; i < o1.length; i++) {
					if (o1[i] != o2[i]) {
						return o2[i] - o1[i];
					}
				}
				return 0;
			}
		});

		return list.get(0);
	}

	int[] merge(Stack<Integer> s1, Stack<Integer> s2) {
		int[] ans = new int[s1.size() + s2.size()];
		int i = 0;
		int x = 0, y = 0;
		while (true) {
			if (s1.size() == x || s2.size() == y) {
				break;
			}
			if (s1.get(x) > s2.get(y)) {
				ans[i++] = s1.get(x);
				x++;
			} else if (s1.get(x) < s2.get(y)) {

				ans[i++] = s2.get(y);
				y++;
			} else {

				int j = x;
				int k = y;
				while (j<s1.size()&&k<s2.size()&&s1.get(j) == s2.get(k)) {
					j++;
					k++;
				}
				if (k==s2.size()||j<s1.size()&&s1.get(j) > s2.get(k)) {
					ans[i++] = s1.get(x);
					x++;
				}else{
					ans[i++]=s2.get(y);
					y++;
				}
			}
		}
        while(x<s1.size()){
			ans[i++]=s1.get(x++);
        }
        while(y<s2.size()){
			ans[i++]=s2.get(y++);
        }
		return ans;
	}

	Stack<Integer> func(int[] nums, int k) {
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < nums.length; i++) {

			while (stack.size() + nums.length - i > k && !stack.isEmpty() && stack.peek() < nums[i]) {
				stack.pop();
			}
			if (stack.size() < k) {
				stack.push(nums[i]);
			}
		}
		return stack;
	}
}
```