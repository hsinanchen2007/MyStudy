class Solution {
public:
    int binaryGap(int N) {
    int i,k=0,max=0;
	vector <int> binary;
	vector <int> LocateOne;
	while(N!=0)
	{
		i=N%2;
		if(i==1) LocateOne.push_back(k);
		k++;
		binary.push_back(i);
		N=N/2;
	}
	if(LocateOne.size()==1) return 0;
	else{
		for(i=1;i<LocateOne.size();i++)
		{
			if((LocateOne[i]-LocateOne[i-1])>max)
			max=LocateOne[i]-LocateOne[i-1];
		}
	}
	return max;
    }
};