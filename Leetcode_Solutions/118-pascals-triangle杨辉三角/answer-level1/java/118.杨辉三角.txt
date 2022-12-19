class Solution {
    public List<List<Integer>> generate(int numRows) {
	    List<List<Integer>> result= new ArrayList<List<Integer>> ();
        if(numRows==0){
	        return result;
	    }
	    List<Integer> first= new ArrayList<Integer>();
	    first.add(1);
	    result.add(first);
	    for(int i=1;i<numRows;i++) {
	        List<Integer> temp= new ArrayList<Integer> ();
	        temp.add(1);
	        for(int j=1;j<i;j++) {
	        	int sum=result.get(i-1).get(j-1)+result.get(i-1).get(j);
	        	temp.add(sum);
	        }
	        temp.add(1);
	        result.add(temp); 
	    }
	    return result;
    }
}