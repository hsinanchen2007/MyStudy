每一步的意义都很清楚
```
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
         long n=numerator;                   //防止负数转换为正值时越界
         long m=denominator;                 //同上
        if(n<0 && m>0||n>0 && m<0)           //判断结果正负值，负值时添加负号
            ans.push_back('-');
        n=abs(n);                            //取绝对值方便后续操作
        m=abs(m);                            //同上
        long z=n/m;                          //记录商，定义为long同样为防止越界 
        n%=m;                                //更新被除数n
        ans+=to_string(z);                   //将整数加入结果字符串
        if(n!=0)                             //根据第一次的结果判断是否需要添加小数点
        {
           ans.push_back('.');
            n*=10;                           //添加小数点后n扩大10位
        }
            
        int local=ans.size();                //记录当前结果所在位
        map<int,int> num_local;              //记录当前结果以及出现的位数
        while(n!=0)
        {
            map<int,int>:: iterator it=num_local.find(n);  //首先查找n是否出现过
            if(it==num_local.end())                        
            {
                num_local.insert(make_pair(n,local));      //未查到即将当前的键值对（n，local）加入map中
            }
            else
            {
                ans.insert(it->second,1,'(');              //当n在map中存在时，说明开始循环，故在第一次出现位置添加左括号
                ans.push_back(')');                        //一旦开始循环，既可以结束运算，并添加有括号
                break;                                     //跳出循环
            }
            if(n<m)             
            {
                ans.push_back('0');                        //n小于m时，需要向后移位
                n*=10;                                     //位到下一位后n扩大10倍
                local++;                                   //更新新一次结果所在位
            }
            else
            {
                ans.push_back(n/m+'0');                    //当n>m时，直接在ans中添加当前位的运算结果
                n%=m;                                      //更新除数
                n*=10;                                     //移位到下一位后n扩大10倍
                local++;                                   //更新新一次结果所在位
            }
        }
        return ans;
    }
};
```
