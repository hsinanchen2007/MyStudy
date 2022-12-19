```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i;
        if(A.size()<3)
        	return 0;
        for(i=0;i<A.size()-1;i++){//定位符合条件的山顶下标
        	if(A[i]>A[i+1])
				break;
			else if(A[i]==A[i+1])
				return 0;
		}
		if(i>=A.size()-1||i==0)//山顶为头结点或尾结点都不行
			return 0;
		for(;i<A.size()-1;i++){//判断后半山脉是否符合山脉定义
			if(A[i]<A[i+1]||A[i]==A[i+1])
				return 0;
		}
		return 1;
    }
};
```
