 









 public int addDigits(int num) {
        int result=0;
		int b=0;
		while(num>0){
			b=num%10;
			num=num/10;
			result+=b;   
			if(num==0 && result>9){
				num=result;
				result=0;
			}
		}
		return result;
    }