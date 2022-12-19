执行用时 :1 m, 在所有 Java 提交中击败了100.00%的用户

内存消耗 :33.8 MB, 在所有 Java 提交中击败了76.25%的用户

所有的乘除都转换成移位
```
class Solution {
   public int divide(int dividend, int divisor) {
            int sign = 1;
	        if(dividend==Integer.MIN_VALUE&&divisor==-1)return Integer.MAX_VALUE;//这里的到的商会溢出，所以直接返回
	        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))sign=-1;//确定正负号
	        if(dividend>0)dividend*=-1;//将正数转换为负数
	        if(divisor>0)divisor*=-1;
	        
	        int result=divider(dividend,divisor,0);
	        return result*sign;
	}
	    
	    public int divider(int dividend,int divisor,int result){
	        if(dividend>divisor)return result;
	        int tmp = divisor;
            int j = 0;
	        while(dividend<=tmp){
	            int i = (1<<j);
	            dividend-=tmp; 
                if(tmp>=Integer.MIN_VALUE>>1)tmp<<=1;//每次都double一下
	            result+=i;
                j++;
	        }
	        return divider(dividend,divisor,result);
	    }

}
```












