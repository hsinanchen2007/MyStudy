### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        if(citations.empty()) return 0;

        int h=0,n=citations.size();
        sort(citations.begin(),citations.end());
        //QuickSort(citations,0,n-1);

        for(int i=0;i<n;i++)
            if(n-i<=citations[i] && n-i>h) h=n-i; 
        
        return h;
    }

    //写着加深印象,实际上用了c++ sort函数
    void QuickSort(vector<int>& a,int first,int last)
    {
        if(last-first<1) return;
        int low=first,high=last,key=a[low];

        while(low!=high)
        {
            while(low!=high && a[high]>=key) high--;
            a[low]=a[high];

            while(low!=high && a[low]<key) low++;
            a[high]=a[low]; 
        }

        a[high]=key;

        QuickSort(a,first,high-1);
        QuickSort(a,high+1,last);
    }
};
```