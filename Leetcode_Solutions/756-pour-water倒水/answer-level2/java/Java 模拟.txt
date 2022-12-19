思路：V的数量很小只有2000，考虑暴力模拟即可
首先考虑能不能向左流 再考虑能不能向右流
需要注意流动过程中如果数列22225，从5开始流的话，式子会变成22235,而不是32225
```
   public static void 	daoshui(int[] arr,int k) {
		    		    	boolean neng =false;
		    		    	boolean rneng=false;
		    		    	for(int i=k-1;i>=1;i--) {
		    		    		if(arr[i]<arr[i+1]) {
		    		    		neng=true;
		    		    			break;
		    		    		}else if(arr[i]>arr[i+1]) {
		    		    			break;
		    		    		}
		    		    	}
		    		    	if(!neng) {		    	//	    		System.out.println(1);

		    		    		for(int i=k+1;i<arr.length;i++) {
		    		    			if(arr[i]<arr[i-1]) {
		    		    				rneng=true;
		    		    				break;
		    		    			}else if(arr[i]>arr[i-1]) {
		    		    				break;
		    		    			}
		    		    		}
		    		    	}
           		    		    	//System.out.println(rneng);

		    		    	if(!neng&&!rneng) {
		    		    		arr[k]++;
		    		    	}
		    		    	if(neng) {
		    		    		int q=-1;
		    		    		for(int i=k-1;i>=1;i--) {
		    		    			int count =-1;
		    		    			if(arr[i]<arr[i-1]) {
		    		    				count=i;
		    		    				q=arr[count];
		    		    				break;
		    		    			}
		    		    		}
		    		    		for(int i=k-1;i>=1;i--) {
		    		    			if(arr[i]==q) {
		    		    				arr[i]++;
		    		    				break;
		 
		    		    			}
		    		    		}
		    		    	}
		    		    	if(!neng&&rneng) {int q=-1;
		    		    		for(int i=k+1;i<arr.length-1;i++) {
		    		    			int count=-1;
		    		    			if(arr[i]<arr[i+1]) {
		    		    				count =i;
		    		    				q=arr[count];
		    		    				break;  
		    		    			}
		    		    		}
		    		    		for(int i=k+1;i<arr.length-1;i++) {
		    		    			if(arr[i]==q) {
		    		    				arr[i]++;
		    		    				break;
		    		    			}
		    		    		}
		    		    	}
		    		    }
		    		    public int[] pourWater(int[] heights, int V, int K) {
		    		    	int []arr=new int [heights.length+2];
		    		    	for(int i=1;i<=heights.length;i++) {
		    		    		arr[i]=heights[i-1];
		    		    	}
		    		    	arr[0]=99999;
		    		    	arr[heights.length+1]=99999;
		    		    	for(int i=0;i<V;i++) {
		    		    		daoshui(arr,K+1);
                                		    		    	//	System.out.println(Arrays.toString(arr));

		    		    	}for(int i=0;i<heights.length;i++) {
		    		    		heights[i]=arr[i+1];
		    		    	}
		    		    	return heights;
		    		    }
```
