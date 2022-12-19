大体思路就是使用动态规划数组保存N-x后，新N的输赢情况。
为了尽可能使Alice赢，我们要找出那个N=N-x后，p[N]为输的情况,如果P[N]为赢的话，则不要这个x，重新找个x。
若全部满足条件的x，N=N-x，P[N]都为输，那Alice无论怎么选都不可能赢，则将old N的p[N]置为输。

```
class Solution {
public:
    bool divisorGame(int N) {

    if(N==1) return false;
    if(N==2) return true;
    if(N==3) return false;
    bool p[N+1];
    
    memset(p,false,sizeof(p));
    p[1]=false;
    p[2]=true;
    p[3]=false;
    //记录N前面的每一个数字的情况
    for(int j=4;j<N+1;j++){
        int z=j;
        for(int i=j;i>=2;i--)
        {
            //如果i符合情况，则x=z/i
            if(z%i==0){
                z=z-z/i;
                //对转之后是bob选数，如果此时bob可以赢，则Alice不选这个x
                if(p[z]==true){
                    z=j; //重新选x
                }
                //如果这个时候选的数可以使Bob输，则Alice赢。
                else{
                    p[j]=true;
                    break;
            }
            }
        }
   
    }

    return p[N];
    }
};
```
