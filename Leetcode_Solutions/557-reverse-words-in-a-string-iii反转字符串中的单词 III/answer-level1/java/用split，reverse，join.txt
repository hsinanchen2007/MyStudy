class Solution {
    public String reverseWords(String s) {
        String[] strings=s.split(" ");
	    List<String> list=new ArrayList<String>();
	    for(int i=0;i<strings.length;i++){
	        list.add(new StringBuffer(strings[i]).reverse().toString());
	    }
		return String.join(" ", list);
    }
}