class Solution {
    public String toLowerCase(String str) {
        /*return str.toLowerCase();*/
        /*StringBuffer sb=new StringBuffer();
		char[] arr=str.toCharArray();
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]>='A'&&arr[i]<='Z')
			{
				arr[i]=(char)(arr[i]+32);
				
			}
			sb.append(arr[i]);
		}
		return sb.toString();*/
        
        /*  执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34.5 MB, 在所有 Java 提交中击败了55.97%的用户*/
        StringBuffer sb=new StringBuffer();
        	char temp;
		for(int i=0;i<str.length();i++)
		{
			temp=str.charAt(i);
			if(temp>='A'&&temp<='Z')
			{
				temp=(char)(temp+32);
			}
			sb.append(temp);
		}
		return sb.toString();
    }
}