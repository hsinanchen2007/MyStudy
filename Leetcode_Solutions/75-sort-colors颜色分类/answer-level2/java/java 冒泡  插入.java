### 解题思路

### 代码

```java
class Solution {
    public void sortColors(int[] arr) {
		for (int i = 0; i < arr.length-1; i++) {
			for (int j = 0; j < arr.length-1-i; j++) {
				if (arr[j]>arr[j+1] ) {
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
            }
			
		}
	 } 




	public  void swap2(int[] arr) {
		
		int insertValue = 0;
		int insertIndex = 0;
		
		for (int i = 0; i < arr.length; i++) {
			
			insertValue=arr[i];
			insertIndex=i-1;
			
			
			while(insertIndex>=0 && insertValue<arr[insertIndex]) {
				arr[insertIndex+1]=arr[insertIndex];
				insertIndex--;
			}
			
			if (insertIndex+1 != i) {
				arr[insertIndex+1] = insertValue;
			}
			
		}
		
	}
}
}
```