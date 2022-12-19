    double myPow(double x, int n){
        //先考虑一波特殊情况
        if(n == 0){
            return 1;
        }
        
        if(x == 1){
            return 1;
        }else if(x == -1){
            if(n % 2 == 0)
                return 1;
            else
                return -1;
        }
        
        int flag = 0;
        
        if(n < 0){
            if(n == INT_MIN){
                flag = 2;
                n = INT_MAX;
            }else{
                flag = 1;
                n = -n;
            }
        }
        
        if(n == INT_MAX){
            n--;
            flag = 3;
        }
        
        double res = x; 
        double tmp = res;
        int count = 1 ;
        int index = 1;
        
        while(index != n && res <= 1.7*pow(10, 308)){
            if(index > n - count){
                count = 1;
                tmp = x;
            }
            res*=tmp;
            tmp*=tmp;
            if(index <= n - count)
                index+=count;
            count*=2;   
        }
        
        if(res > 1.7*pow(10, 308)){
            return 0;
        }
        
        if(flag == 0){
            return res;        
        }else if(flag == 1){
                return (double)1/res;
        }else if(flag == 2){
            return (double)1/(res*x);
        }else{
            return res*x;
        }    
    }