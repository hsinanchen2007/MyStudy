### 解题思路
菜鸟一个，本方法利用旋转数组中的环状替换法解题的，执行用时还行，内存消耗应该是做到比较低了
![1584436504(1).png](https://pic.leetcode-cn.com/f56b9834410f0450e2aca25464ac0b788765954549671fd9c6acf5b1684fd085-1584436504\(1\).png)

### 代码
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int len=matrix[0].size();
    int temp=0;
    int x=0,y=0;
    int n=len/2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<len-2*i-1;j++)
        {
            x=len-1-i;
            y=len-1-i-j;
            int x1=x;
            int y1=y;
            int previous=matrix[x][y];
            do{
                temp=matrix[y1][len-x1-1];
                matrix[y1][len-x1-1]=previous;
                previous=temp;
                int temp2=x1;
                x1=y1;
                y1=len-temp2-1;
            }while(!(x1==x&&y1==y));
        }
    }
    }
};
```