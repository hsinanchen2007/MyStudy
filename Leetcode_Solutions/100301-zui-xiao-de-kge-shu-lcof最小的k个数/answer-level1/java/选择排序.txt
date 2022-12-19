选择排序是选择数组中最小的数将该数移动到数组最前面，将其他元素往后移动，重复N次操作（时间复杂的（O（N2）））
	    public int[] getLeastNumbers(int[] arr, int k) {
	    	int [] result=new int[k];
	    	for(int i=0;i<k;i++){
	    		int min=arr[i];
	    		for(int j=i+1;j<arr.length;j++){
	    			if(min>arr[j]){
	    				int temp=min;
	    				min=arr[j];
	    				arr[j]=temp;
	    			}
	    		}
	    		result[i]=min;
	    	    arr[i]=min;
	    	}
	    	return result;

	    }