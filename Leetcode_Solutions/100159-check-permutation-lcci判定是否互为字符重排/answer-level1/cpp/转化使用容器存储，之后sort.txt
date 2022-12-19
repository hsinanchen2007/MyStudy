先比较两字符串长度
再将字符串分别使用容器存储，利用sort排序之后比较容器是否相等
```
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        vector<string> A(s1.size());
        vector<string> B(s2.size());
        for(int i=0;i<s1.size();i++){
            A[i]=s1[i];
            B[i]=s2[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return A==B;
    }
};
```
