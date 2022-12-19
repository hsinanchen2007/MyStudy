这个题的难点在于两个方面：
1. 连乘的处理。
2. 前导零的处理。
# 连乘的处理
在数学公式中，连乘的开始符是一个加减符号，结束符是另一个加减符号。因此，我们每次都要保存好前面的结果，程序中为`pre`。`pre`的作用就是保存上一次还没结束的连乘运算，比如2\*3\*5，当计算完2\*3之后，会将结果6保存在pre中，如果再遇到`乘5`运算，再将`pre`乘上5就ok。如果完整的运算是1+2\*3\*5+6，那么`pre`从`1+`开始保存，直到`+6`结束。
# 前导零的处理
处理比较简单粗暴，就是直接判断开始的第一个字符是否为0。如果为0，则后面不可以再加字符，否则可以继续加字符。
# 完整程序
```
#define ll long long
class Solution {
public:
    vector<string> ans;
    char op[3]={'+','-','*'};
    void alloc_op(ll result, ll target, ll pre, string path,string num,int pos){
        int n_len=num.length();
        if(pos==n_len){
            if((result+pre)==target) ans.push_back(path);
            return ; 
        }
        for(int i=0;i<3;++i){
            string tmp=path+op[i];
            int tmp_r=result;
            int tmp_p=pre;
            int tmp_n=0;
            for(int j=0;pos+j<n_len;++j){
                tmp+=num.at(pos+j);
                tmp_n=tmp_n*10+(num.at(pos+j)-'0');
                if(i<=1){
                    tmp_r=result+pre;
                    if(i==0)tmp_p=tmp_n;
                    else tmp_p=-tmp_n;
                }else tmp_p=pre*tmp_n;
                alloc_op(tmp_r,target,tmp_p,tmp,num,pos+j+1);
                if(num.at(pos)=='0') break;
            }
        }
    }
    vector<string> addOperators(string num, ll target) {
        ll result=0;
        ll pre=0;
        string path="";
        for(int i=0;i<num.length();++i){
            pre=pre*10+(num.at(i)-'0');
            path+=num.at(i);
            alloc_op(result,target,pre,path,num,i+1);
            if(num.at(0)=='0') break;
        }
        return ans;
    }
};
```