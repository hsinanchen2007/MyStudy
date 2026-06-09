class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0]=1;
        for(int i=1;i<rowIndex+2;i++){
            for(int j=i-1;j>0;j--){
                if(j==i-1)
                    res[j]=1;
                else   res[j]=res[j]+res[j-1];
            }
        }
        return res;
    }
};