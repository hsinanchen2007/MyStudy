```
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m==0)nums1=nums2;
        else if(n==0)nums1=nums1;
        else
        {
            int i,j,k;
            for( i=m-1,j=n-1,k=1; j>=0; )
            {
                if(nums1[i]<=nums2[j])
                {
                    nums1[n+m-k]=nums2[j];
                    j--;
                    k++;
                }
                else
                {
                    nums1[n+m-k]=nums1[i];
                    i--;
                    k++;
                    if(i<0)
                    {
                        while(j>=0)
                        {
                            nums1[j]=nums2[j];
                            j--;
                        }
                    }
                }
            }
        }
    }
};
```
