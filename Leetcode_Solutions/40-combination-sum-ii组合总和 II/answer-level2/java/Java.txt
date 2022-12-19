class Solution {
	
	List<List<Integer>> list = new LinkedList<>();
	
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
    	Arrays.sort(candidates);
    	LinkedList<Integer> l = new LinkedList<>();
    	combination(candidates,l,target,0);
    	return list;
    }
    
    public void combination(int[] candidates,LinkedList<Integer> l,int target,int start){
    	if(target==0) {
    		list.add(new LinkedList<>(l));
    	}else {
    		for(int i = start;i<candidates.length;i++) {
                if(i>start&&candidates[i]==candidates[i-1])
            {
                continue;
            }
        		if(target>=candidates[i]) {              
                    l.add(candidates[i]);
                    combination(candidates,l,target-candidates[i],i+1);
        			l.removeLast();
        		}else {
        			break;
        		}
        	}
    	}
    }  
}