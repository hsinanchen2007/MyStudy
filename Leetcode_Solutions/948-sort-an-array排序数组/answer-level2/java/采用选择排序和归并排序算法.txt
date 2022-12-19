```
public class MySort {
	//选择排序法(升序)
	public static int[] selectionSort(int[] originalData) {
		for (int i = 0; i < originalData.length-1; i++) {
			  for (int j = i+1; j < originalData.length; j++) {
				    if(originalData[i]>originalData[j]) {
				    	int t=originalData[i];
				    	originalData[i]=originalData[j];
				    	originalData[j]=t;
				    }
			}
		}
		return originalData;
	}
	//归并排序法
	public static int[] mergeSort(int[] originalData) {
		int []tarrayay=new int[originalData.length];
		sort(originalData, 0, originalData.length-1, tarrayay);
		return originalData;
		
	}
	    private static void sort(int[] array,int left,int right,int []tArray){
	        if(left<right){
	            int middle = (left+right)/2;
	            //左边归并排序
	            sort(array,left,middle,tArray);
	            //右边归并排序
	            sort(array,middle+1,right,tArray);
	            //将两个有序子数组合并操作
	            merge(array,left,middle,right,tArray);
	        }
	    }
	    private static void merge(int[] array,int left,int middle,int right,int[] tArray){
	        int i = left;
	        int j = middle+1;
	        int t = 0;//指示tArray下标
	        while (i<=middle && j<=right){
	            if(array[i]<=array[j]){
	                tArray[t++] = array[i++];
	            }else {
	                tArray[t++] = array[j++];
	            }
	        }
	        while(i<=middle){//将左边剩余元素填充进tArray中
	            tArray[t++] = array[i++];
	        }
	        while(j<=right){//将右序列剩余元素填充进tArray中
	            tArray[t++] = array[j++];
	        }
	        t = 0;
	        //将tArray中的元素全部拷贝到原数组中
	        while(left <= right){
	            array[left++] = tArray[t++];
	        }
	    }
}
```


