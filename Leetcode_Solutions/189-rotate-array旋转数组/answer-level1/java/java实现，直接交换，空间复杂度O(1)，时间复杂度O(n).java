直接交换，空间复杂度O(1)，时间复杂度O(n)
循环替换
* 例如
     * 1,2,3,4,5 k=3
     * 结果:
     * 3,4,5,1,2
     * 原数组:下面的数字均为索引，超出索引就减掉长度，交换次数为数组的长度
     * 0和0+3交换，
     * 3和3+3-5=1交换
     * 1和1+3交换
     * 4和4+3-5=2交换
     * 2和2+3-5=0交换
     * 需要注意的是，交换时只能改变前一个索引index的值，真正被换到index+k的值需要
     * 用一个整数cache保存下来
     * 
     * 出现的问题，上述这种顺序交换，如果nums的长度为偶数
     * 会出现环，这时候需要判断，如果新的index是起点，那么就要改变index++
```
class Solution {
   public void rotate(int[] nums, int k) {
    	//如果移动次数等于了nums.length，相当于回到原地
    	//所以这里取余数
    	k = k % nums.length;
          if(k == 0 || nums.length == 1)
    		return;
        //直接交换位置，交换次数为数组的长度
    	int index = 0;
    	int cache = nums[index];
    	int start = 0;
    	for(int i = 0; i < nums.length; i++) {
    		int index2 = index + k;
    		index2 = index2 >= nums.length ? index2- nums.length:index2;
    		//交换
    		int tmp = nums[index2];
    		nums[index2] = cache;
    		cache = tmp;
    		index = index2;
    		if(index == start) {
    			index++;
    			start = index;
    			cache= nums[index];
    		}
    	}
    }
}
```