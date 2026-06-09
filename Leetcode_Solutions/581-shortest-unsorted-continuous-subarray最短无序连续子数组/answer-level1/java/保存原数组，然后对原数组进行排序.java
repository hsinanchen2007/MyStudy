### 解题思路
对原数组排序后，与未排序的数组进行比较，计算最短子串长度

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if(nums == null || nums.length == 0)
            return 0;
        if(nums.length == 1)
            return 0;
        if(nums.length == 2){
            if(nums[0] <= nums[1])
                return 0;
            else 
                return 2;
        }
        int[] b = new int[nums.length];
		int coun = 0;
		int i,j,h = -1,l = -1;
		for(i = 0;i < nums.length;i++)
			b[i] = nums[i];
		Arrays.sort(nums);
        i = 0;
        j = nums.length - 1;
        while(i < j) {
			if(nums[i] == b[i] && nums[j] == b[j]) {
				
				i++;
				j--;
				continue;
			}
			if(nums[i] != b[i]  && nums[j] == b[j]){
				
				if(h != -1 && l != -1) {
					coun = h - l + 1;
					break;
				}
				if(l == -1)
					l = i;
				j--;
				continue;
				
			}
			if(nums[j] != b[j]  && nums[i] == b[i]) {
				if(h != -1 && l != -1) {
					coun = h - l + 1;
					break;
				}
				if(h == -1)
					h = j;
				
				i++;
				System.out.println(i);
				continue;
			}
			if (nums[j] != b[j] && nums[i] != b[i]) {
				
				if(h != -1 && l != -1) {
					coun = h - l + 1;
					break;
				}
				if(l == -1) {
					
					l = i;
				}
				if(h == -1) {
					h = j;
				}
				if(h != -1 && l != -1) {
					coun = h - l + 1;
					break;
				}
				continue;
			}
		}
        return coun;
    }
}
```