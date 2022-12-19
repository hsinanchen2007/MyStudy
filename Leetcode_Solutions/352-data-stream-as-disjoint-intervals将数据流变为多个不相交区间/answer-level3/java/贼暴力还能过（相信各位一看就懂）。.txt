```
class SummaryRanges {

	List<Integer> list;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        list=new ArrayList<>();
    }
    
    public void addNum(int val) {
        list.add(val);
    }
    
    public int[][] getIntervals() {
    	int len=0;
    	Collections.sort(list);
        int[][] ans=new int[list.size()][2];
        for(int i=0;i<list.size();i++)
        {
        	if(i==0) ans[len][0]=list.get(i);
        	else
        	{
        		if(list.get(i)-list.get(i-1)>1)
        		{
        			ans[len++][1]=list.get(i-1);
        			ans[len][0]=list.get(i);
        		}
        	}
        }
        ans[len++][1]=list.get(list.size()-1);
        int[][] res=new int[len][2];
        for(int i=0;i<len;i++)
        	res[i]=ans[i];
        return res;
    }
}
```
