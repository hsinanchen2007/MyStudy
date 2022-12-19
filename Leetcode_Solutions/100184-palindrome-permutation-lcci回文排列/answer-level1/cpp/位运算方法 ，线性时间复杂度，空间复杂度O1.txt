### 解题思路
位运算，记录已经有的字符串，如果没有记录的话记录，num+1，如果有记录的话，去掉记录，num-1。最后如果是回文串，num<=1(=1是奇数，=0是偶数)
时间复查度On 空间复杂度O1
### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int num=0;
        unsigned int p1=0;
        unsigned int p2=0;
        unsigned int p3=0;
        unsigned int p4=0;
        //128个字符，1个int是4*8=32，所以需要4个int来表示
        for(int i=0;i<s.size();++i)
        {
            unsigned int * p;
            int t=s[i];
            cout<<t<<endl;
            if(t<32) {
                p=&p1;}
            else if(t<64){ 
                p=&p2;
                t-=32;
            }
            else if(t<96) {
                p=&p3;
                t-=64;
            }
            else {
                p=&p4;
                t-=96;
            }
            int n=pow(2,t);
            if(((*p)|n)>(*p))
            {
                ++num;
                *p=(*p)|n;
                //cout<<" not has "<<s[i];
            }else
            {
                --num;
                //已经有了要去掉   1  1  1  0  1
                //                  0  0  1  0  0
                *p=(*p)-n;
                //cout<<*p<<" "<<n<<" "<<*p|n<<endl;
                //cout<<" has "<<s[i];
            }
            cout<<endl;

        }
        if(num<=1) return true;
        else return false;
    }
};
```