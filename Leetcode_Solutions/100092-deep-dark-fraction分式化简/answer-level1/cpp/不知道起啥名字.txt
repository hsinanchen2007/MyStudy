### 解题思路
首先将计算连分数过程抽象为不断计算ax+1/(n/m)的过程。以an-1为起点，递推地执行该过程。最后使用辗转相除法进行化简。

### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> result;
        int n,m;//n为分子，m为分母
        int oldN,oldM;
        //首先以an-1为起点,初始化[n,m]
        n = cont.at(cont.size()-1);
        m = 1;

        //接下来循环处理an-2到a0
        for(int i= cont.size()-2;i >= 0;i--){
            oldN = n;
            oldM = m;
            n = cont.at(i) * oldN + oldM;
            m = oldN; 
        }


        //下面进行分式化简
        int a,b,c,d=1;
        a = n, b = m;
        while(a!=0){
            c = a/b;
            d = a - (b*c);
            if(d == 0)
                break;
            a = b;
            b = d;
        }
        if(a==0){
            result.push_back(0);
            result.push_back(1);
        }
        else{
            n = n/b;
            m = m/b;
            result.push_back(n);
            result.push_back(m);
        }
        return result;
    }
};
```