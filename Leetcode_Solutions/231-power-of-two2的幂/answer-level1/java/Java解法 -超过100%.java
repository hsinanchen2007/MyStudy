  2的幂，写成二进制，1的个数肯定只有一个,判断有一个1即可，直接套用java函数即可
// 若二进制数只有一个1，满足条件
	   if(n<0) return false;
	   int b =Integer.bitCount(n);
	   return b==1?true:false;