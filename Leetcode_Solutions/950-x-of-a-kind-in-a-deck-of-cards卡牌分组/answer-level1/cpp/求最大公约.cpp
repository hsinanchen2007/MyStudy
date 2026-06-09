发现自己写的很麻烦，哈哈哈。。。
但是关键就是求最大公约数啦~

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int num=1;
        for(int i=1;i<deck.size();i++){
            if(deck[i]==deck[i-1]){
                num++;
            }
            else break;
        }

        int a=num;
        int b=num;
        num=1;
        int flag=0;
        for(int i=b+1;i<deck.size();i++){
            flag=1;
            if(deck[i]==deck[i-1]) num++;
            else{
                a = gcd(a,num);
                num=1;
            }
        }
        if(flag) a=gcd(a,num);
        

        if(deck.size()%a!=0 || a<2) return false;
        for(int i=a;i<deck.size()-1;i+=a){
            if(deck[i+a-1]==deck[i]);
            else return false;
        }
        return true;
    }


    int gcd(int i, int j){
        if(j==0) return i;
        else return gcd(j,i%j);
    }
};
```