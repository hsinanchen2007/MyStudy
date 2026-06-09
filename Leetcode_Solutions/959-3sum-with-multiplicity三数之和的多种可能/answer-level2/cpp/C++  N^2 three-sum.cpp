```
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int,int> Map;
        for(int t:A) {
            Map[t]++;
        }
        map<int, int>::iterator it=Map.begin();
        vector<int> arr;
        arr.reserve(A.size());
        for(;it!=Map.end();it++) {
            arr.push_back(it->first);
        }
        int len=arr.size();
        long long res=0;       // 注意数据范围
        const int m=1000000007;
        for(int i=0;i<len;i++) {
            long long count_i=Map[arr[i]];
            if(count_i>=3&&arr[i]*3==target) {
                res=(res+count_i*(count_i-1)*(count_i-2)/6)%m;
            } 
            for(int j=i+1;j<len;j++) {
                long long x=target-arr[i]-arr[j];
                if(Map.find(x)!=Map.end()) {
                    int count_j=Map[arr[j]];
                    if(x>arr[j]) {
                        res=(count_i*count_j*Map[x]+res)%m;
                    }else if(x==arr[j]){
                        res=(count_i*count_j*(count_j-1)/2+res)%m;
                    }else if(x==arr[i]){
                        res=(count_j*count_i*(count_i-1)/2+res)%m;
                    }
                }
            }
        }
        return res;
    }
};
```
