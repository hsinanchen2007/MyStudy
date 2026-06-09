'''c++
class Solution {
public:
    void quickSort(vector<int>& arr, int p, int r, int i){
        if(p<r){
            int q = partation(arr, p, r);
            int k = q-p+1;
            if(k==i){
                return ;
            }else if(i<k){
                quickSort(arr, p, q-1, i);
            }else{
                quickSort(arr, q+1, r, i-k);
            }
        }
    }
    int partation(vector<int>& arr, int p, int r){
        int x = arr[r];
        int i = p-1;
        for(int j=p;j<r;j++){
            if(arr[j]<x){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[++i], arr[r]);
        return i;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int p = 0;
        int r = arr.size()-1;
        if(k>=r+1){
            return arr;
        }
        quickSort(arr, p, r, k);
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};
'''