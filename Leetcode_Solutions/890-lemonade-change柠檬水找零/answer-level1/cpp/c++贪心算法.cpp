class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 判断特殊情况
        if(bills[0] != 5)
            return false;
        if(bills.size()==0)
            return true;
        
        //分别处理三种情况。利用map容器记录手头的所有零钱张数
        map<int, size_t> bill_count;
        for(int &bill: bills){
            ++bill_count[bill];
            if(bill==5)
                continue;
            if(bill==10){
                if(bill_count[5]==0)
                    return false;
                --bill_count[5];
                continue;
            }
            if(bill==20){
                if(bill_count[10]==0){
                    if(bill_count[5] < 3)
                        return false;
                    else{
                        bill_count[5] -= 3;
                    }
                }
                else{
                    if(bill_count[5] == 0)
                        return false;
                    else{
                        bill_count[5] -= 1;
                        bill_count[10] -=1;
                    }    
                }
                   
            }
        }
        return true;
    }
};