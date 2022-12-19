### 解题思路
想看插入排序实现的想法可以看看代码，没什么好讲的，插入排序常规思路了，就是效率不高

### 代码

```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        int temp;
		int j;
		for(int i = 1;i<arr.length;i++) {
			temp = arr[i];
			j = i - 1;
			while(j >= 0 && temp < arr[j]) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j+1] = temp;
		}
		int[] result = new int[k];
		for(k = k - 1;k>=0;k--) {
			result[k] = arr[k];
		}
		return result;
    }
}
```