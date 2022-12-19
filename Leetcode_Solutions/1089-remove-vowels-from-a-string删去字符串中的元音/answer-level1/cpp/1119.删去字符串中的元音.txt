### 解题思路
本来没想过要写，题解，这是小白第一次做题。
但看到内存消耗击败了百分之百的用户……就想着提交一下题解。
思路是新建一个string，然后一一对比传入的string把不是元音的位赋值到新的string，
做完对比后再用'\0'填充剩下的位置。

### 代码

```cpp
class Solution {
public:
    string removeVowels(string S) {
        string temp=S;
        int a=S.length();
        cerr<<"a ="<<a<<endl;
        int i= 0,k=0;
        for(; i< a; i++)
        {
            if((S[i]=='a')||(S[i]=='e')||(S[i]=='i')||(S[i]=='o')||(S[i]=='u'))
            {

            }
            else
            {
                temp[k]=S[i];
                k++;
            }
            //cerr<<"k="<<k<<"\t\n";
        }
        //cerr<<"k= "<<k<<endl;
        
        while(k<a)
        {
            temp[k]='\0';
            k++;
        }
        /*
        for(int i=0;;i++)
        {

        }
        */
        cout<<temp;
        return temp;
    }
};
```