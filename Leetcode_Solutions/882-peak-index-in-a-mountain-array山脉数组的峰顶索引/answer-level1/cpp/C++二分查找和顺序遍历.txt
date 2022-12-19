```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
//此处开始是二分查找
        int low = 0;
        int high = A.size() - 1;
        while (low <= high) 
        {
            int mid = low + ((high - low) >> 1);
            if ((A[mid] > A[mid + 1]) && A[mid] > A[mid - 1]) 
            {
                return mid;
            } 
            else if ((A[mid] > A[mid + 1]) && A[mid] < A[mid - 1]) 
            {
                high = mid - 1;
            } 
            else    
            {
                low = mid + 1;
            }
        }
        return -1;

        
//此处开始是顺序遍历
/*        int ans=0;
        int len=A.size();
        for(int i=1;i<len;i++)
        {
            int j=0,k=0;
            for(j=i+1;j<len;j++)
            {
                if(A[i]<A[j])
                {break;}
            }
            
            for(k=i+1;k>=0;k--)
            {
                if(A[k]>A[i])
                {break;}
            }
            if(j==len&&k==-1)
            {
                ans=i;
                break;
            }
        }
        return ans;
*/        
    }
};
```
