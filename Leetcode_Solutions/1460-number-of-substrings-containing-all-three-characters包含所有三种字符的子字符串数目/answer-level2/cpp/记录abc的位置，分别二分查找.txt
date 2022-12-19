
- 先顺序记录下所有的 a,b,c 的位置，存储于 pa，pb，pc
- 然后遍历 pa，pb，pc 分别以a开头，b开头，c开头查找，开始的下标`start`是知道的
- 然后在另外两个数组里二分查找，第一个比`start`大的下标
- 如果都存在另外两个下标比`start`大，那么可有的子串数就是 `s-size()-最大的下标`

```cpp
class Solution {
	vector<int> pa;
	vector<int> pb;
	vector<int> pc;
public:
    int numberOfSubstrings(string s) {
    	int i,x,y;
    	for(i = 0; i < s.size(); i++)
    	{	//记录abc的下标
    		if(s[i] == 'a')
    			pa.push_back(i);
    		else if(s[i] == 'b')
    			pb.push_back(i);
    		else
    			pc.push_back(i);
    	}
    	if(pa.empty() || pb.empty() || pc.empty())
    		return 0;
    	int count = 0;
    	for(auto& idxa : pa)
    	{
    		x = bsfirst(idxa,pb);//二分查找第一个大于idxa的下标
    		y = bsfirst(idxa,pc);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pb[x],pc[y]);
    	}
    	for(auto& idxb : pb)
    	{
    		x = bsfirst(idxb,pa);
    		y = bsfirst(idxb,pc);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pa[x],pc[y]);
    	}
    	for(auto& idxc : pc)
    	{
    		x = bsfirst(idxc,pb);
    		y = bsfirst(idxc,pa);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pb[x],pa[y]);
    	}
    	return count;
    }

	int bsfirst(int idx, vector<int>& v)
	{	//二分查找，第一个比idx大的数
		int l = 0, r = v.size()-1, mid;
		while(l <= r)
		{
			mid = l+((r-l)>>1);
			if(v[mid] < idx)
				l = mid+1;
			else if(v[mid] > idx)
			{
				if(mid == 0 || v[mid-1] < idx)
					return mid;
				else
					r = mid-1;
			}
		}
		return -1;
	}
};
```
执行用时：76 ms
内存消耗：17.3 MB
