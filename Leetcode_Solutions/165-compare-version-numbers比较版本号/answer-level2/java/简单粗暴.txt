### 解题思路
分割"."，转换int数组，逐个比较，缺省为0

### 代码

```java
class Solution {
   public int compareVersion(String version1, String version2) {
		String[] versionArr1 = version1.split("\\.");
		String[] versionArr2 = version2.split("\\.");
		int len = Math.max(versionArr1.length, versionArr2.length);
		int[] arr1 = new int[len];
		int[] arr2 = new int[len];
		for (int i = 0; i < len; i++) {
			if (i < versionArr1.length) {
				arr1[i] = Integer.valueOf(versionArr1[i]);
			}
			if (i < versionArr2.length) {
				arr2[i] = Integer.valueOf(versionArr2[i]);
			}
			if (arr1[i] > arr2[i]) {
				return 1;
			}
			if (arr1[i] < arr2[i]) {
				return -1;
			}
		}
		return 0;
	}
}
```