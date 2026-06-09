### 解题思路
比较每两两元素的组合，组合得到的数越小，越是将其放在前面

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
    //得到一个String类型数组，形似nums
	String[] strNumbers = new String[nums.length];
	for(int i = 0; i < nums.length; i++) {
		strNumbers[i] = String.valueOf(nums[i]);
	}
	//排序。（传入一个比较器对象）
	Arrays.sort(strNumbers, new Comparator<String>() {
		@Override
		public int compare(String o1, String o2) {
			return (o1 + o2).compareTo(o2 + o1);//升序
		}
	});
	//将该字符串数组元素拼接起来
	StringBuilder sb = new StringBuilder();
	for(int i = 0; i < strNumbers.length; i++) {
		sb.append(strNumbers[i]);
	}
	return sb.toString();
    }
}
```