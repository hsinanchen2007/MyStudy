public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> result=new ArrayList<>();
		List<Integer> answer=new ArrayList<>();
		List<Integer> visit=new ArrayList<>();
		for(int i=0;i<nums.length;i++) {
			visit.add(nums[i]);
		}
		forPermute(visit, answer, result);
		return result;
	}
	
	public void forPermute(List<Integer> visit,List<Integer> answer,List<List<Integer>> result){
		if(visit.size()==0) {
			result.add(new ArrayList<>(answer));
			return;
		}
		for(int i=0;i<visit.size();i++) {
			answer.add(visit.get(i));
			List<Integer> i_visit=new ArrayList<>();
			for(int j=0;j<visit.size();j++) {
				if(j!=i) {
					i_visit.add(visit.get(j));
				}
			}
			forPermute(i_visit, answer, result);
			answer.remove(answer.size()-1);
		}
	}