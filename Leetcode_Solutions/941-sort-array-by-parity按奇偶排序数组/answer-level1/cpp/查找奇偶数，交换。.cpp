//解题思路：从前往后找奇数，从后往前找偶数，找到后交换，依次查找，直至奇偶下标之和等于数组长度。



    vector<int> sortArrayByParity(vector<int>& A) {
        int i =0;
        int oddnum = 0;
        while(i+oddnum !=A.size()){
            if(A[i]%2 != 0 && A[A.size()-1-oddnum]%2 ==0){
                swap(A[i],A[A.size()-1-oddnum]);
                ++i;++oddnum;
            }
            else if(A[i]%2 != 0 && A[A.size()-1-oddnum]%2 !=0){
                ++oddnum;}
            else if(A[i]%2 == 0 && A[A.size()-1-oddnum]%2 ==0){
                ++i;}
                else { ++i;++oddnum;}

        }
        return A;
    }
