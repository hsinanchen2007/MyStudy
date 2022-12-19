class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int ans=2;
        unordered_set<int> m;
        for(int i=0;i<A.size();++i){
            m.insert(A[i]);
        }
        int first,second;
        for(int i=0;i<A.size()-ans+2;++i){
            first=A[i];
            for(int j=i+1;j<A.size()-ans+2;++j){
                second=A[j];
                //cout<<"**************************"<<second<<endl;
                int temp=2;
                while(m.count(first+second)){
                    //cout<<first<<"   "<<second<<endl;
                    temp+=1;
                    first=first+second;
                    swap(first,second);
                }
                first=A[i];
                ans=max(ans,temp);
            }
        }
        return ans==2?0:ans;
    }
};