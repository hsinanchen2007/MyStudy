class Solution {
    public int numUniqueEmails(String[] emails) {
    	if (emails == null || emails.length == 0)
    		return 0;
    	java.util.ArrayList<String> temp = new java.util.ArrayList<>();
    	int result = 0;
    	
    	for (int i = 0; i < emails.length; i++) {
    		String[] temp1 = new String[2];
    		String temp2 = "";
 
    		temp1 = emails[i].split("@");

    		
    		for (int j = 0; j < temp1[0].length(); j++) {
    			if (temp1[0].charAt(j) == '.') {
    				temp1[0] = temp1[0].replaceAll("[.]", "");
    			}
    			if (temp1[0].charAt(j) == '+') {
    				temp1[0] = temp1[0].substring(0, j);
    				break;
    			}
    		}

    		
    		temp2 = temp1[0]+"@"+temp1[1];
    		
    		if (!temp.contains(temp2))
    			temp.add(temp2);
    	}
    	
    	return temp.size();
    }
}