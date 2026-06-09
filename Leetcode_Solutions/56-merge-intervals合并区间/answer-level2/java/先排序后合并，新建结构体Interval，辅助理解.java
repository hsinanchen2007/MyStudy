如果把二维数组转化为Interval[]结构体变量的话，代码更容易理解，直接看代码：
```
    class Interval {//内部类
		int start;
		int end;
		

		public boolean canMerge(Interval that) {//可以合并区间
			if(this.end>=that.start)
				return true;
			return false;
		}
		public Interval mergeWith(Interval that) {//合并区间
			Interval tmp=null;
			if(this.end>that.end) {
				tmp=this;
			}else {
				tmp=new Interval(this.start,that.end);
			}
			return tmp;
		}
		
		public Interval(int start,int end) {
			this.start=start;
			this.end=end;
		}
		
		public int[] toArray() {
			int[]arr=new int[2];
			arr[0]=start;
			arr[1]=end;
			return arr;
		}
		
		
	}
	public int[][] merge(int[][]intervals){
		if(intervals.length==0)
            return new int[][] {};
		Interval[]inters=new Interval[intervals.length];
		for(int i=0;i<intervals.length;i++) {
			inters[i]=new Interval(intervals[i][0],intervals[i][1]);
		}
		
		Arrays.sort(inters, new Comparator<Interval>() {
			@Override
			public int compare(Interval o1, Interval o2) {
				return o1.start-o2.start;
			}
			
		});
		List<int[]>list=new ArrayList<>();
		Interval tmp=inters[0];
		for(int i=1;i<inters.length;i++) {
			if(tmp.canMerge(inters[i])) {	//如果可以合并
				tmp=tmp.mergeWith(inters[i]);
			}else {
				list.add(tmp.toArray());
				tmp=inters[i];
			}
		}
		list.add(tmp.toArray());//最后一个元素
		
		int[][]res=new int[list.size()][];//将结果转换int[][]
		int count=0;
		for(int[]temp:list) {
			res[count++]=temp;
		}
		return res;
	}
```
