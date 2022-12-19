贪心算法: 从前往后比较字符串上的字符, 通过删除那些破坏顺序的列来逐步构建顺序.

(S1). 用一个向量来记录当前不确定是否排好顺序的那些字符串: 让j记录当前研究的列, 若 A[i] 和 A[i+1] 的前j列完全一样, 那个 i 就包含在 vec 里. 初始化时, vec={0, 1,2,...,A.size()-2};

(S2).若 j 列破坏了之前的顺序, 那么删除 j 列, 结果加1; 若 j 列没破坏之前排序, 那么不删除, 但是新增加的 j 列可能会区分开之前不能区分的字符串 A[i][0:j-1] 和 A[i+1][0:j-1], 因此要更新 vec；

(S3).若 vec 是空的, 就说明已经排好序了, 不需要再继续了, 返回结果, 否则继续检查下一列 j+1 列.

```angelscript
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m=A.size();
        int n=A[0].size();
        
        vector<int> vec;
        for (int i=0; i+1<m; i++)
            vec.push_back(i);
        
        int ans=0;
        int j=0;
        bool sorted=false;
        while(!sorted && j<n){
            int del=0;
            for (int i: vec)
                if (A[i][j]>A[i+1][j]){
                    del=1;
                    ans+=1;
                    break;
                }
            
            if (del==0){
                vector<int> tmp;
                for (int i:vec){
                    if (A[i][j]==A[i+1][j])
                        tmp.push_back(i);
                }
                vec=tmp;
            }
            
            if (vec.empty())
                sorted=true;
    
            j++;
        }
   
        return ans;
    }
};
```
