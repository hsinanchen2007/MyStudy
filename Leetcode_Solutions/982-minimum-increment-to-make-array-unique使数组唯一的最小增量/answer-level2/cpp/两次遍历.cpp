和官方答案思路差不多，找到重复数字和漏掉的数字，相减。
可能数组比map更省时间
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty()) return 0;
        int min=*min_element(A.begin(),A.end());
        int max=*max_element(A.begin(),A.end());
       map<int,int> m;
       for(auto a:A){
           ++m[a];
       }
       int sub=0,add=0,cnt=0;
       for(int i=min;i<max+A.size();++i){
           if(m.find(i)!=m.end()){
               cnt+=m[i]-1;
               sub+=(m[i]-1)*i;
           }
           else if(cnt>0){
               add+=i;
               --cnt;
           }
       }
       return add-sub;
    }
};
```
