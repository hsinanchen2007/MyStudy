class Solution {
    public String addStrings(String num1, String num2) {
        int len1=num1.length();
        int len2=num2.length();
        int upLen,downLen;
        String upSt;
        String dowSt;
        if(len1>=len2)
        {
        	upSt=num1;
        	dowSt=num2;
        	upLen=len1;
        	downLen=len2;
        }
        else
        {
        	upSt=num2;
        	dowSt=num1;
        	upLen=len2;
        	downLen=len1;
        }
        
        int agent=0,sum=0;
        int i,j;
        StringBuffer result=new StringBuffer();
        for(i=upLen-1,j=downLen-1;i>=0&&j>=0;i--,j--)
        {
        	sum=upSt.charAt(i)-'0'+dowSt.charAt(j)-'0'+agent;
        	agent=sum/10;
        	result.append(sum%10);
        	System.out.println("sum:"+sum+"\t"+"sun%10:"+sum%10);
        }
        
        while(i>=0)
        {
        	sum=upSt.charAt(i)-'0'+agent;
        	agent=sum/10;
        	result.append(sum%10);
        	i--;
        }
        
        if(agent!=0)//如果进位到第一位超过10，则在头追加
        {
        	result.append(agent);
        }
        
        return result.reverse().toString();
    }
}