class Solution {
public:
    
    string small[20]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                      "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string decade[10]={" "," ","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string big[4]={"Billion","Million","Thousand"," "};//倒序
    
    string numberToWords(int num) {
        //三位为一组，百位十位个位都是通用的
        //Billion,Million,Thousand是按照位数来的
        
        if(!num) return small[0];
        string res;
        for(int i=1000000000,j=0;i>0;i/=1000,j++)
        {
            if(num>=i)
            {
                res+=get_part(num/i)+big[j]+' ';
                num%=i;
            }
            
        }
        while(res.back()==' ') res.pop_back();
        return res;
        
    }
    string get_part(int num)
    {
        string res;
        if(num>=100)
        {
            res += small[num/100]+" Hundred ";
            num %= 100;
        }
        if(!num) return res;
        if(num>=20)
        {
            res+=decade[num/10]+' ';
            num%=10;
        }
        if(!num) return res;
        res+=small[num]+' ';
        return res;
    }
};