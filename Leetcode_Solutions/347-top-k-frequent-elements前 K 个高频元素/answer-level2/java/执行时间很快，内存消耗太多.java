class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
       List <Integer> list=new ArrayList<Integer>();
		Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		PriorityQueue<Number> queue=new PriorityQueue<Number>(new Comparator<Number>() {
			@Override
			public int compare(Number o1, Number o2) {
				return o2.count-o1.count;
			}
		});
		for(int i=0;i<nums.length;i++){
			putVal(map,nums[i]);
		}
		for(Map.Entry<Integer,Integer> entry:map.entrySet()){
			queue.add(new Number(entry.getKey(),entry.getValue()));
		}
		for(int i=0;i<k;i++){
			Number number = queue.poll();
			list.add(number.num);
		}
        return list;
    }
    
    public static void putVal(Map<Integer,Integer> map,int i){
        if(map.containsKey(i)){
            int count=map.get(i);
            map.put(i,count+1);
        }else{
            map.put(i,1);
        }
    }
}
class Number{
	public Number(int num,int count){
		this.num=num;
		this.count=count;
	}
	int num;
	int count;
}

执行时间很快，就是太耗内存了，参考下