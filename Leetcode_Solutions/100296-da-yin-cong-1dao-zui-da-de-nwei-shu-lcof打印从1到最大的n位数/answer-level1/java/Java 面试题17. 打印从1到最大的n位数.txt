### 解题思路
1. `n`其实是要打印出的数字的最大值`+1`的数中所含`0`的个数，即假设`n = 3`，那么要打印的最大数为 `999`，而`999 + 1 = 1000`则含有`3`个`0`；
2. 我们总是将最高位置为`1`，而后边的数则全为`0`，从而得到一个字符串`stringBuilder`，将其转换为`int`类型；
3. 接上一步得到的`int`类型数值`-1`则为最后要返回的数组的大小；
4. 然后将`1`到最大的`n`位数存放在数组中即可；

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        StringBuilder stringBuilder = new StringBuilder("1");
		for (int i = 0; i < n; i++) {
			stringBuilder.append("0");
		}
		
		int size = Integer.parseInt(stringBuilder.toString()) - 1;

		int[] resultArr = new int[size];
		for (int i = 0; i < size; i++) {
			resultArr[i] = i + 1;
		}

		return resultArr;
    }
}
```