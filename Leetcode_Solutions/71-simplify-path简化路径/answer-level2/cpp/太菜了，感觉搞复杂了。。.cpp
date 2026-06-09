class Solution 
{
    public:
    string simplifyPath(string path) 
	{
		vector<char> vec;
		int len=path.size();
		
		for(int i=0;i<len;i++)
		{
			if(i==0)vec.push_back('/');
			if(path[i]=='/')
			{
				if(vec.back()=='/')continue;
				else if(vec.back()=='.'&&*(vec.end()-2)=='/')vec.pop_back();
				else vec.push_back('/');
			} 
			else
			{
				int j=i;string str;
				while(j<len&&path[j]!='/')j++;
				if(j>i+2)
				{
					while(i<j){vec.push_back(path[i]);i++;}
					i--;
				}
				else if(j==i+2)
				{
					if(path[i]=='.'&&path[i+1]=='.')
					{
						if(vec.size()>=3)
						{
							vec.pop_back();
							while(vec.back()!='/')vec.pop_back();
						}
						i=j-1;
					}
					else 
					{
						while(i<j){vec.push_back(path[i]);i++;}
						i--;
					}
				}
				else if(j==len)
				{
					if(path[i]=='.')continue;
					else vec.push_back(path[i]);
				}
				else vec.push_back(path[i]);
			}
		}
		
		path.clear();
		vector<char>::iterator iter,last;
		iter=vec.begin();
		last=vec.end()-1;
		for(;iter<=last;iter++)path.push_back(*iter);
		if(*(path.end()-1)=='/'&&vec.size()!=1)*(path.end()-1)='\0';
		return path;
    }
};