

class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        Map<Integer, Content> hMap = new HashMap<Integer, Content>();
        for(int i = 0; i < indexes.length; i++) {
	    	Content content = new Content();
	    	content.source = sources[i];
	    	content.target = targets[i];
	    	hMap.put(indexes[i], content);
	    }
	    
	    StringBuilder stringBuilder = new StringBuilder();
	    for(int i = 0; i <= S.length() - 1; ++i) {
	    	if(hMap.containsKey(i)) {
	    		 int start = i;
	             int end = hMap.get(i).source.length() + start;
	             if(hMap.get(i).source.equals(S.substring(start, end))) {
	            	 stringBuilder.append(hMap.get(i).target);
                     i += hMap.get(i).source.length() - 1;
	             }
	             else {
                     stringBuilder.append(S.charAt(i));
                 } 
	    	}
	    	else {
	    		stringBuilder.append(S.charAt(i));
	    	}
	    }
        return stringBuilder.toString();
    }
}

class Content {
	String source;
	String target;
}