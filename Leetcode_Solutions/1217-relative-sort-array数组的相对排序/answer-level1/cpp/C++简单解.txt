class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int q=0;
        for(int i=0;i<m;i++){
            int p=arr2[i];
            for(int j=0;j<n;j++){
                if(arr1[j]==p){
                    swap(arr1[q],arr1[j]);
                    q++;
                }
            }
        }
        sort(arr1.begin()+q,arr1.end());
        return arr1;
    }
};