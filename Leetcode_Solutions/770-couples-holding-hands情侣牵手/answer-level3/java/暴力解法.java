### 解题思路
直接遍历 然后交换位置 记录下交换次数
### 代码

```java
class Solution {
   public static int minSwapsCouples(int[] row) {
		int num=0;   //交换次数
		for (int i = 0; i <row.length-1 ;i=i+2 ) {  
			int val = row[i];
			int target;  
			if(val%2==0) target=val+1;   
			else target=val-1;
			for (int j = i+1; j <row.length ; j++) {
				if(row[j]==target && i!=j-1){
				  int temp;
				  temp=row[i+1];
				  row[i+1]=row[j];
				  row[j]=temp;
				  num++;
				  break;
				}
			}
		}
		return num;
	}
}
```