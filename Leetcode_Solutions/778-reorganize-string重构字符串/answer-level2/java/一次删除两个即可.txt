    public String reorganizeString(String s) {
        if(s == null || s.length() <=1){
        	return s;
        }
        char[] chars = s.toCharArray();
        int[] appearTime = new int[26];
        char[] dict = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
        		'q','r','s','t','u','v','w','x','y','z'};
        for(char c : chars){
        	appearTime[c-'a'] ++;
        }
        int l = s.length();
        int max = 0;
        for(int i=0; i<26; i++){
        	if(appearTime[i] > max){
        		max = appearTime[i];
        	}
        }
       if(l % 2 == 0 && max > l/2){
    	   return "";
       }
       if(l % 2 != 0 && max > l/2+1){
    	   return "";
       }
        int maxIndex;
        int max2Index;
        StringBuilder builder = new StringBuilder();
        while(l >= 2){
        	maxIndex = findMax(appearTime);
        	max2Index = find2Max(appearTime, maxIndex);
        	builder.append(dict[maxIndex]);
        	builder.append(dict[max2Index]);
        	appearTime[maxIndex]--;
        	appearTime[max2Index]--;
        	l-=2;
        }
        if(l >0){
        	maxIndex = findMax(appearTime);
        	builder.append(dict[maxIndex]);
        }
        
        return builder.toString();
        
    }
	
	private int find2Max(int[] appearTime, int maxIndex) {
		int max = 0;
		int index = 0;
		for(int i =0; i < appearTime.length; i++){
			if( i != maxIndex && appearTime[i] > max ){
				max = appearTime[i];
				index = i;
			}
		}
		return index;
	}

	private int findMax(int[] appearTime) {
		int max = 0;
		for(int i =0; i < appearTime.length; i++){
			if(appearTime[i] > appearTime[max]){
				max = i;
			}
		}
		return max;
	}