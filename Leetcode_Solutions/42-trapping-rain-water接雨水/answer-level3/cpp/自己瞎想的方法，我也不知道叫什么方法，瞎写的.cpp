### 解题思路
首先进行模型抽象，将输入的vector看成曲线，曲线存在若干极大值，在两个相邻极大值间存在着空间可以容纳雨水。
当确定一个标杆向后搜索时，只需要搜索高度大于等于当前标杆的下一标杆即可，由于木桶原理，两个标杆间能够容纳的雨水其实取决于
两个标杆中较小的那个高度。如果在向后搜索的过程中找不到高度大于等于当前标杆的下一标杆也无所谓，只要找到当前标杆后最高且离当前
标杆尽可能远的下一标杆即可。计算容积后设下一标杆为当前标杆继续向后搜索即可。

### 代码

```cpp
class Solution {
public:
    // 函数用于计算两个索引值间的容积 
    int getVolume(int i , int j , vector<int>& height){
        int waterline = min(height[i],height[j]);
        int acc = 0 ;
        for ( int c = i ; c < j ; ++c ) acc+=(waterline>height[c])?waterline-height[c]:0; // 只累加低于水平线的高度
        return acc ;
    }
    // 计算能接多少雨水的函数
    int trap(vector<int>& height) {
        int sz = height.size();
        int total_volume = 0 ,i=0;
        
        while(i<sz-1){
            //cout<< i<<" ";
            int max_height =-1 ; 
            int max_index  =i+1 ;
            for (int j = i + 1 ; j < sz ; ++j ){
                //寻找下一个更高高度标杆,由于木桶效应，容纳雨水取决与两标杆间高度最低的那个，
                // 因此后一个标杆高度只要大于等于前一个标杆即可    
                if ( height[j] >= height[i] ){
                    max_height = height[j];
                    max_index  = j ;
                    break ;
                }
                // 若没找到大于等于前置标杆长度的标杆，直接寻找距离前置标杆最远且高度尽可能高的
                // 标杆
                if( height[j] >= max_height ){
                    max_height = height[j]  ;
                    max_index  = j          ;
                }
            }
            total_volume+=getVolume(i,max_index,height);
            //cout<<total_volume<<endl;
            i=max_index;
        }
        
        return total_volume;
    }
};
```