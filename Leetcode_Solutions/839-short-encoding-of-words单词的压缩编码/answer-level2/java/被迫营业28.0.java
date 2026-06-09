class Solution {
    public int minimumLengthEncoding(String[] words) {
 if(words.length==0) {
			   return 0;
		   }
		   	Arrays.sort(words,new Comparator<String>(){

				@Override
				public int compare(String o1, String o2) {
					// TODO Auto-generated method stub
					if (o1.length() > o2.length())
						                    return -1;
						                else if (o1.length() < o2.length())
						                    return 1;
						                return o1.compareTo(o2);
				}
		   		
		   	});
		   	int ans =0;
		   	List<String> list = new ArrayList<String>();
		   	list.add(words[0]);
		   	ans+=words[0].length();
		   	for(int i=1;i<words.length;i++) {
		   		int len = words[i].length();
		   		boolean b = true;
		   		for(String s:list) {
		   		if(s.substring(s.length()-len).equals(words[i])||s.equals(words[i])) {
		   				b=false;
		   				break;
		   			}
		   		}
		   		if(b) {
		   			list.add(words[i]);
		   			ans+=words[i].length();
		   		}
		   	}
		   	ans+=list.size();
		   	return ans;
    }
}