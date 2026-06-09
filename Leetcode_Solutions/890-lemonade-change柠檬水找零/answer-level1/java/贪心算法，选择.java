class Solution {
    public boolean lemonadeChange(int[] bills) {
       int pa = 0;//5元张数
		int pb = 0;//10元张数
		for(int i = 0; i < bills.length; i++) {
			switch(bills[i]) {
			case 5:pa++;break;
			case 10:if(pa>0) {pa-=1;pb++;}else return false;break;
			case 20:if(pb > 0 && pa > 0) {pa-=1;pb-=1;}else if(pa > 2) pa-=3;else return false;break;
			}	
          
    }
        return true;
    }
}