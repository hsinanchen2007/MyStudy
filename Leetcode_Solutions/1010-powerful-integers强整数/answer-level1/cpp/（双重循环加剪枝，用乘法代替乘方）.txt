### 解题思路
![Y1Q2~EP0BC(E\]5EG1B@N_DY.png](https://pic.leetcode-cn.com/6c72b6101cefe5333f4bd00b4ef089f8cd747e680bbc714c8683a2279658ca28-Y1Q2~EP0BC\(E%5D5EG1B@N_DY.png)

我的解法的基本思路还是对x和y的幂次进行双重循环，用一个set进行去重。在确定循环的边界的时候，对于内层循环，当两个次方的和大于bound后就跳出内层循环，对于外层循环，当一个x的幂次已经大于等于bound的时候，也不用在继续循环下去。

然而这个解法在当x=1或者y=1的时候受到了降维打击，当x或者y=1时，内层循环或者外层循环会进行bound次重复计算，在bound极大的情况下，会超出时间限制，因此在函数入口处进行判断，当x=1且y=1时，直接返回2，当x，y中某一个等于1时，为了便于处理剪枝，我们始终让x=1,y!=1,然后在内层循环执行完一次后，判断x是否为1,若为1,则后面的循环都是和第一次内层循环重复的操作，因此直接跳出。

在计算乘方的时候，我们注意到，如果每次循环都执行一次乘方操作的话，无疑有许多重复计算部分，因此我们将乘方操作用乘法代替，内层循环不断乘以y，外层循环不断乘以x，就能极大提高运行速度。

### 代码

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
       vector<int> ans;
        set<int> s;
        if(x==1 && y==1){
            if(2<=bound)
                ans.push_back(2);
            return ans;
        }

        // 始终令y!=1而x=1
        if(y==1){
            y=x;
            x=1;
        }
        int tmp_x = 1;
        
        for(int i=0; i<bound; i++){
            int tmp_y = 1;
            for(int j=0; j<bound; j++){
                int elem = tmp_x + tmp_y;
                if(elem <= bound){
                    s.insert(elem);
                    tmp_y*=y;       //计算y的乘方
                }
                else
                    break;
            }

            // 外层循环剪枝：当仅仅x的幂次就达到bound时，不需要继续计算下去
            //  当x==1时，也不需要再继续计算下去。
            if (pow(x, i)>=bound||x==1)
                break;
            tmp_x*=x;           //计算x的乘方
        }
        set<int>::iterator iter = s.begin();
        while(iter!=s.end()){
            ans.push_back(*iter);
            iter++;
        }
        return ans;
    }
};
```