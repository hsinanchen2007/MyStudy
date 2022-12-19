### 解题思路
java双百
![1583917507(1).jpg](https://pic.leetcode-cn.com/8ccbfea0af2ebb6f6f3159c74f748aa485b9e8e72160decf7bce70d843b23188-1583917507\(1\).jpg)

求出该数组的和能否分为3整份，若不能直接false，若能从数组第一个开始加，加到等于平均值，在清零，重新加，若满足次数大于即为满足的数组

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
		for(int number:A) {
			sum += number;
		}
		if(sum%3 > 0) {
			return false;
		}
		//求数组能否整份3份
		int oneThird = sum/3;
		int cardinal = 0;
		int i = 0;
		for(int number:A) {
			cardinal += number;
			if(cardinal == oneThird) {
				cardinal = 0;
				i++;
			}
		}
		return i>=3?true:false;
    }
}
```