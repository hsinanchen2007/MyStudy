class Solution {
public:
    bool isdigit(char c){
        return c-'0'<=9 && c-'0'>=0;
    }
  
    int myAtoi(string str) {
       // cout<<INT_MIN;
        // -2147483648  2147483647
        //cout<<INT_MAX;
        int n=str.size(),i=0;
        while(str[i]==' '){i++;}
        
        int flag=1;
        if(!isdigit(str[i])&& str[i]!='-'&& str[i]!='+') return 0;
        if(str[i]=='-') {flag=false;i++;}
        if (str[i]=='+' && flag==1) i++;
        
        int sum=0;
        for(;i<n;i++){
            if(isdigit(str[i])){
                // int v=str[i]-'0';
                // 
                if(sum<INT_MAX/10||(sum==INT_MAX/10&& (str[i]-'0')<=7))
                    sum=sum*10+(str[i]-'0');// 这里必须上括号
                else return flag==true?INT_MAX:INT_MIN;
            }
            else break;
        }
       
       
        return flag==true?sum:-sum;
          

    }
};