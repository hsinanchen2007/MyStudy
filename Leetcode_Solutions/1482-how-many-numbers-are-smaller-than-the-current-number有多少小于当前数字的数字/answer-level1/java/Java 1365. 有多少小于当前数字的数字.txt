### 解题思路
1. 先定义一个数组`resultArr`用于接受最后的结果；
2. 进入第一次遍历，同时定义一个变量`count`用于计数比当前数要小的数的个数；
3. 进入第二次遍历，比较除当前数之外其他元素与当前数的大小，比当前数小的，`count`加`1`；
4. 完成第二次遍历后将每次的计数结果`count`存入数组`resultArr`;
5. 完成第一次遍历后跳出循环，返回最终结果`resultArr`；
### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] resultArr = new int[nums.length];
		for (int i = 0; i < nums.length; i++){
			int count = 0;
			for (int j = 0; j < nums.length; j++){
				if (i != j){
					if (nums[i] > nums[j]){
						count++;
					}
				}
			}
			resultArr[i] = count;
		}

		return resultArr;
    }
}
```