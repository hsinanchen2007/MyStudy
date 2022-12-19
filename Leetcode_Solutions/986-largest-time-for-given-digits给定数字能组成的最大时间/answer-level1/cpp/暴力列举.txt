class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) 
    {
       
        int max=-1;
        int e;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(i!=j)
                for(int k=0; k<4; k++) 
                {
                    if(j!=k&&i!=k)
                    {

                        e=A[i]*1000+A[j]*100+A[k]*10+A[6-i-j-k];
                        if(e<2400&&e%100<60) 
                        {
                            if(max<e)
                            max=e;
                        }
                    }
                }
            }
        }
        if(max==-1)
            return "";
        string a = to_string(max);
          
        while(a.length()<4)
        {
            a = "0"+a;
        }
        a.insert(2,":");
        return a;

    }
};