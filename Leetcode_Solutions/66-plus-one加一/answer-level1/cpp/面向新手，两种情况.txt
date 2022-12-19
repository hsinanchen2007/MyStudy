

![image.png](https://pic.leetcode-cn.com/e60f5a39758a1c520a293df62e92dffde72eb693466a235157ad182824051af8-image.png)

````Code spanclass Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> vec;
        vec.assign(digits.begin(),digits.end());
        vector<int>::iterator iter;
        int n=0;
        for(int j=0;j<digits.size();j++)
        {
            if(digits[j]==9) n++;                    
        }
        if(n==digits.size())//如果每位都是9，需进位
        {
            digits.clear();
            digits.resize(n+1);
            digits.assign(n+1,0);
            digits[0]=1;
            return digits;
        }
        else//如果不是每位都是9，不进位
        {
        int i=digits.size()-1;
        F(vec,digits,i);
        //cout<<i;
        return digits;
        }
    }



void F(vector<int> &vec,vector<int> &digits,int i) //双vector，新vector长度动，digits长度不动      
    {
        vector<int>::iterator iter;
        if(vec.back()==9)
        {
            iter = vec.end()-1;//用iterator获取vector最后一个元素应该用vec.end()-1，而不是vec.end()
            *iter = 0;
            digits[i]=*iter;
            i--;
            vec.pop_back();
            F(vec,digits,i);//有条件递归
        }
        else
        {
            iter = vec.end()-1;
            *iter+=1;
            digits[i]=*iter;
            //cout<<*iter;
            i--;
            vec.pop_back();
        }
    }    
};````