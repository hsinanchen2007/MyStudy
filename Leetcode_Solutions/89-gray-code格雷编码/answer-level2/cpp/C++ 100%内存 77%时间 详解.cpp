
一阶： 0->1
二阶： 我们先前已经有了1阶的信息，能不能利用上呢
观察示例： 0->1->3->2,即00->01->11->10
可以发现 二进制表示下，二阶的前两位可以直接在一阶结果前面加一个0，而后两位则是将首位的0改成1，再逆序访问一阶结果
首位添0不改变原值，添1则加上2*(N-1)即可
即二阶：0->1->1+2*(2-1)->0+2*(2-1)
推导： N阶的前2*(N-1) 位与N-1阶完全相同，后2*(N-1)位则为逆序访问N-1阶加上2*(N-1)
代码如下


```
class Solution {
public:
vector<int> res;
    vector<int> grayCode(int n) {
        res.push_back(0);
        if(n==0) return res;
        int mark=1, tmp=1;
        while(mark<=n){
            for(int i=res.size()-1; i>-1; i--){
                res.push_back(res[i]+tmp);
            }
            mark++;
            tmp *= 2;
        }
        return res;
    }
};
```

