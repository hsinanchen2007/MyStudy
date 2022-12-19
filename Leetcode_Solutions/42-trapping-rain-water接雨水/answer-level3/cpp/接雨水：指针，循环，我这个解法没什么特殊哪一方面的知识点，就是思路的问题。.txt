### 解题思路
![image.png](https://pic.leetcode-cn.com/89c127a208cb4a09ff14267aae9f9643ed06e44fcb323299d31449803524e32c-image.png)
从图中可以看到，首先选取数组开头为maxheightpos，i向后遍历时,height[i]<height[maxheightpos]说明我们这个地方可以储水(这里是可以储水，但是真正想要储水必须要找到某一个位置i,得到height[i]>=height[maxheightpos])，将它加入temp中，i继续遍历，当height[i]>=height[maxheightpos]时，此时说明储水成立，将它加入到num中，maxheightpos=i,然后继续向后找符合的情况。遍历完时，可能存在下面图的情况，此时就需要反着再来一遍。。

应该是官方解答二，考虑最后状态，从最高的柱子往两边看呈递减，那么我只要分别从左右两端往中间遍历，让数列呈这样的状态就行（eg.从左开始，height[i]>height[i-1]时，把height[i]补齐，并且加上差值）

作者：gy915-UeEN4SGwuv
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/98-by-gy915-ueen4sgwuv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
![9EAAB826976FF45D83FCC28B445B4F7C.jpg](https://pic.leetcode-cn.com/01e34cb3ca394b07feb7e6beb23627bf7a9f043613ac50f3519aeb863c932557-9EAAB826976FF45D83FCC28B445B4F7C.jpg)

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int num=0,maxheightpos=0,temp=0;  //temp为当前储水的量
        for(int i=1;i<height.size();i++){
            if(height[i]>=height[maxheightpos]){
                maxheightpos=i;
                num+=temp;
                temp=0;
                continue;
            }
            temp+=height[maxheightpos]-height[i];
        }
        temp=0;
        int size=maxheightpos;          //下一个循环到maxheightpos停止
        maxheightpos=height.size()-1;    //重新来过，此时maxheightpos=height.size()-1;
        for(int i=height.size()-1;i>=size;i--){
            if(height[i]>=height[maxheightpos]){
                maxheightpos=i;
                num+=temp;
                temp=0;
                continue;
            }
            temp+=height[maxheightpos]-height[i];
        }
        return num;
    }
};
```