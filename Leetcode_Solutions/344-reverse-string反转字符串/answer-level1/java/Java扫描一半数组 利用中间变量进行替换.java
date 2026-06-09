
扫描一半的数组，利用中间变量将s[i]和s[l-i-1]字符进行替换

如果数组长度为奇数，例如5，则需扫描从0-3

如果数组长度为偶数，例如6，也是将数据从0-3进行扫描，因此说，间隔点div=(l-1)/2+1

考虑边界情况，字符个数为0，1，2

class Solution {
    public void reverseString(char[] s) {
        
     
		int l=s.length;
		int div=(l-1)/2+1;
		char rep ='1';
		
        if(l>2){
            
            for(int i=0;i<div;i++) {
			rep=s[i];
			s[i]=s[l-1-i];
			s[l-1-i]=rep;
            }
        
        }else if(l==1){
            s=s;
        }else if(l==2){
            rep=s[1];
			s[1]=s[0];
			s[0]=rep;
        }else{
            s=null;
        }
    }
}