```
class Solution {
    vector<pair<int,int>> q;
public:
    int getKth(int lo, int hi, int k) {
        for(int i = lo;i <= hi;i++)
            q.push_back({getPath(i),i});
        return quick_sort(0,q.size()-1,k);
    }
    int quick_sort(int l,int r,int k)
    {
        if(l==r) return q[l].second;
        int i = l - 1, j = r + 1;
        auto x = q[l];
        while(i < j)
        {
            do i++; while(checkI(q[i],x));
            do j--; while(checkJ(q[j],x));
            if(i < j) swap(q[i],q[j]);
        }
        int sl = j - l + 1;
        if(sl >= k)
            return quick_sort(l,j,k);
        else return quick_sort(j+1,r,k-sl);
    }
    bool checkI(pair<int,int> a,pair<int,int> b)
    {
        if(a.first < b.first) return true;
        if(a.first == b.first)
            if(a.second < b.second) return true;
        return false;
    }
    bool checkJ(pair<int,int> a,pair<int,int> b)
    {
        if(a.first > b.first) return true;
        if(a.first == b.first && a.second > b.second) return true;
        return false;
    }
    int getPath(int x)
    {
        int pace = 0;
        while(x!=1)
        {
            if(x%2==0) 
            {
                x /= 2;
                pace++;
            }else{
                x = 3 * x + 1;
                pace++;
            }
        }
        return pace;
    }
};
```
