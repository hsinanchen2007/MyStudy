### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b){
                if(b==0) return a;
                else return gcd(b,a%b);
            }
    int sum[10010];
    bool hasGroupsSizeX(vector<int>& deck) {
       
       
        for(auto i : deck) sum[i]++; //数据规模较小，直接作为数组下标；
        int t=0, flag = 0, a, b;
        for(auto i : sum){
            if(!i) continue;
            //cout<<i<<" ";
            if(flag == 0){    //第一个不为0的sum值
                a = i;
                flag++;
            }
            else if(flag == 1){
                b = i;       //第二个不为0的sum值
                t = gcd(a, b); //有两个数才可以用gcd；
                flag++;
            }
            else{
                t = gcd(i,t);
            }


        }
       // puts("");
       if(deck.size() == 1) return false;
       return (t == 0 || t >= 2?true:false); //t==0 表示deck只有一种数；

    }
};
```