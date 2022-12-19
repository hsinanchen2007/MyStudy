### 解题思路
在双指针法基础上的小小改进。
双指针法：首尾各有一个指针start,end;H[start],H[end]两个代表首尾初的高度，每次取最短的那个做为矩形的纵向长度，H[start]、H[end]谁小，谁的指针往中间挪动，直到首尾重叠，那么此处可以有所改进，如果H[start]小，并且H[start]<H[start-1],那么计算出来的矩阵面积肯定会比保存的最大面积小，同理如果H[end]小，并且H[end]<H[end+1],也比保存的面积小。
于是加强条件如代码所示，start与end必须保持至少为1的距离，否则肯定为0结束循环，另外加强条件时，依然要保证H[start]与H[end]谁小谁的指针往中间挪动的道理

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针法
        int start = 0,end = height.size()-1;
        int maxarea=0;
        while(start!=end){
            if(height[start]<=height[end]){//谁小谁往中间挪动
                maxarea = max(maxarea,(end-start)*height[start]);
                start++;
                while(start+1 < end && height[start]<=height[start-1] && height[start]<= height[end]) start++;//start与end之间至少距离为1，start+1处高度比start处小，满足谁小谁指针挪动
            }else{
                maxarea = max(maxarea,(end-start)*height[end]);
                end--;
                while(start+1 < end && height[end]<=height[end+1] && height[start]> height[end]) end--;//start与end之间至少距离为1，end处高度比end+1处小，满足谁小谁指针挪动
            }
        }
        return maxarea;
    }
};
```