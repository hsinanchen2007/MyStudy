遍历，排除

public static String getHint(String secret, String guess) {
        char []sArray = secret.toCharArray();
        char []gArray = guess.toCharArray();
        
        ArrayList<Integer> recIndex = new ArrayList<>();
        ArrayList<Integer> repeatIndex = new ArrayList<>();
        int gCount = 0;
        int mCount = 0;
        for (int i = 0; i < sArray.length; i ++) {
        	if ( sArray[i] == gArray[i] ) {
        		recIndex.add(i);
        		repeatIndex.add(i);
        		gCount ++;
        	}
        }
        
        for (int j = 0; j < sArray.length; j ++) {
        	Boolean bRepeat = false;
        	for (int k = 0; k < recIndex.size(); k ++) {
        		if ( recIndex.get(k) == j ) {
        			bRepeat = true;
        			break;
        		}
        	}
        	
        	if ( !bRepeat ) {
        		for (int u = 0; u < gArray.length; u ++) {
        			if( gArray[u] == sArray[j] ) {
        				Boolean bRepeat1 = false;
            			for (int k = 0; k < repeatIndex.size(); k ++) {
                    		if ( repeatIndex.get(k) == u ) {
                    			bRepeat1 = true;
                    			break;
                    		}
                    	}
            			
            			if ( !bRepeat1 ) {
            				repeatIndex.add(u);
                			mCount ++;
                			break;
            			}
        			}
        		}
        	}
        }
        
        return gCount + "A" + mCount + "B";
    }