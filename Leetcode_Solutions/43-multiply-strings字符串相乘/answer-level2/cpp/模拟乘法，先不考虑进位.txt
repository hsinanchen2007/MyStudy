class Solution {
public:
    string multiply(string num1, string num2) {
       if(num1[0]=='0'||num2[0]=='0')
           return "0";
        int n1=num1.length();
        int n2=num2.length();
        int res[221]={0};
        int i,j,k;
        for(i=n1-1;i>=0;i--)//所有位数计算，先不管进位
        {
            for(j=n2-1;j>=0;j--)
            {
             res[n1+n2-i-j-2]+=(num1[i]-'0')*(num2[j]-'0');   
            }
        }
        for(i=0;i<221;i++) //处理进位
        {
          if(res[i]>=10)
          {
              res[i+1]+=res[i]/10;
              res[i]=res[i]%10;
          }    
        }
        for(i=220;i>=0;i--)//找到不为0的位置
        {
            if(res[i]!=0)
            {k=i;break;}
        }
        string s="";
        for(i=k;i>=0;i--)//倒叙合并为字符串
            s+=char(res[i]+'0');
        return s;
    }
};