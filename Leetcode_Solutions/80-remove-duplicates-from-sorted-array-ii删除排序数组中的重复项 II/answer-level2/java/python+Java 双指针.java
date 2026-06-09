![1571965708(1).png](https://pic.leetcode-cn.com/998671a167de0d0202519b7e6c094fef6a8222371a3c5565fbc9d98948ad5ce5-1571965708\(1\).png)
```
public class Solution {
	 public int removeDuplicates(int[] nums) {
	        int size = nums.length;
	        int i = 0;
	        int j = 1;
	        int count = 1;
	        while(j <size) {
	            if(nums[j] == nums[i]) {
	                if(count >= 2) {
	                    j = j+1;
	                }
	                else {
	                    count++;                 
	                    i++;
	                    nums[i] = nums[j];
	                    j++;
	                }
	            }
	            else {
	                i++;
	                nums[i] = nums[j];
	                count = 1;
	                j++;
	            }
	         }
	        return ++i;
	       }
	   
	 }
 

```
python
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        size = len(nums)
        i = 0
        j = 1
        count = 1
        while j <size:
            if nums[j] == nums[i]:
                if count >= 2:
                    j = j+1
                else:
                    count += 1                   
                    i +=1
                    nums[i] = nums[j]
                    j +=1
            else:
                i+=1
                nums[i] = nums[j]
                count = 1
                j+=1
        return i+1
```
