```
class Solution {
public:
    void  merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> res;
        int i=0,j=0;
        while(i<m && j<n){
            if (A[i]>B[j]){
                res.push_back(B[j++]);
            }
            else res.push_back(A[i++]);
        } 
        //cout <<i<<j<<endl;
        if(i==m)
            while(j<n){
                res.push_back(B[j++]);
            }
        else while(i<m){
                res.push_back(A[i++]);
            }
        A=res;
    }
};
```

1.新建一个vector<int> res存储结果，对比A、B 中元素选小的加入res，A为空后将B中剩下的拷贝给res；

太菜了，只能想到这种办法，之前还看到过别人不开新的空间，
2.**在A上从后往前插入元素，按从大到小从**  A、B中选元素方法也是从后往前选大的
计算好开始插入的位置为 A[m+n-1]
实现起来也很简单，太机智了 >_<

