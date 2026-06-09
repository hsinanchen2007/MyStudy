变量ForR为标志位，false时用于右侧指针移动，true时左侧指针移动
```
class Solution {
    public String minWindow(String s, String t) {
    	if(s.isEmpty() || t.isEmpty())
    		return "";
    	if(s.length() < t.length())
    		return "";
    	
    	Map<Character,Integer> charMap = new HashMap<>();
    	for(int i = 0; i < t.length(); i++) {
    		if(charMap.containsKey(t.charAt(i))) {
    			charMap.put(t.charAt(i), charMap.get(t.charAt(i))+1);
    		}else {
        		charMap.put(t.charAt(i), 1);
    		}
    	}

    	Map<Character,Integer> sMap = new HashMap<>();
    	Map<Character,Boolean> containsMap = new HashMap<>();
    	int l = 0,r = 0;
    	int matchSize = 0,tSize = charMap.size();
    	StringBuilder tmp = new StringBuilder();
    	String result = "";
    	boolean LorR = false;
    	for(; r <= s.length();) {
    		if(!LorR) {
    			if(r == s.length())
    				break;
        		if(charMap.containsKey(s.charAt(r))) {
            		if(sMap.containsKey(s.charAt(r))) {
            			sMap.put(s.charAt(r), sMap.get(s.charAt(r))+1);
            		}else {
            			sMap.put(s.charAt(r), 1);
            		}
            		if(charMap.get(s.charAt(r)) <= sMap.get(s.charAt(r)) && !containsMap.containsKey(s.charAt(r))) {
            			matchSize++;
                		containsMap.put(s.charAt(r), true);
            		}
        		}
        		tmp.append(s.charAt(r));
        		if(matchSize == tSize) {
        			if(result.isEmpty())
        				result = tmp.toString();
        			else
        				result = result.length()>tmp.length()?tmp.toString():result;
        			LorR = true;
        		}
        		r++;
    		}else {
    			if(r-l < t.length()) {
    				break;
    			}
        		if(charMap.containsKey(s.charAt(l))) {
        			sMap.put(s.charAt(l), sMap.get(s.charAt(l))-1);
        			if(sMap.get(s.charAt(l)) < charMap.get(s.charAt(l))) {
        				matchSize--;
        				containsMap.remove(s.charAt(l));
            			LorR = false;
            			result = result.length()>tmp.length()?tmp.toString():result;
        			}
        		}
    			tmp.deleteCharAt(0);
        		l++;
    		}
    	}
    	return result;
    }
}
```
