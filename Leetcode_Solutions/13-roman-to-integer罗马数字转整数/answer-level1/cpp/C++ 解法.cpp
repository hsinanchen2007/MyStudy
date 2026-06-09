### 解题思路
此处撰写解题思路
其实解法挺暴力的hhh
因为出现9 4 这种情况就是由于I在V的左面，
那么从小到大遍历，对于遍历过去的位置取将其置为负值即可 后面再遇到前面的自然会减掉
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        int listnum []={1000,500,100,50,10,5,1};
        //string liststr[]={'M','D','C','L','X','V','I'};
        int len=s.length();
        //int sig;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='I'){
               num+=listnum[6];
               
           }else if(s[i]=='V'){
               listnum[6]=-listnum[6];
               num+=listnum[5];
           }else if(s[i]=='X'){
               if(listnum[6]>0)
                listnum[6]=-listnum[6];
                listnum[5]=-listnum[5];
                  num+=listnum[4];
           }
           else if(s[i]=='L'){
                listnum[4]=-listnum[4];
                  num+=listnum[3];
           }else if(s[i]=='C'){
               if(listnum[4]>0)
               listnum[4]=-listnum[4];
                listnum[3]=-listnum[3];
                  num+=listnum[2];
           }else if(s[i]=='D'){
                listnum[2]=-listnum[2];
                  num+=listnum[1];
           }else if(s[i]=='M'){
               if(listnum[2]>0)
                listnum[2]=-listnum[2];
                listnum[1]=-listnum[1];
                  num+=listnum[0];
           }

           
        }
        return num;
    }
};
```