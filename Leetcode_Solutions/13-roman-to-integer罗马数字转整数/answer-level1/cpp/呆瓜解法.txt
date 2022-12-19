很呆瓜的解法...


执行结果：通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了83.67%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了94.70%的用户

class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int bit1000 = 0;
        int bit900 = 0;
        int bit500 =0;
        int bit400 = 0;
        int bit100 = 0;
        int bit90 = 0;
        int bit50 = 0;
        int bit40 = 0;
        int bit10 = 0;
        int bit9 = 0;
        int bit5 = 0;
        int bit4 = 0;
        int bit1 = 0;
        
        while(i<s.length())
        {
            if(s[i]=='M') 
            {
                bit1000+=1;
                i++;
            }
            else if(s[i]=='C'&&s[i+1]=='M')
            {
                bit900+=1;
                i=i+2;
            }
            else if(s[i]=='D')
            {
                bit500+=1;
                i++;
            }
            else if(s[i]=='C'&&s[i+1]=='D')
            {
                bit400+=1;
                i=i+2;
            }
            else if(s[i]=='C'&&s[i+1]!='D'&s[i+1]!='M')
            {
                bit100++;
                i++;
            }
            else if(s[i]=='X'&&s[i+1]=='C')
            {
                bit90++;
                i+=2;
            }
            else if(s[i]=='L')
            {
                bit50++;
                i++;
            }
            else if(s[i]=='X'&&s[i+1]=='L')
            {
                bit40++;
                i+=2;
            }
            else if(s[i]=='X'&&s[i+1]!='L'&&s[i+1]!='C')
            {
                bit10++;
                i++;
            }
            else if(s[i]=='I'&&s[i+1]=='X')
            {
                bit9++;
                i=i+2;
            }
            else if(s[i]=='V')
            {
                bit5++;
                i++;
            }
            else if(s[i]=='I'&&s[i+1]=='V')
            {
                bit4++;
                i=i+2;
            }
            else if(s[i]=='I'&&s[i+1]!='V'&&s[i+1]!='X')
            {
                bit1++;
                i++;
            }
            
        }
        return bit1000*1000+bit900*900+bit500*500+bit400*400+bit100*100+bit90*90+bit50*50+bit40*40+
            bit10*10+bit9*9+bit5*5+bit4*4+bit1*1;
    }
};