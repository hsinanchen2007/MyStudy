1.暴力法时间复杂度O(n*n)，会超时。
2.利用归并排序
    归并本质就是2分，在左右数组合并的时候，检测左大于右的次数，即可以组成有序对的个数
```
class Solution {
public:

vector<int> merge(vector<int> &ll, vector<int> &rr)
{
	int l1 = ll.size();
	int l2 = rr.size();
	vector<int> tt;
	int i = 0 ,j = 0;
	while (i < l1 && j < l2)
	{
		if (ll[i] <= rr[j])
		{
			tt.push_back(ll[i]);
			++i;
		}
		else
		{
			cou += (l1 - i);//每次插入右数组的值时，就代表左数组剩下的值都比他大，可以组成有序对。
			tt.push_back(rr[j]);
			++j;
		}
	}
	if (i < l1)
	{
		tt.insert(tt.end(), (ll.begin() + i), ll.end());
	}
	else
	{
		tt.insert(tt.end(), (rr.begin() + j), rr.end());
	}
	return tt;
}

vector<int> guibin_sort(vector<int> & c1)
{
	int len = c1.size();
	if (len == 1)
		return c1;
	int mid = len / 2;
	vector<int> ll,rr;
	ll.assign(c1.begin(), (c1.begin() + mid));
	rr.assign((c1.begin() + mid), c1.end());
	ll = guibin_sort(ll);
	rr = guibin_sort(rr);
	return merge(ll, rr);
}

    int reversePairs(vector<int>& nums) {
        int cc = 0;
        cou = 0;
        if(nums.empty())
            return cc;
        nums = guibin_sort(nums);

        return cou;
    }
    static int cou;
};
int Solution::cou = 0;
```
