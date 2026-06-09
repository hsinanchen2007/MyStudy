题目本意实际按照26分解target数字。
每次按照26取余直至比26还小。

public static String convertToTitle(int n) {
    	ArrayList<Integer> cNum = new ArrayList<>();
    	
    	int nTemp = n;
    	int yu = 0;
    	while ( nTemp > 26 ) {
    		
    		yu = nTemp % 26;
    		nTemp /= 26;
    		if( yu == 0 ) {
    			yu = 26;
    			nTemp --;
    		}
    		
    		cNum.add(yu);
    	}
    	cNum.add(nTemp);
    	
    	String strConvert = "";
    	for ( int i = cNum.size() - 1; i >= 0; i -- ) {
    		strConvert += (char) (cNum.get(i) + 64);
    	}
    	
    	return strConvert;
    }
