public int[][] merge(int[][] intervals) {
		if(intervals.length==0)return new int[0][0];
		int[] temp = new int[intervals.length*intervals[0].length];
		int k=0;
		//将二维数组降维处理
		for(int i=0;i<intervals.length;i++)
			for(int j=0;j<intervals[0].length;j++) {
				temp[k++]=intervals[i][j];
			}
		//对数据排序
		for(int i=0;i<temp.length/2-1;i++)
			for(int j=0;j<temp.length-2-i;j=j+2) {
				if(temp[j]>temp[j+2]) {
					int tempp=temp[j];
					temp[j]=temp[j+2];
					temp[j+2]=tempp;
					
				    tempp=temp[j+1];
					temp[j+1]=temp[j+3];
					temp[j+3]=tempp;
					
				}
			}
		
		//区间合并
		int m=1,n=2;
		while(n+1<temp.length) {
			if(temp[m]>=temp[n]&&temp[m]<=temp[n+1]) {
				temp[m]=Integer.MAX_VALUE;
				temp[n]=Integer.MAX_VALUE;
			}
			else if(temp[m]>=temp[n]&&temp[m]>temp[n+1]) {
				temp[n+1]=temp[m];
				temp[m]=Integer.MAX_VALUE;
				temp[n]=Integer.MAX_VALUE;
			}
			m=m+2;
			n=n+2;
		}
		List<Integer> result = new ArrayList<Integer>();
		//去除无效数字
		for(int i=0;i<temp.length;i++) {
			if(temp[i]!=Integer.MAX_VALUE)
			result.add(temp[i]);
		}
		int[][] resultArray = new int[result.size()/2][2];
		k=0;
		//生成结果二维数组
		for(int i=0;i<result.size()/2;i++)
			for(int j=0;j<2;j++){
				resultArray[i][j]=result.get(k++);
			}
		
		return resultArray;
}