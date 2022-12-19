        class Solution {
        public:
            bool isNumber(string s) {
                if(s.size()==0)
                    return false;

                if(s.size()==1){
                    if(s[0]>='0'&&s[0]<='9')
                        return true;
                    else
                        return false;
                }

                //去前导和后导空格
                int l=0,r=s.size()-1;
                while(s[l]==' ')
                    l++;
                while(s[r]==' ')
                    r--;
                s=s.substr(l,r-l+1);
                // e的个数 和 其他字符的个数
                int num=0,num1=0,num2=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]=='E'||s[i]=='e'){
                        num++;
                    }
                    else if(s[i]>='0'&&s[i]<='9'){
                        num1++;
                    }
                    else if(s[i]=='-'||s[i]=='+')
                        ;
                    else if(s[i]=='.')
                        num2++;
                    else
                        return false;
                }
                if(num>1||num2>1) //e的个数和小数点的个数必须 <=1
                    return false;
                int sum=1; //至少有一个数字
                sum+=num;  //如果存在e ，那么至少要有两个数字
                if(num1<sum)
                    return false;
                //正负号的位置
                for(int i=1;i<s.size();i++){ //正负号只准许出现在首位或者e的后一位
                    if(s[i]=='-'||s[i]=='+'){
                        if(s[i-1]!='e'&&s[i-1]!='E')
                            return false;
                    }
                }
                //e的位置
                for(int i=0;i<s.size();i++){
                    if(s[i]=='e'||s[i]=='E'){
                        if(i==0||i==s.size()-1)  //e不能出现在头和尾
                            return false;
                        else if(i==1&&(s[0]=='-'||s[0]=='+'||s[0]=='.'))   
                            return false;
                        else if(i==s.size()-2&&(s[i+1]=='-'||s[i+1]=='+'||s[i+1]=='.'))
                            return false;
                    }
                }
                // 小数点的位置
                int g=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]=='.'){
                        if(g==1)  //小数点不能出现在e的后面
                            return false;
                        if(i==0||i==s.size()-1){
                            if(i==0){
                                if(s[i+1]<'0'||s[i+1]>'9')
                                    return false;
                            }
                            else{
                                if(s[i-1]<'0'||s[i-1]>'9')
                                    return false;
                            }
                        }
                    }
                    if(s[i]=='E'||s[i]=='e')
                        g=1;
                }
                return true;
            }
        };