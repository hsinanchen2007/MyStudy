### 解题思路
先数组排序，在求出相同数的数量，该数量跟前一个求出的数量求最大公约数，若该公约数小于2，return false
若大于2，继续重复先前的工作，下面代码3ms，击败84%
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] dock) {
        if (dock.length < 2)
			return false;
		Arrays.sort(dock);
		int num1 = 0, num2;
		for (int i = 0; i < dock.length;) {
			int temp = dock[i];
			int j = i, num = 0;
			while (j < dock.length && temp == dock[j]) {
				num++;
				j++;
			}
			if (num < 2)
				return false;
			if (num1 != 0) {
				if (minCommonMultiple(num1, num) < 2)
					return false;
			}
			num1 = num;
			i = j;
		}
		return true;
    }

    public static int minCommonMultiple(int num1, int num2) {
		if (num1 < num2) {
			int temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int num = num1 * num2;
		while (num1 % num2 != 0) {
			int temp = num1 % num2;
			num1 = num2;
			num2 = temp;
		}
		return num2;
	}
}
```