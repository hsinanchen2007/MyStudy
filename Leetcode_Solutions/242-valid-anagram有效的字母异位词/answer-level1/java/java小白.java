public boolean isAnagram(String s, String t) {
        char[]arrs=s.toCharArray();
        char[]arrt=t.toCharArray();
        char[]masks=new char[26];
        char[]maskt=new char[26];
        int[]nums=new int[26];
        int[]numt=new int[26];
        char c='a';
        for(int i=0;i<26;i++) {
        	masks[i]=c;
        	maskt[i]=c;
        	c++;
        }
        for(int i=0;i<26;i++) {
        	nums[i]=0;
        	numt[i]=0;
        }
        for(int i=0;i<arrs.length;i++) {
        	for(int j=0;j<26;j++) {
        		if(arrs[i]==masks[j])
        			nums[j]++;
        	}
        }
        for(int i=0;i<arrt.length;i++) {
        	for(int j=0;j<26;j++) {
        		if(arrt[i]==maskt[j])
        			numt[j]++;
        	}
        }
        for(int i=0;i<26;i++) {
        	if(nums[i]!=numt[i])
        		return false;
        }
        return true;
    }