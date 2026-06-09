前向差分
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if (A.empty())
        {
            return NULL;
        }
        //前向差分
        vector<int>::iterator it;
        for (it = A.begin()+1; it != A.end(); ++it)
        {
            if ( *(it-1)<*(it) && *(it)>*(it+1) )
            {
                // return it - A.begin();
                return distance(A.begin(), it);
            }
        }
        return NULL;
    }
};
```

最大值
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if (A.empty())
        {
            return NULL;
        }
        //最大值
        vector<int>::iterator biggest = max_element(A.begin(), A.end());
        return distance(A.begin(), biggest);
    }
};
```

二分查找
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if (A.empty())
        {
            return NULL;
        }
        //二分查找
        int p = 0, q = A.size()-1, k;
        while (p < q)
        {
            k = (p+q)/2;
            if (A[k-1]<A[k] && A[k]<A[k+1])
            {
                p = k + 1;
            }
            else if (A[k-1]>A[k] && A[k]>A[k+1])
            {
                q = k - 1;
            }
            else
            {
                return k;
            }  
        }
        return p;
    }
};
```
