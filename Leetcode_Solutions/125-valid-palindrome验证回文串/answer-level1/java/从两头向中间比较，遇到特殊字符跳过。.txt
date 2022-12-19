	public  boolean isPalindrome(String s) {
		if(s.length()==0)return  true;
		int i=0;
		int j= s.length()-1;
		while(i<j){
			if(! isAlphaNum(s.charAt(i))){i++; continue;}
			if(! isAlphaNum(s.charAt(j))){j--; continue;}
			if(toLower(s.charAt(i++)) == toLower(s.charAt(j--))){
				continue;
			}else{
				return false;
			}
		}
		return true;
	}

	public char toLower(char c){
		return (char)(c>='A'&&c<='Z' ? (c+32) : c );
	}
	public boolean isAlphaNum(char c){
		return (c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z');
	}