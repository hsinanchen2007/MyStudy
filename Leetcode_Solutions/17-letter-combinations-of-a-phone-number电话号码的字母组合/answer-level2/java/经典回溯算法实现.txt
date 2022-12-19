List<String> letterCombinations(String nums) {
		map.put("2", "abc");
		map.put("3","def");
		map.put("4", "ghi");
		map.put("5", "jkl");
		map.put("6", "mno");
		map.put("7", "pqrs");
		map.put("8","tuvw");
		map.put("9", "xyz");
		
		if(nums.length() == 0){
			return result;
		}
		
		String path = "";
		dfs(nums,0,nums.length(),result,path);
		return result;
			
	}

	private void dfs(String nums, int index, int len, List<String> result, String path) {
		// TODO Auto-generated method stub
		int length = nums.length();
		if(length == 1){
			for(int i=0;i<map.get(nums).length(); i++) {
				result.add(map.get(nums).substring(i,i+1));
			}
			return;
		}
		if(index == len){
			result.add(path);
			
			return ;
		}
		String tempS = map.get(String.valueOf(nums.charAt(index)));//abc
		for(int i=0;i<tempS.length();i++){
            //经典回溯算法，先选中当前值，递归，再释放掉当前值
			path += String.valueOf(tempS.charAt(i));
			dfs(nums,index+1,len,result,path);
			path = path.substring(0, path.length()-1);
		}
	}