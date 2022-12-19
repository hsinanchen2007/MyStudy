bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        if(sum%3!=0) return false;
        int n=sum/3;
        int start=0,end=0;
        sum=0;
        int count=0;
        while(start<A.size()){
            sum+=A[start];
            if(sum==n){
                cout<<start<<endl;
                sum=0;
                count++;
            }
            start++;
        }
        if(count>=3){
            return true;
        }else{
            return false;
        }
    }