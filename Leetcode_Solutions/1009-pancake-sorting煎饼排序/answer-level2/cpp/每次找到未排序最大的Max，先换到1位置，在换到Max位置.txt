```
    vector<int> pancakeSort(vector<int>& A) {
        int max=A.size();
        vector<int> vec;
        while(max!=1){
            for(int i=0;i<max;i++){
                if(A[i]==max){
                    vec.push_back(i+1);
                    vec.push_back(max);
                    reverse(A.begin(),A.begin()+i+1);
                    reverse(A.begin(),A.begin()+max);
                    max--;
                    break;
                }
            }
        }
        return vec;
    }
```
