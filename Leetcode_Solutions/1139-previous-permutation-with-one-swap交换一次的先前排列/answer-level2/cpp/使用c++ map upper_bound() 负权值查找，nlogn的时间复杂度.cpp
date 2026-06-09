使用c++ map upper_bound() 负权值查找，nlogn的时间复杂度 36ms
```
typedef pair<int,int> ii;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        map<int,int> dict;
        int n=A.size();
        for(int i=n-1;i>=0;i--){
            auto it=dict.upper_bound(-A[i]);
            if(it!=dict.end()){
                int temp=A[i];
                A[i]=A[it->second];
                A[it->second]=temp;
                break;
            }
            dict[-A[i]]=i;
        }
        return A;
    }
};
```
