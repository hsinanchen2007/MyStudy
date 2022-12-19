### 解题思路
这里我们只要界定了0和2的边界，那么1也就自然排序好了。
1、将0的边界指向数组第一个元素
2、将2的边界指向数组的最后一个元素
3、从头到尾开始遍历数组

- 如果当前值是0，就和0边界的元素交换
- 如果当前值是2，就和2边界的元素交换
- 如果当前值是1，就检索下一个元素
- 如果处理完后当前检索位置大于等于p2的位置那么就退出程序

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
    	int p0 = 0, p2 = nums.length - 1;
    	for(int i = 0; i < nums.length; i++)
    	{	
    		if(nums[i] == 0)
    		{
    			swap(nums,i,p0);//向前交换
    			p0++;
    		}else if(nums[i] == 2)
    		{
    			swap(nums,i--,p2);//向后交换
    			p2--;
    		}
    		if(i >= p2)
    			break;
    	}
    }
    
    private void swap(int[] nums,int a,int b)
    {
        if(a == b || nums[a] == nums[b])
    		return;
    	nums[a] = nums[a] + nums[b];
    	nums[b] = nums[a] - nums[b];
    	nums[a] = nums[a] - nums[b];
    	
    }
}
```
这里有点点细节需要考虑：
假如初始化是：{1，2，0}，p0 = 0，p2 = 2, i = 0
第一次交换后是：{1，2，0}，p0 = 0, p2 = 2, i = 1，
第二次交换后是：{1，0，2}，p0 = 0, p2 = 1, i = 2，这时候 i >= p2理应退出遍历，但是我们发现0其实我们是没有处理过的，它是被交换到数组中的位置1处的，所以这个时候我们不能将i++，但是我写的for循环里面写了++，所以在向后交换的时候加上了i–来抵消i++