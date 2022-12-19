### 解题思路
从左往右比较，
1.当 [i]>[i+1] 那就说明这个数([i])需要移除,
2.当遍历到最后一个元素[length-1]时，说明需要移除最后一个元素!
每移动一次更新char数组

### 代码

```java
class Solution {
    public String removeKdigits(String num, int k) {
		if (num == null || num.length() <= k)
			return "0";
		char[] baseArr = num.toCharArray();
		for (int item = 0; item < k; item++) {
			for (int i = 0; i < baseArr.length; i++) {
				//删除最后一个
				if (i == baseArr.length - 1) {
					baseArr = Arrays.copyOf(baseArr, baseArr.length - 1);
					break;
				} else {
					//删除第i个元素
					if (baseArr[i] > baseArr[i + 1]) {
						char[] arr1 = Arrays.copyOfRange(baseArr, 0, i);
						char[] arr2 = Arrays.copyOfRange(baseArr, i + 1, baseArr.length);
						int originArr1Length = arr1.length;
						arr1 = Arrays.copyOfRange(arr1, 0, arr1.length + arr2.length);
						System.arraycopy(arr2, 0, arr1, originArr1Length, arr2.length);
						baseArr = arr1;
						break;
					}
				}
			}
		}
		//首字母去0
		String resp = new String(baseArr).replaceFirst("^0*", "");
		return "".equals(resp) ? "0" : resp;
	}


    
}
```