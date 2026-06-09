执行用时 :3 ms, 在所有 Java 提交中击败了94.76%的用户
内存消耗 :34 MB, 在所有 Java 提交中击败了76.01%的用户
使用位运算
```
class Solution {
   public int divide(int dividend, int divisor) {
       	if(divisor==0) return Integer.MAX_VALUE;
		//最小值  负数对于正数
		if(dividend==Integer.MIN_VALUE){
			if(divisor==-1){
				return Integer.MAX_VALUE;
			}else if(divisor==1){
				return Integer.MIN_VALUE;
			}
		}
		//将负数操作全部转换为正数  sign符号位
		long divd=(long)dividend;
		long divs=(long)divisor;
		int sign=1;
		if(divd<0){
			divd=-divd;
			sign=-sign;
		}
		if(divs<0){
			divs=-divs;
			sign=-sign;
		}
		
		int res=0;
		while(divd>=divs){
			int shift=0;
			while(divd>=divs<<shift){
				shift++;
			}
			//加上结果
			res+=(1<<(shift-1));
			//减去值
			divd-=(divs<<(shift-1));
		}
        return sign*res;
   }
}
```
