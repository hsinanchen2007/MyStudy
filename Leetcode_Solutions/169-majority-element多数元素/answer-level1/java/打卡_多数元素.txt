### 解题思路
一开始直接想到的就是枚举每个元素,然后判断该元素在此数组中出现的次数.

通过题目知道,多数元素最多出现的次数大于n/2,所以一开始枚举的元素数量可以改为`nums.length/2+1`

在查找元素的时候发现,不用查找已经枚举过的元素,所以查找时循环的开始定为`j=i+1`

若想从循环中获取出现次数最多的数字,需要跳出循环定义两个关键变量
        记录出现次数最多的数字
        记录数字最多出现的次数

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        //定义一个记录出现次数最多的数字
        int num=0;
        //定义一个记录数字最多出现的次数
        int numMax=0;
        //多数元素出现的次数大于n/2,所以不用看后面的元素出现的次数
       for(int i=0;i<nums.length/2+1;i++){
           //记录当前元素出现的次数
			int a=1;
            //该层循环是找出该元素在数组中出现的次数
			for(int j=i+1;j<nums.length;j++){
				if(nums[i]==nums[j]){
					a++;
				}
			}
			if(numMax<a){
				numMax=a;
				num=nums[i];
			}
		}
       return num;
    }
}
```