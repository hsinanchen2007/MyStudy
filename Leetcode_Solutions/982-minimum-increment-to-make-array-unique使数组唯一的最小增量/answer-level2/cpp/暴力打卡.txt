### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
		sort(A.begin(),A.end()); 
		vector<int>kong;
		for(int i=0,j=1;j<A.size();j++,i++)
		{
			if(A[i]==A[j])
				continue;
			int tem=A[i];
			while(tem+1!=A[j])
			{
				kong.push_back(tem+1);
				tem++;
			}
		}
		int res=0;
		int temp=0,j,cnt;
		int konnum=0;
		int endoff=1;
		for(int i=0;i<A.size();)
		{
			j=i+1;
			cnt=0;
			while(j<A.size()&&A[j]==A[i])
			{
				cnt++;
				j++;
			}				
			for(;cnt>0;cnt--)
			{
                while(konnum<kong.size()&&kong[konnum]<A[i])
					konnum++;
				if(konnum<kong.size())
					res+=kong[konnum++]-A[i];
				else
				{
					res+=A[A.size()-1]+endoff-A[i];
					endoff++;
				}
					
			}
			i=j;
		}
		return res;
    }
};
```