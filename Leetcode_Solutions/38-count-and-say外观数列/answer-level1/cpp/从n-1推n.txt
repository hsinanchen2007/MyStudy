

class Solution {
public:
    string countAndSay(int n) {
        //前一项是countAndSay(n-1)
        string s;
        if(n == 1){
            s = '1';
        }else
        {
            string p = countAndSay(n-1);
            int i = 0;
            int len = p.size();
            int cont = 1;
            int x=0;
            //312211
            for(i=0;i<len;i++)
            {
                if(p[i] == p[i+1])
                {
                    cont++;
                }else{
                    char c = cont + '0';
                    s += c ; 
                    s += p[i];
                   
                    cont = 1;
                }
            }

        }

        return s;
    }
};
