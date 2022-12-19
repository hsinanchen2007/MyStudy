class Solution {
    public:
        bool canThreePartsEqualSum(vector<int>& A) {
                int sum = 0;
                        for(int i = 0; i < A.size(); i++){sum += A[i];}
                                int tmp = 0, flag = 0;
                                        for(int i: A){
                                                    tmp += i;
                                                                if(tmp == sum / 3)
                                                                            {tmp = 0; flag++;}
                                                                                    }
                                                                                            return flag >= 3;
                                                                                                }
                                                                                                };
}