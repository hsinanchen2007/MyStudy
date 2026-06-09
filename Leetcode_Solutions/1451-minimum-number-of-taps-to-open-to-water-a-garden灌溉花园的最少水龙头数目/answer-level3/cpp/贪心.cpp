### 解题思路
![image.png](https://pic.leetcode-cn.com/4c8d7c88b6d9e02a3dae89df5ec80e8f166e4aca2201626ad6b7336a0a3a64d0-image.png)
编程菜鸡，目前只会用C++和java。这道题之前算法设计作业做过一个类似的，是poj上的1328。第一次提交写的递归，结果超内存了，然后就写成循环了。
先用两个vector来存每个水龙头能覆盖到的区域的左边界和右边界，ranges=0就不考虑。每次找一个左边界小于leftPos并且右边界大于目前rightPos的水龙头作为bestTips，如果找不到就返回-1.
### 代码

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> left;
        vector<int> right;
        for(int i=0;i<n+1;i++){
            if(ranges[i]!=0){
                left.push_back(i-ranges[i]);
                right.push_back(i+ranges[i]);
            }
        }
        int len=left.size();
        int bestTips=-1,num=0,leftPos=0,rightPos=0;
        while(rightPos<n){
            for(int i=0;i<len;i++){
                if(left[i]<=leftPos){
                    if(right[i]>rightPos){
                        rightPos=right[i];
                        bestTips=i;
                    }
                }
            }
            if(bestTips!=-1){
                num++;
                leftPos=rightPos;
                bestTips=-1;
            }
            else
                return -1;
        }
        return num;
    }
};
```