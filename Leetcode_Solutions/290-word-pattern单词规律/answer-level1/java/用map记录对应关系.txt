pattern与str单词和字符的对应关系使用map来记录可解题。

public static boolean wordPattern(String pattern, String str) {
        char []cArray = pattern.toCharArray();
        String []strArray = str.split(" ");
        
        if ( cArray.length != strArray.length ) {
        	return false;
        }
        
        Map<Character, String> map = new HashMap<Character, String>(); 
        for (int i = 0; i < cArray.length; i++ ) {
        	
        	Boolean bSearch = true;
        	for(Character key : map.keySet()){
        		String value = map.get(key);
        	    if ( key == cArray[i] ) {
        	    	bSearch = false;
        	    	if ( !value.equals(strArray[i]) ) {
        	    		return false;
        	    	}
        	    }
        	    else {
        	    	if ( value.equals(strArray[i]) ) {
        	    		return false;
        	    	}
        	    }
        	} 
        	
        	if ( bSearch ) {
        		map.put(cArray[i], strArray[i]);
        	}
        }
        
        return true;
    }