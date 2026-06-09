### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<string> res;

    string largestNumber(vector<int>& nums) 
    {
        vector<string> A; 
        for(int i:nums) A.push_back(to_string(i));

        res=A;
        MergeSort(A,0,A.size()-1);

        string s;
        for(string a:A) s+=a;
        if(s[0]=='0') return "0";
        return s;
    }

    //这里我采用归并排序
    void MergeSort(vector<string>& A,int low,int high)
    {
        if(high-low<1) return;

        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
    void Merge(vector<string>& A,int low,int mid,int high)
    {
        int i=low,j=mid+1,r=low;

        while(i<=mid && j<=high)
        {
            if(A[i]+A[j]>A[j]+A[i]) res[r++]=A[i++];
            else res[r++]=A[j++];
        }

        while(i<=mid) res[r++]=A[i++];
        while(j<=high) res[r++]=A[j++];

        while(low<=high) A[low]=res[low],low++;
    }
};
```