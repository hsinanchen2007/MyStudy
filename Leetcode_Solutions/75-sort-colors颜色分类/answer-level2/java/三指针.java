![image.png](https://pic.leetcode-cn.com/75ca46a261a2e64615c16cd5008ba60342b79f56e51fcb4464eedda78b1d991e-image.png)
第一次写题解，如果有错或者有什么建议，欢迎大家多多指教！
我的方法是用三个指针给这个数组进行分区，过程如下：
1. 三个指针i = 0, j = 0, k = nums.length - 1
2. 定义(, i)区域内都为0， [i, j]区域内都为1，(j, k]内未知，(k, )为2
3. 主要是根据条件判断移动j指针，循环条件是j<=k
    - 如果nums[j] == 0，交换i和j的数字，并且移动指针：i++,j++
    - 如果nums[j] == 1，只移动j++
    - 如果nums[j] == 2，交换j和k的数字，移动指针k--

代码如下：
```
public class Solution {

    public void sortColors(int[] nums) {
    	if(nums.length == 0 || nums.length == 1) {
    		return;
    	}
    	int n = nums.length;
    	int i = 0;
    	int j = 0;
    	int k = n - 1;
    	
    	while(j <= k) {
    		if(nums[j] == 0) {
    			//和i交换
    			swap(j, i, nums);
    			i++;
    			j++;
    		}else if(nums[j] == 2) {
                	//和k交换
    			swap(j, k, nums);
    			k--;
    		}else {
			//不交换，只移动j
    			j++;
    		}
    	}
    }
	private void swap(int i, int j, int[] nums) {
    	int temp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = temp;
	}
}
```
