class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1)
        return s;

        vector<string> vec(numRows,"");//存储每一行字符串
        int d1=numRows*2-2;
        int d2=numRows-1;
        for(int i=0;i<s.size();i++)
        {
            if(i%d1<=numRows-1)//直线中
            {
                vec[i%d1]+=s.substr(i,1);

            }else{//斜线中

                vec[vec.size()-i%d2-1]+=s.substr(i,1);//从倒数第二个开始

            }
        }

        string result="";

        for(int i=0;i<vec.size();i++)
        {
            result+=vec[i];
        }

        return result;
        

    }
};