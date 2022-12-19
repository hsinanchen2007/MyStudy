public String intToRoman(int num) {
		String str=new String();
		int tem=num;
      for(int i=0;i<6;i++) 
      {
    	  Result ret= getValue(tem,i);
    	  str+=ret.value;
    	  tem=ret.num;
      }
      str+=getChars(tem,'I');
       return str;
    }
	private Result getValue(int num,int i) 
	{	
		int  [] divisors= {1000,500,100,50,10,5};
		char  [] c1s=   {'M','D','C','L','X','V'};
		char  [] c2s=   {'C','C','X','X','I','I'};
		int [] offs= {100,100,10,10,1,1};
		int quotient=num/divisors[i];
		int Remainder=num%divisors[i];
		String str=new String();
		str=getChars(quotient,c1s[i]);
		if(Remainder>=(divisors[i]-offs[i]) )
		{
			str+=c2s[i];
			str+=c1s[i];
			Remainder-=(divisors[i]-offs[i]);
		}
		Result ret=new Result();
		ret.num=Remainder;
		ret.value=str;
		return ret;
	}
	private String getChars(int nums,char c) 
	{
		String ret=new String();
		for(int i=0;i<nums;i++) 
		{
			ret+=c;
		}
		return ret;
	}
class Result 
{
	String value;
	int num;
}