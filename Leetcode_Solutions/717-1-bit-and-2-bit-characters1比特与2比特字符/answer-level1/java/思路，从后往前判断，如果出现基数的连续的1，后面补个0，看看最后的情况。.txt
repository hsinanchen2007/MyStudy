 public boolean isOneBitCharacter(int[] bits) {
    	int lastOneIndex = bits.length-1;
    	boolean consecutive = false;
    	int count = 0;
    	for (int i = bits.length-1; i>=0; i--) {
    		if (bits[i]==1) {
    			if (!consecutive) {
    				lastOneIndex = i;
    			}
    			count++;
    			consecutive = true;
    		} else {
    			if (consecutive) {
    				break;
    			}
    		}
    	}
    	
    	if(count == 0) {
        	return true;
    	}
    	
    	if (count%2 == 0) {
    		if (lastOneIndex == bits.length-1) {
    	    	return false;
    		}
    	} else {
    		if (lastOneIndex == bits.length-2) {
    	    	return false;
    		}
    	}
    	
    	
    	return true;
    }