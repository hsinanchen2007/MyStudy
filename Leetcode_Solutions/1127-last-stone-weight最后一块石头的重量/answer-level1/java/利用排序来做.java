为每次都是选取最大的两颗石头，所以可以利用排序来做，每次选出两颗最大的石头并做了相应的处理后，再次对数组进行排序，这样就保证所有的零在前面，最后数组最后两位只能是0和某个数，或者都是零。
```
public static int lastStoneWeight(int[] stones) {
		int result=1000;
		int[] arr = Arrays.copyOf(stones, stones.length);
		Arrays.sort(arr);
		int i = arr.length - 1;
		if(i>0){
			if (arr[i] == 0 && arr[i - 1] == 0) {
				result = 0;
				return result;
			}
			if (arr[i] != 0 && arr[i - 1] == 0) {
				result = arr[i];
				return result;
			}
			if (arr[i] == arr[i - 1]) {
				arr[i] = 0;
				arr[i - 1] = 0;
				result = lastStoneWeight(arr);
			} else if (arr[i - 1] < arr[i]) {
				arr[i] = arr[i] - arr[i - 1];
				arr[i - 1] = 0;
				result = lastStoneWeight(arr);
			}
		}else{
			result=arr[i];
			return result;
		}
		
		return result;
	}
```