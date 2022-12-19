
	public int strStr(String haystack, String needle) {
        	char[] str1 = haystack.toCharArray();
		char[] str2 = needle.toCharArray();

		if(str1.length < str2.length)
          		return -1;
        	if(str1.length == 0 || str2.length == 0)
        		return 0;

		for(int i = 0;i < str1.length;i++){
			int k = i;
			for(int j = 0;(j < str2.length) && (k < str1.length) && (str1[k] == str2[j]);j++,k++){
				if(j == str2.length - 1)
					return i;
			}
		}

		return -1;
    	
	}