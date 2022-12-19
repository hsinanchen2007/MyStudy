先把数组分为start 与end两个数组排序  然后比较后一个start与前一个end 如果end >=start进行合并  注意index是用来标记实际长度的  不然没法知道二维数组的长度

```
public static int[][] merge(int[][] intervals) {

	    if(intervals==null || intervals.length==0)  return new int[0][0]; 
	    int []start=new int[intervals.length];
	    int []end=new int[intervals.length];
	    for (int i = 0; i < end.length; i++) {
			start[i]=intervals[i][0];
			end[i]=intervals[i][1];
		}
	    Arrays.sort(start);
	    Arrays.sort(end);
	    
	    int i=0;
	    int arr[][]=new int[intervals.length][2];
	    //使用index标记实际长度
	    int index=0;
	    
	    while(i<intervals.length){
	    	int st=start[i];
	    	while(i<intervals.length-1 && start[i+1]<=end[i]) i++;
	    	int en=end[i];
	    	arr[index][0]=st;
	    	arr[index][1]=en;
	    	i++;
	    	index++;
	    	
	    }
	    //只取前一部分
	    arr = Arrays.copyOfRange(arr, 0, index);

	    return arr;
	}
```
