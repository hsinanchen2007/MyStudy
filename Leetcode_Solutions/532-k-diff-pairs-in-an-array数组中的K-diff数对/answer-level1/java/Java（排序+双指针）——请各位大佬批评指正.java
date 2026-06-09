执行结果：通过
显示详情 
执行用时 :8 ms, 在所有 Java 提交中击败了87.30%的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了5.21%的用户
### 解题思路
1、分类讨论

2、分类讨论中：k == 0时,该问题转换为：统计数组中至少出现2次的元素个数;k > 0时,遍历数组

3、k > 0时,遍历数组：该步骤在实现代码时需注意break和continue的使用

  3.1 `if(i+1<=nums.length-2 && nums[i] == nums[i+1]) continue;`以及`if(j+1<=nums.length-1 && nums[j] == nums[j+1]) continue;`，两者都是为了去重

  3.2 `nums[j]-nums[i] == k`以及`nums[j]-nums[i] > k`，两者都应在语句块中使用break;（这是因为数组已经是从小到大按顺序排列的，内层循环只会不断增加差值，所以应该退出循环体）
### 代码

```java
public static int findPairs1(int[] nums, int k) {
	if(nums.length == 0 || nums.length == 1 || k < 0)
		return 0;
	Arrays.sort(nums);
	if(k == 0) {
	//该子问题转换为：确定数组中至少出现2次的元素个数
		int num = 0;
		Map<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i <= nums.length-1; i++) {
			if(!map.containsKey(nums[i])) {
				map.put(nums[i], 1);
			}else if(map.containsKey(nums[i]) && map.get(nums[i])==1) {
				num++;
				map.replace(nums[i], 1, 2);
			}
		}
		return num;
	}
    int num = 0;
    for(int i = 0; i <= nums.length-2; i++) {
    	if(i+1<=nums.length-2 && nums[i] == nums[i+1]) {
    		continue;
    	}
    	for(int j = i+1; j <= nums.length-1; j++) {
    		if(j+1<=nums.length-1 && nums[j] == nums[j+1]) {
        		continue;
        	}
    		if(nums[j]-nums[i] == k) {
    			num++;
    			break;
    		}else if(nums[j]-nums[i] > k) {
    			break;
    		}else {
    			continue;
    		}
    	}
    }
    return num;

}
```