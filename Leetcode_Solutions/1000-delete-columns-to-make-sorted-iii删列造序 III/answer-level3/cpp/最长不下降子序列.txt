题目思路来源于最长不下降子序列，只是这里的偏序关系（x<=y）定义为:第y列的元素大于第x列的对应行的元素。
最终答案为字符串长度 减去 最长不下降子序列长度
```
class Solution {
public:
    bool cmp(int x,int y,vector<string>& A){ //x <= y
        int len = A.size();
        for(int i=0;i<len;i++){
            
            if(A[i][x] > A[i][y]) return false;
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& A) {
        
        int n = A[0].size();
        
        for(int i=0;i<n;i++){
            
            f[i]=1;
            for(int j=0;j<i;j++){
                
                if(cmp(j,i,A))f[i] = max(f[i],f[j]+1);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans,f[i]);
        
        return n-ans; 
    }
private:
    int f[101];
};
```
