#define min(a,b) ((a)<(b)?(a):(b))

int leftmax(int* numarr, int numi,int numsize)
{
	int maxtrap = 0;
	
	for (int i=0;i<numi;i++)
	{
		if (numarr[i]>maxtrap)
		{
			maxtrap = numarr[i];
		}
	}
	
	return maxtrap;
	
}

int rightmax(int* numarr, int numi,int numsize)
{
	int maxtrap = 0;
	
	for (int i=numi;i<numsize;i++)
	{
		if (numarr[i]>maxtrap)
		{
			maxtrap = numarr[i];
		}
	}	
	return maxtrap;
}

int trap(int* height, int heightSize)
{
    //快排找出最大值
	int  result = 0;
	int maxleft,maxright;

	for (int i =1;i<heightSize-1;i++)
	{
		maxleft = leftmax(height,i,heightSize);
		maxright = rightmax(height,i,heightSize);

		int res = min((maxleft-height[i]),(maxright -height[i]));
		if (res<0)	res = 0;	

		result +=res;
	}
	
	return result;
}