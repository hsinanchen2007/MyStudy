class Solution {
public:
    string toGoatLatin(string S) {
	int i,j,k;
	string tmp="";
	string result;
	vector <string> A;
	for(i=0;i<S.size();i++)
	{
		if(S[i]!=' ') tmp+=S[i];
		else{
			A.push_back(tmp);
			tmp="";
		}
	}
	A.push_back(tmp);
	for(i=0;i<A.size();i++)
	{
        if(A[i][0]=='a'||A[i][0]=='e'||A[i][0]=='i'||A[i][0]=='o'||A[i][0]=='u'
		||A[i][0]=='A'||A[i][0]=='E'||A[i][0]=='I'||A[i][0]=='O'||A[i][0]=='U')
		{
			A[i]=A[i]+"ma";
			for(k=0;k<i+1;k++)
			{
				A[i]=A[i]+"a";
			}
		}	
		else{
			char a=A[i][0];
			for(j=0;j<A[i].size()-1;j++)
			{
				A[i][j]=A[i][j+1];
			}
			A[i][j]=a;
			A[i]=A[i]+"ma";
			for(k=0;k<i+1;k++)
			{
				A[i]=A[i]+'a';
			}
		}
	}
	for(i=0;i<A.size()-1;i++)
	{
		result=result+A[i]+" ";
	}
	result=result+A[i];
	return result;
    }
};
![QQ图片20200316163502.png](https://pic.leetcode-cn.com/839ca0ce46e8e3c88dbc8c6cab8d6ca3b5c9b5fe4157de6fc6f9767faaa5a005-QQ%E5%9B%BE%E7%89%8720200316163502.png)
