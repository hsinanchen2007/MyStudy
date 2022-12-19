class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int* coin = new int[3]();
        int L = bills.size();
        for(int i=0; i<L; i++){
            if(bills[i] == 5) coin[0]++;
            else if(bills[i] == 10){
                coin[1]++;
                coin[0]--;
                if(coin[0] < 0) return false;
            }
            else{
                coin[2]++;
                if(coin[1] > 0){
                    coin[1]--;
                    coin[0]--;
                    if(coin[0] < 0) return false;
                }
                else{
                    coin[0] -= 3;
                    if(coin[0] < 0) return false;
                }
            }
        }
        return true;
    }
};