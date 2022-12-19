### 解题思路
主要思路是区分左右两侧不同的操作，分开来处理，处理思路完全一致

### 代码

```cpp
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        //每次倒水调用update一次修改height数组;
        for(int i=0;i<V;i++){
            update(heights,K);
        }
        //返回最终数组
        return heights;
    }
    void update(vector<int>& heights,int pos){
        //按照规则来更新heights，首先初始化两个index用来记录左右倒水的位置，每次只能是选择左或者右或者当前位置
        int indexL=-1;
        int indexR=-1;
        //min值记录往单侧递减的最小水滴高度
        int min=heights[pos];
        for(int i=pos-1;i>=0;i--){
            //如果还有更小的则继续更新这个更小位置为index
            if(heights[i]<min){
                min=heights[i];
                indexL=i;
            }else if(heights[i]==min){//这里遇到相等条件时只需要继续往后遍历即可，因为可能还有更适合的index
                continue;
            }else{//好，一旦发现不是单调递减了，循环退出
                break;
            }
        }
        min=heights[pos];
        for(int i=pos+1;i<heights.size();i++){
            if(heights[i]<min){
                min=heights[i];
                indexR=i;
            }else if(heights[i]==min){
                continue;
            }else{
                break;
            }
        }
        //简单的根据三种情况去修改height
        if(indexL!=-1) {
            heights[indexL]++;
        }else if(indexR!=-1) {
            heights[indexR]++;
        }else{
            heights[pos]++;
        }
    }
};
```