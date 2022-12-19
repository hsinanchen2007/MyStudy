思路：办法比较笨，主要是找规律，我用数字来代替字母看起来比较直观
0   4   8     12
1 3 5 7 9  11 13
2   6   10    14
这是三行的情况，我们再来看看4行的情况
1     7       13
2   6 8    12 14
3 5   9 11    15
4     10      16
这样，我们就能看清规律，以四行为例，第一行和最后一行间隔都为6((4-1)*2),第二行间隔为4 2 4 2 4 2，第三行间隔为2 4 2 4 2 4。这样，我们就能根据每一行的间隔规律来求结果 代码如下
 string convert(string s, int numRows) {
	int stringSize=s.size();
	int maxDouble=(numRows-1)*2;
	if(stringSize<=numRows)
	{
		return s;
	}
    if(numRows==1)
    {
        return s;
    }
	string result=s;
	vector<int> s1;
	for(int i=maxDouble;i>0;i-=2)
	{
		s1.push_back(i);
	}
	s1.push_back(maxDouble); 
	int i=0;
	for(int k=0;k<numRows;k++)
	{
		//主要是增量的问题
		int start=k;
		int increNum=1;
		while(start<stringSize)
		{
			//判断是增加哪个量
			
			if(k==0||k==numRows-1)
			{
				//第一层或最后一层
				result[i]=s[start];
				start+=maxDouble;

			}
			else
			{
				if(increNum%2==1)
				{	//奇数次
					result[i]=s[start];
					start+=s1[k];			
				}
				if(increNum%2==0)
				{
					result[i]=s[start];
					start+=maxDouble-s1[k];
				}
				increNum++;
			}			
			i++;
		}
	}
	return result;	
}