### 解题思路
求出数组最大的间距并记录下其下标。与首尾的的特殊情况[0...i]和[...i...0]相对比，求出距离最大值。

### 代码

```cpp
class Solution {
    //求出数组最大的间距并记录下其下标。与首尾的的特殊情况[0...i]和[...i...0]相对比，求出距离最大值。
public:
    int maxDistToClosest(vector<int>& seats) {
        int low,high,dis,first,temp;
        low=0;
        high=0;
        dis=0;
        temp=0;
        vector<int>all(2,0);
        for(int i =0;i<seats.size();i++){
            if(seats[i]==1){
                //记录下第一个为1的点
                if(temp==0){
                    first=i;
                    temp++;
                }

                //求出一般情况下的距离最大值
                low=high;
                high=i;
                if(dis<high-low){
                    dis=high-low;
                    all[1]=high;
                    all[0]=low;
                }                
            }
        }

        //与首尾的的特殊情况比较
        if(first-0>=seats.size()-1-high){
            if((dis/2)<=first){
                dis=first;
            }
            else{
                dis=dis/2;
            }
            
        }
        else{
            if((dis/2)<=seats.size()-high-1){
                dis=seats.size()-high-1;
            }
            else{
                dis=dis/2;
            }

        }
        


        return  dis;
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/d0801e0fcca7e2ba5176cb41a0a7396f2710941786a6bc7d19c42d713c31df44-image.png)
