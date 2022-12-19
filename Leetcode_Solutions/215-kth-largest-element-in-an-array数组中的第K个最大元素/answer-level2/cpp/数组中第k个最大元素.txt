class Solution {
    
public:
    int findKthLargest(vector<int>& nums, int k)  {
        
        
    //利用优先队列，实质利用堆排序
    // priority_queue<int, vector<int>, greater<int>> pq;
    // for (auto& n : nums)
    // {
    //     if (pq.size() >= k && pq.top() >= n) 
    //         continue;
    //     pq.push(n);
    //     if (pq.size() > k)
    //     {
    //         pq.pop();
    //     }
    // }
    // return pq.top();
        
    //利用快排
    return quickSort(nums,0,nums.size()-1,k);
    }
    
    
    int quickSort(vector<int> &arr, int l, int r, int k) {
	    srand(time(NULL));
	    swap(arr[l], arr[rand() % (r - l + 1) + l]);

	    int v = arr[l];
	    int i = l + 1, j = r;
	    if (r <= l)
		    return arr[l];
	    while (i <= j) {
	    	while (i <= r && arr[i] < v) i++;
	    	while (j >= l + 1 && arr[j] > v) j--;
	    	if (i > j)
		    	break;
	    	swap(arr[i], arr[j]);

	    	i++;
	    	j--;
    	}
	    swap(arr[l], arr[j]);
    	if (j == arr.size() - k)
    		return arr[j];
    	else if (arr.size() - k > j)
	    	return quickSort(arr, j + 1, r, k);
    	else
    		return quickSort(arr, l, j - 1, k);
    }
};