各位大佬们好，我本来想要用DFS解决这道题，但是发现这边好像都是用BFS的题解，打扰了。 
思路大致为，先根据beginword对全空间的单词进行处于，对于第一个beginword，我首先找出所有与它差一的单词列列表onediflist，其他的单词作为下一轮的全空间列表restlist。 单词处理结束之后，根据得到的onediflist，依次将里面的单词作为beginword进行递归查找，。。。。 对于最后遍历过得onediflist，将路径最小的值最为当前beginowrd到endword之间的路径长度。 以下是代码。

  ```
 String endword;
   int min=Integer.MAX_VALUE;
   Map<String,Integer>lenToendword=new HashMap<String, Integer>();// 存储单词与endword之间的距离
	 public int ladderLength(String beginWord, String endWord, List<String> wordList) {	     
	     if(beginWord.equals(endWord)) return 1;
	     if(wordList.size()<1) return 0; 
	     this.endword=endWord;
	     if(!wordList.contains(endWord)) return 0;
	     Set<String> wordSet=new HashSet<String>(wordList);   
	     return Math.max(0, findladderlength(beginWord, wordSet,1));
	    }
	 public int findladderlength(String beginword,Set<String> wordSet,int level) {
		 if(level>min || !wordSet.contains(endword)) { // hashset 查找时间为O(1)
			 lenToendword.put(beginword, -1);
			 return -1;
		 }
		 int ans=Integer.MAX_VALUE;
		Set<String> restStrings=new HashSet<String>();//  restStrings=worlist-onedifword   存储与beginword差别2个以上字母的单词
		 List<String> onedifwords=new ArrayList<String>(); // 存储与beginword只有一个字母差别的单词
		 for(String curString:wordSet) {
	        	
	        	if(lenToendword.containsKey(curString)&&lenToendword.get(curString)==-1) continue; // 剪枝，如果已经判断了是到不了的，就没必要重复计算
	        	int count=0;     	
	        	for(int j=0;j<beginword.length();j++) {  // 这一段循环计算与beginword差几个字母
	        		if(beginword.charAt(j)!=curString.charAt(j)) {
	        			count++;
	        		}
	        	}
	        	if(count>1) {// 如果差2个及以上，就存到restString
	        		restStrings.add(curString);
	        	}else if(count==1) {// 如果只差一个 就存到onedifwords
	        		if(curString.equals(endword)) {// 如果onedifwords中存在endword，那么一步到位，此处的beginword与endword之间距离为2，同时记录
	        			lenToendword.put(beginword,2);
	        			if(min>level+1) {
	        				min=level+1;
	        			}	   		
	        			return 2;
	        		}
	        			
	        		onedifwords.add(curString);
	        	}
	        }
		 
		 for(int i=0;i<onedifwords.size();i++) {
			 int curlen=0;
			 if(lenToendword.containsKey(onedifwords.get(i))) {
				 curlen=lenToendword.get(onedifwords.get(i));
			 }else {
				 curlen=findladderlength(onedifwords.get(i),restStrings,level+1);
			 }
			 
	         if(curlen==-1) continue;
	         ans=Math.min(curlen+1, ans);
		 }
		 ans=( ans==Integer.MAX_VALUE?-1:ans);// 将距离endword最短的距离作为当前单词到end'word之间的距离
		 // 如果不能到达，或者lenToendword没有存储该字母，或者找到了一个更短的距离
		 if(ans==-1||!lenToendword.containsKey(beginword)||(lenToendword.containsKey(beginword)&&lenToendword.get(beginword)>ans)) {
			 lenToendword.put(beginword, ans);
		 }
		
		 
		 return ans;
	 }
```
