空间复杂度: O(N),时间复杂度O(NlogN)
```
class Solution {
    int res;
    int temp[50005];
public:
    int reversePairs(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return res;
    }
    void merge(vector<int> &nums,int l,int r)
    {
        if(l >= r) return;
        int mid = l + r >> 1;
        merge(nums,l,mid);
        merge(nums,mid+1,r);
        int i = mid, j = r,k = 0;
        while(i >= l && j >= mid + 1)
        {
            long a = nums[i];
            long b = nums[j];
            b += b;
            if(a <= b)
                j--;
            else{
                res += j - mid;
                i--;
            }
        }
        i = l,j = mid + 1;
        while(i <= mid && j <= r)
        {
            if(nums[i] > nums[j])
            {
                temp[k++] = nums[j++];
            }else{
                temp[k++] = nums[i++];
            }
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];
        for(i = l, k = 0; i <= r; i++)
            nums[i] = temp[k++];
    }
};
```
在merge中多加一周循环用来计算反转对个数，可以从大到小计算，时间复杂对为O(N)
算法时间复杂度为O(NlogN).
不过卡long long确实恶心了我一下
