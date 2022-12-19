### 解题思路
很平淡的一个解答方式，先去判断是否返回空数组
1.如果第二个数组的和减去本数组中最大的，加上第一个数组最小的，如果仍然大于第一个数组，则返回（同理1-2）
2.遍历去取得相同时的值
执行用时 :6 ms , 在所有 Java 提交中击败了98.83%的用户
内存消耗 :47.7 MB, 在所有 Java 提交中击败了100.00%的用户


### 代码

```java
class Solution {
    public int[] findSwapValues(int[] array1, int[] array2) {
        int[] result = {};
		Arrays.sort(array1);
		Arrays.sort(array2);
		int count1 = 0;
		int count2 = 0;
		int max1 = array1[array1.length-1];
		int max2 = array2[array2.length-1];
		int min1 = array1[0];
		int min2 = array2[0];
		for(int i : array1){
			count1 += i;
		}
		for(int i : array2){
			count2 += i;
		}
		// 是否返回空数组
		boolean emptyFlag = false;
		// 如果第二个数组的和减去本数组中最大的，加上第一个数组最小的，如果仍然大于第一个数组，则返回空
		if(count2 > count1){
			emptyFlag = (count2 - max2 + min1) > (count1 - min1 + max2) ? true : false; 
		}else{
			emptyFlag = (count1 - max1 + min2) > (count2 - min2 + max1) ? true : false; 
		}
		if(emptyFlag)
			return result;
		for(int i = 0 ; i < array1.length ; i++){
			int val1 = array1[i];
			for(int j = array2.length-1 ; j > 0 ; j-- ){
				int val2 = array2[j];
				if((count1 - val1 + val2) == (count2 - val2 + val1)){
					result = new int[2];
					result[0] = val1;
					result[1] = val2;
					return result;
				}
			}
			
		}
		
		return result;
    }
}
```