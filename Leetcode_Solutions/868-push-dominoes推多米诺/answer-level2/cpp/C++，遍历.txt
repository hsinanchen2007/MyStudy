## 考虑LL，RR，RL三种情况，遍历一遍完事，个人觉得自己写的还是比较好理解的
```
class Solution {
public:
    //需要单独考虑LL,RR,LR这三种情况，记录上一个字符的位置，以及字符，并且记录.的个数，这样方便之后的写代码
    string pushDominoes(string s) {
        int n=s.length();
        int cnt=0,idx=0;//cnt表示的是有多少个.字符
        char ch='.';
        for(int i=0;i<n;i++){
            if(s[i]=='L'&&ch!='R'){
                for(int j=idx;j<i;j++){
                    s[j]='L';
                }
            }else if(s[i]=='L'&&ch=='R'){
                for(int j=0;j<cnt/2;j++){
                    s[idx+j+1]='R';
                    s[i-1-j]='L';
                }
            }else if(s[i]=='R'&&ch=='R'){
                for(int j=idx;j<i;j++){
                    s[j]='R';
                }
            }
            if(s[i]!='.'){
                idx=i;
                ch=s[i];
                cnt=0;
            }else{
                cnt++;//表示.的数量增加了。。。
            }
        }
        if(ch=='R'){//处理最后一个字符，就是如果最后一个字符是R的话需要单独考虑，如果是L或者.是不需要考虑的
            for(int i=0;i<cnt;i++){
                s[n-i-1]='R';
            }
        }
        return s;
    }
};
```