### 解题思路
1. 现将传入的数组arr进行排序（任意排序方法皆可，此处采用冒泡）；
2. 新定义一个最终结果的int型数组resultArr，长度为传入的k；
3. 将排序好的数组的前k个值传入上一步中所定义的数组resultArr中；
4. 返回最终结果数组resultArr；

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //		排序数组，冒泡排序
		for(int i = 0; i < arr.length - 1; i++){
			for (int j = 0; j < arr.length - 1 - i; j++){
				if (arr[j] > arr[j + 1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}

		int[] resultArr = new int[k];
		for (int m = 0; m < k; m++){
			resultArr[m] = arr[m];
		}
		return resultArr;
    }
}
```