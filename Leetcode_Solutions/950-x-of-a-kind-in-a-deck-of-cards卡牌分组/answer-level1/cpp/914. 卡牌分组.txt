### 暴力法
先用Map对所有数字进行计数，再从2开始寻找可能分成的组数，若有返回true，若无返回false
### 时间/空间复杂度
时间复杂度:O（n2）
空间复杂度：O（n）
### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> M;//int,count
        for(int i=0;i<deck.size();++i){
            M[deck[i]]++;
        }
        bool res=false;
        for(int i=2;i<10000;++i){
            bool flag=true;
            for(auto j:M){
                if(j.second%i!=0){
                    flag=false;
                     break;
                }
            }
            if(flag==true){
                res=true;
                break;
            }
        }
        return res;
    }
};
```

### 最大公约数
由题意可知，如果最后能被成功分组，即所有组个数的最大公约数大于等于2，因此我们可以通过求得所有数的最大公约数，并判断是否大于2即可。
### 时间/空间复杂度
时间复杂度:O（n）
空间复杂度：O（n）
### 代码
 ```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> count(10000,0);
        for(auto i:deck) count[i]++;
        bool res=false;
        int g=-1;
        for(int i:count){
            if(g==-1) g=i;
            else g=gcd(i,g);
        }
        return g>=2;
    }
};
```