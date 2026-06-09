思路：把每一个数都对应相乘，然后将得出的结果全部相加保存起来  最后得出结果


class Solution {
public:
    string multiply(string num1, string num2) {//按位相乘后相加
        string res;int ret=0;if(num1=="0"||num2=="0")//当有一个数为0时，直接输出0
            return "0";
        for(int i=num1.size()-1;i>=0;--i)//对每一个数都进行相乘
        {
            string temp;int k=num1.size()-1-i;
           while(k--)
                temp+='0';//与十位、百位相乘 则多加0即可          
            for(int j=num2.size()-1;j>=0;--j)
            {
                int ans1=num1[i]-'0';
               int ans2=num2[j]-'0';
               ret+=ans1*ans2;
                temp+=ret%10+'0';
                ret/=10;
            }
            if(ret)temp+=ret+'0';ret/=10;
            reverse(temp.begin(),temp.end());//结果取反  没什么好说的
            res=add(res,temp);//将每一步得出的结果都相加保存起来
        }
        return res;
    }
    string add(string num1,string num2)//处理相加
    {
        string res;int ret=0; int i=num1.size()-1,j=num2.size()-1;
        while(i>=0||j>=0||ret!=0)
        {
            if(i>=0)ret+=num1[i--]-'0';
            if(j>=0)ret+=num2[j--]-'0';
            res+=ret%10+'0';
            ret/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};