#双指针遍历一次

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size()-1;
        while(i<j){
            if(A[i]%2 == 0){
                i++;
            }else{
                if(A[j]%2 == 0){
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                    i++;
                    j--;
                }else{
                    j--;
                }
            }
        }
        return A;
    }
};