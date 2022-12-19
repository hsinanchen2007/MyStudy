### 解题思路
达到O（logn）级别的复杂度最简单的应该就是归并排序了，归并排序这里不做讲解，merge和mergesort就可以完成排序，去掉mergesort中我写注释的if语句就是归并排序的模板代码。

### 代码

```cpp
class Solution {
public:
//初始化，记录tar目标值，pos目标值所在位置
	int tar=0,pos=-1;
    int search(vector<int>& nums, int target) {
//将目标值赋给tar使得可以在其他函数中访问，不需要在递归函数中创建变量节省空间
        tar=target;
//针对传入的数组为空或长度为1进行讨论因为后面归并函数对长度为一的数组不做排序操作无法判断
        if(nums.size()==0)
        	return pos;
        if(nums.size()==1)
        {
        	if(nums[0]==tar)
        		return 0;
        	else
        		return pos;
		}
//进行归并排序
        merge(nums,0,nums.size()-1);
        return pos;
    }
    void merge(vector<int> &arr,int low,int high)
    {
    	if(low<high)
    	{
    		int mid=(low+high)/2;
    		merge(arr,low,mid);
    		merge(arr,mid+1,high);
    		mergesort(arr,low,mid,high);
		}
	}
	void mergesort(vector<int> arr,int low,int mid,int high)
	{
		int p1=low,p2=mid+1,size=high-low+1,i=0;
		vector<int>temp(size,0);
		while(p1<=mid&&p2<=high)
		{
			if(arr[p1]<arr[p2])
				temp[i++]=arr[p1++];
			else
				temp[i++]=arr[p2++];
		}
		while(p1<=mid)
			temp[i++]=arr[p1++];
		while(p2<=high)
			temp[i++]=arr[p2++];
		for(i=0;i<size;i++)
		{
//在这里进行比较，找到则记录下标
			if(arr[low+i]==tar)
				pos=low+i;
			arr[low+i]=temp[i];
		}
			
	}
};
```