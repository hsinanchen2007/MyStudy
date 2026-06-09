### 解题思路
	第一遍（超时）：三层for循环，对两层List内容都进行排序，主要复习List的用法。
	第二遍（想办法缩减时间）：改进for循环，先对nums排序，然后一层for循环遍历，for循环中分别从首和尾同时推进，遍历出满足条件的结果，存入list中，因为已经对nums排过序了，后续的操作都是自动有序的，所以不需要再对list排序。但是需要对list查重，浪费时间，可以再存入list前就做完查重。具体方法如下，注意对三个下标的查重判断步骤和位置有差别。

### 代码

```java
class Solution {
    public static List<List<Integer>> threeSum(int[] nums) {
		Arrays.sort(nums);
		//System.out.println(nums.toString());
        List<List<Integer>> LL=new ArrayList<>();
		for(int i=0;i<nums.length;i++){
			if(i>0&&nums[i]==nums[i-1])
				continue;
			for(int j=i+1,k=nums.length-1;j<k;){
				int sum=nums[i]+nums[j]+nums[k];
				if(sum==0){		
                    while(j<k&&nums[j]==nums[j+1])
                        j++;
                    while(k>j&&nums[k]==nums[k-1])
                        k--;				
					LL.add(Arrays.asList(nums[i],nums[j],nums[k]));
					j++;
					k--;
				}
				if(sum<0)
					j++;
				if(sum>0)
					k--;
			}
		}
        for(List<Integer> i:LL){
            System.out.println(i);
        }
		return LL;
    }
}
```