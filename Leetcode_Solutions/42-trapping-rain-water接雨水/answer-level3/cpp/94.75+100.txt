### 解题思路
先找到最高点，然后找到最高点(M)之前的次高点(Front_Sec)和之后的次高点(Behind_Sec)；分两段计算；对之前的那段面积，计算最高点(Front_M=M)、次高点(Front_Sec)之间的面积，然后用次高点更新最高点（Front_Sec=Front_M）；对之后的面积同理。
时间复杂度O(n^2)；可能可以通过哈希表存储大小位置加快速度？研究下别人的思路。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxH=0,Front_Sec,Front_M,Behind_Sec,Behind_M,Squ=0,tmp=0;
        for(int i=1;i<n;i++)//find max_i
        {
            if(height[maxH]<height[i])
            {
                maxH=i;
            }
        }
        //计算H之前的面积
        Front_M=maxH;
        while(Front_M>0)//
        {
            Front_Sec=0;tmp=0;
            for(int j=1;j<Front_M;j++)
            {
                if(height[Front_Sec]<height[j])
                {
                    Front_Sec=j;
                }
            }
            if(Front_M!=Front_Sec+1)
            {
                for(int j=Front_Sec;j<Front_M;j++)
                {
                   tmp+=height[j];
                }
                Squ+=(Front_M-Front_Sec)*height[Front_Sec]-tmp;
            }
            
            Front_M=Front_Sec;cout<<Squ;
        }
        Behind_M=maxH;
        while(Behind_M<n-1)//
        {
            Behind_Sec=n-1;tmp=0;
            for(int j=n-2;j>Behind_M;j--)
            {
                if(height[Behind_Sec]<height[j])
                {
                    Behind_Sec=j;
                }
            }
            if(Behind_M!=Behind_Sec+1)
            {
                for(int j=Behind_Sec;j>Behind_M;j--)
                {
                   tmp+=height[j];
                }Squ+=(Behind_Sec-Behind_M)*height[Behind_Sec]-tmp;
            }
            
            Behind_M=Behind_Sec;
        }
        return Squ;
    }
};
```