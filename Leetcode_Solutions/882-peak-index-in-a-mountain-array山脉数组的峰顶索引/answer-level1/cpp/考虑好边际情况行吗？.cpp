```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low=0,high=A.size()-1,mid;
        while(low<=high){
	        mid=((unsigned)low+(unsigned)high)>>1;
			if(mid==0||mid==A.size()-1)
				return mid;
			if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) 
            	return mid;
        	else if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1]) 
            	high = mid - 1;
        	else 
            	low = mid + 1;
        }
		return low;
    }
};
```
if else结构没什么说的，上面添加一个查找的边际判断，就是正常的了【否则数组溢出】。
真不知道以前的怎么过了，一个个的都不考虑溢出，关键是截图显示居然过了？？？
