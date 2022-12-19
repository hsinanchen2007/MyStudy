执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了67.72%的用户

`int mySqrt(int x){

        int wideflag,headNum,endNum,midNum,midNumSquare;
	
        headNum = 0;
        endNum = 46341;
		while(1)
		{            
			if(endNum - headNum == 1)
				return headNum;			
			midNum = (endNum + headNum) / 2;
			midNumSquare = midNum * midNum;
			if(midNumSquare < x)
					headNum = midNum;
			else if(midNumSquare > x)
					endNum = midNum;
			else
					return midNum;
		}		
        return 0;
    }`