![QQ截图20200303125242.png](https://pic.leetcode-cn.com/8ce1cfee846d237f7753beaee31155a3a74ce5da705f315602cd0572a39bdea1-QQ%E6%88%AA%E5%9B%BE20200303125242.png)

### 解题思路
在cpp中vector的运行效率实在太低了
刚开始用了$n^3$的方法直接枚举爆算，按理说应该卡着过，结果严重超时
所以还是用了一种比较麻烦的方法，就是根据斜率排序，再数斜率相同的直线数目
这样子时间复杂度其实差不远，是$n^2\log_2n$

### 代码

```cpp
class Solution {
    const double MIN=1e-5;//这是避免double精度问题，用来进行比较的常数
    int n;
    vector<int> Ans;//这就是存储答案的vector
    double slope[310][310];//存储斜率的二维表
    
    double abs(double x){//手写的绝对值函数
        return (x>0)?x:-x;
    }

    double Calc(vector<int> a,vector<int> b){//计算两个点直线的斜率
        double dx=a[0]-b[0];
        double dy=a[1]-b[1];

        if(abs(dx)<MIN)
        return -37;//这里的-37是我随便取的特殊值，用来处理斜率无穷大的情况

        return dy/dx;
    }

public:
    vector<int> bestLine(vector<vector<int>>& points) {
        n=points.size();
        memset(slope,-1,sizeof(slope));

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            slope[i][j]=Calc(points[i],points[j]);//先预处理每两个点的斜率
        }

        int ans=0;
        for(int i=0;i<n;i++){
            sort(&slope[i][i+1],&slope[i][n]);//对于每个点points[i]，都进行排序，便于查找斜率相同的点
            slope[i][n]=-31.4;//这里的-31.4也只是个特殊值

            int len=2;
            for(int j=i+2;j<=n;j++)
            if(abs(slope[i][j]-slope[i][j-1])<MIN)
            len++;
            else{
                if(len>ans){
                    ans=len;
                    for(int k=i+1;k<n;k++){//由于排序打乱了原有的顺序，所以需要这样扫一遍找到对应斜率的点
                        double sp=Calc(points[i],points[k]);
                        if(abs(sp-slope[i][j-1])<MIN){
                            Ans.clear();
                            Ans.push_back(i);
                            Ans.push_back(k);
                            break;
                        }
                    }
                }
                len=2;
            }
        }

        return Ans;
    }
};
```