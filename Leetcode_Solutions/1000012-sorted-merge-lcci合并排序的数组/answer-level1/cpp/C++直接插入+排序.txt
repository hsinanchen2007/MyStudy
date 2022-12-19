其实逆向双指针比较符合题意吧。。不过我懒，直接插入排序，也快
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int step = A.size() - m;
        for(;step>0;step--)
            A.pop_back();
        for(auto i :B)
            A.push_back(i);
        sort(A.begin(),A.end());
    }
```
