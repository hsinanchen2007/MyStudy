执行用时 :2 ms, 在所有 Java 提交中击败了92.54%的用户
内存消耗 :40.8 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
cnts[i][0]记录i这个数字在nums里面出现了多少次，cnts[i][1]记录比i这个数字小的有多少数字
第一个for计算cnts[i][0]的值
第二个for计算cnts[i][1]的值
第三个for给ans赋值nums里面出现的对应位置数字的解
### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
		int cnts[][] = new int[101][2] ;
		int ans[] = new int[nums.length] ;
		for(int i=0;i<nums.length;i++) cnts[nums[i]][0]++ ; 
		for(int i=1;i<101;i++) {
			cnts[i][1] = cnts[i-1][0] + cnts[i-1][1] ;
		}
		for(int i=0;i<nums.length;i++) {
			ans[i] = cnts[nums[i]][1] ;
		}
		return ans ;
    }
}
```