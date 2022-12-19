执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了88.89%的用户
```
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> times;
        vector<int> legalTimes;
        int tmp=0;
        int result=0;
        
        //求全排列
        sort(A.begin(),A.end());  //调用next_permutation求全排列的时候必须先给容器排序
        do{
            for(int i=0;i<A.size();i++){
                tmp += A[i]*pow(10,3-i);
            }
            times.push_back(tmp);
            tmp=0;
        }while(next_permutation(A.begin(),A.end()));
        
               //找出合法的排列
               for(int i=0;i<times.size();i++){
                   if(times[i]>2359)continue;
                   else if(times[i]%100>59)continue;
                   else{
                       legalTimes.push_back(times[i]);
                   }
               }
        if(legalTimes.size()==0)return "";
               for(int i=0;i<legalTimes.size();i++){
                   if(legalTimes[i]>result){
                       result=legalTimes[i];
                   }
               }
               
               string largestTimeFromDigits = to_string(result);
                //string左边补0
               while(largestTimeFromDigits.length()<4){
                   largestTimeFromDigits = "0"+largestTimeFromDigits;
               }
               largestTimeFromDigits.insert(2,":");
               return largestTimeFromDigits;
    }
};
```
