### 解题思路
1. 判断c是否为非负整数，若是，则直接返回false
2. 利用Math包中sqrt()方法求出小于c的平方根的最大整数作为右指针，同时设置左指针从0开始；
3. 开始循环，若左指针小于右指针，判断两指针之和与c的大小；
	- 若和等于c，返回false；
	- 若和小于c，左指针加1；
	- 若和大于c，右指针减1；
4. 默认返回false

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        // c为非负整数，则若c为负直接返回false
		if (c < 0){
			return false;
		}
		// 取c的平方根，并将其强制转换为不大于平方根值的最大整数
		int flag = (int) Math.sqrt(c);
		int i = 0;
		while (i <= flag){
			if ((i*i + flag*flag) == c){
				return  true;
			} else if ((i * i + flag * flag) < c) {
				i++;
			}else {
				flag--;
			}
		}
		return false;
    }
}
```