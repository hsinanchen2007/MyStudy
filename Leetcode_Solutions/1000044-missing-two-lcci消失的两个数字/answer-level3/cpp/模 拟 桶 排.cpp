完整的序列包含1-N的所有元素，考虑做桶排，最后空出来的就是答案。
那么怎么用O(1)的空间完成呢？考虑某个下标i，设其值为a[i]，则a[i]应该在排序后位于a[i]-1的下标处
记p=a[i]-1
1. p==i 则a[i]排序前和排序后位置相同，++i
2. p!=i 则a[i]排序后应该在p的位置，swap(a[p],a[i])，注意，此时i不能++，还要判断a[p]的位置
3. a[i]==0 哈哈，这位置就是答案了，++i
因为每个元素最多只会被访问2次，也最多被交换2次，因此时间仍是O(n)，同时显然空间也是O(n)
```
class Solution {
public:
    vector<int> missingTwo(vector<int>& A) {
        A.push_back(0);
        A.push_back(0);
        int n=A.size();
        vector<int> Ans;
        for (int i=0;i<n;)
            if (!A[i]) Ans.push_back(i+1),++i;
            else if (A[i]==A[A[i]-1]) ++i;
            else swap(A[i],A[A[i]-1]);
        return Ans;
    }
};
```
