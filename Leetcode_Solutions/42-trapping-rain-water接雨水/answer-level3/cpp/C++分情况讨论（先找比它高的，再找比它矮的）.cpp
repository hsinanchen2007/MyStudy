### 解题思路
执行用时击败68.64%，感觉效率还可以。
思路：
1、从每个柱子出发，从左往右找到第一个比他高（或相等）的柱子，在减去中间的柱子高度，加入结果；
2、如果1找不到，就从这个柱子出发找它右边最接近它高度（但比它矮）的柱子，减去中间的柱子高度，加入结果；
3、进入下一次循环时，把位置置为找到的那个柱子，如果每找到则位置+1；
4、循环结束返回结果。
注意点：
1、所有情况下，遇到0都必须跳过；
2、必须先找高的，再找矮的。

改进思路：
使用单调栈来做（要求栈内元素单调递减），遇到比栈顶大的元素就弹栈（弹栈的时候计算中间有多少水），这样代码会更加简介，但本质思路是一样的，具体代码我有收藏（即题解中sweet姐写的）。
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        //1、从每个柱子出发，从左往右找到第一个比他高（或相等）的柱子，在减去中间的柱子高度、
        //2、如果1找不到，就从这个柱子出发找它右边最接近它高度的柱子，减去中间的柱子高度
        int re=0;
        for(int i=0; i<height.size(); i++){
            if (height[i]==0) continue;
            bool flag_h=false;//是否找到高的
            bool flag_l=false;//是否找到矮的
            int j,k;
            if (height[i]>0){
                //先找比他高的
                j=i+1;
                for (; j<height.size(); j++){
                    if (height[j]>=height[i]){
                        flag_h=true;
                        break;
                    }
                }
                if (flag_h){//找到了比它高的
                    int temp=0;
                    for(int kk=i+1; kk<j; kk++){
                        temp+=height[kk];
                    }
                    re+=height[i]*(j-i-1)-temp;
                }
                else {//没找到比它高的，那就找离它距离最近的矮的
                    j=i+1;
                    int low=height[i];
                    k=i;
                    for (; j<height.size(); j++){
                        if (height[j]==0) continue;
                        if (height[j]<height[i]){
                            flag_l=true;
                            if (abs(height[j]-height[i]) < low){
                                low=abs(height[j]-height[i]);
                                k=j;
                            }
                        }
                    }
                    if (flag_l){
                        int temp=0;
                        for(int ii=i+1; ii<k; ii++){
                            temp+=height[ii];
                        }
                        re+=height[k]*(k-i-1)-temp;
                    }
                    else{
                        //高的也没有，低的也没有，往下一步
                        continue;
                    }
                }

            }
            if (flag_h) i=j-1;
            else if (flag_l) i=k-1;
            else continue;
        }
        return re;
        
    }
};
```