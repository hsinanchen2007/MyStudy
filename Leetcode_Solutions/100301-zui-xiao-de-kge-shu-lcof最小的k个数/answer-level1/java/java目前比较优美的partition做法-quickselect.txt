```
//最小的k个数
	public int[] getLeastNumbers(int[] arr, int k) {
		if(k==0||arr.length==0)return new int[0];
		quickselect(arr,0,arr.length-1,k);
		int[] res=new int[k];
		for(int i=0;i<k;i++) {
			res[i]=arr[i];
		}
		return res;
	}

	private void quickselect(int[] arr, int begin, int end, int k) {
		if(begin>=end)return;
		int m=partition(arr,begin,end);
		if(k==m) {
			return;
		}else if(k<m) {
			quickselect(arr, begin,m-1, k);
		}else if(k>m){
			quickselect(arr, m+1,end, k);
		}
	}

	private int partition(int[] arr, int begin, int end) {
		int pivot=end;
		int counter=begin;
		for(int i=begin;i<end;i++) {
			if(arr[i]<arr[pivot]) {
				int temp=arr[counter];
				arr[counter]=arr[i];
				arr[i]=temp;
				counter++;
			}
		}
		int temp=arr[pivot];
		arr[pivot]=arr[counter];
		arr[counter]=temp;
		return counter;
	}
```
