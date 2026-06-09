    vector<int> constructArr(vector<int>& a) {
        int len=a.size();
        vector<int> b(len,1);
        int leftProduct=1;
        int rightProduct=1;
        for(int i=0;i<len;i++){
            b[i]*=leftProduct;
            leftProduct*=a[i];
        }
        for(int i=len-1;i>=0;i--){
            b[i]*=rightProduct;
            rightProduct*=a[i];
        }
        return b;
    }
