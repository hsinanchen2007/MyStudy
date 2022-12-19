```
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2){
            return n;
        }
        int ans=0;
        ///double 64位精度不够，long double 128位
        long double *v=(long double*)malloc(sizeof(long double)*n),one=1;
        for(int i=0;i<n;i++){//以点i为端点
            int tp=1,tq=0,lv=0;
            ///不必考虑小于i的点，过小于i的点的全部直线，结果已更新
            for(int j=i+1;j<n;j++){
                int x = points[i][0]-points[j][0],y = points[i][1]-points[j][1];///得到矢量（x，y）
                if(x==0&&y==0){///重合点，直接计数
                    tp++;///点j和i重合，计数+1
                    continue;
                }
                if(x==0){///横纵坐标为0处理
                    y=1;
                }
                else if(y==0){
                    x=1;
                }
                v[lv++]=one*y/x;///push_back一个（i，j）为端点的斜率，不用在意除数为0（结果为正无穷大inf）
            }
            
            ///统计斜率个数时，可使用map或者unordered_map一类的容器，毕竟平衡二叉树或者hash的查询效率很高
            sort(v,v+lv);///斜率排序 O(nlgn)
            if(lv){///求同一斜率的最多个数
                int ts=1;
                for(int i=1;i<lv;i++){
                    if(v[i]==v[i-1]){
                        ts++;
                    }
                    else{
                        tq=max(tq,ts);
                        ts=1;
                    }
                }
                tq=max(tq,ts);
            }
            ans=max(ans,tp+tq);///更新结果
        }
        return ans;
    }
};
```
![图片1.png](https://pic.leetcode-cn.com/dfe54636106b6b07f85a2ba8ffe4f98fae69b33eed42c83bc14a24513a0a55b8-%E5%9B%BE%E7%89%871.png)
///
上面的代码求斜率时，直接用y/x是不够妥当的...浮点数运算存在精度误差。
单纯为了追求时间复杂度才用的。
gcd肯定没错
将斜率矢量(x,y)----gcd--->(gx,gy)即化成最简分数。然后套map，hash计数
经自己测试：
(gcd或者直接除)+(map或者unordered_map) 运行时间24ms
gcd+手动hash+排序计数 运行时间12ms
直接除+排序计数 运行时间8ms
///
可以看出，map或者hash容器果然还是不如排序sort高效。即便是hash容器，在数据量小的时候仍然比不上sort
