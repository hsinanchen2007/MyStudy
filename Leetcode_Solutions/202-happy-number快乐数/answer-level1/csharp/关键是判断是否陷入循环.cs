 public bool IsHappy(int n) {
        List<int> exist = new List<int>();
        int p=0, sum=0;
        while(true){
            p = n%10;
            n/=10;
            sum = p*p+sum;
            if(n==0){
                if(exist.Contains(sum)) {return false;}
                else if(sum==1) {return true;}
                else {exist.Add(sum);n=sum;sum=0;}
        }       
        }
       
    }