    本来今天想刷一道“栈”标签的题目，但是想不出如何使用栈来解这道题，只好在暴力解法上优化一下了。
    因为题目说数组的元素是唯一的，所以可以把nums2的元素当作key存入HashMap中，利用HashMap的get()方法原理，快速找到nums1某个元素在nums2中的位置。（最近才学数据结构，各位大神可以帮我看一下我这种解法的时间复杂度和空间复杂度吗？）
![微信图片_20200402190752.png](https://pic.leetcode-cn.com/b5ac3509a3be3a69bbdee0c14660984443fdad271d11f709b22cda17fff820b9-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200402190752.png)

```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] results = new int[nums1.length];
		int index = 0;
		int j=0;
		
		Map<Integer,Integer> map = new HashMap<>();
		for(int i = 0;i<nums2.length;i++){
			map.put(nums2[i],i);
		}
		
		for(int i=0;i<nums1.length;i++){
			int inDex = map.get(nums1[i]);  //找出nums1元素在nums2中的位置，然后向右方向判断
			for(j=inDex+1;j<nums2.length;j++){
				if(nums1[i]<nums2[j]){
					results[index++]=nums2[j];
					break;
				}
			}
			if(j>=nums2.length) results[index++]=-1;
		}
		return results;
    }
}
```
