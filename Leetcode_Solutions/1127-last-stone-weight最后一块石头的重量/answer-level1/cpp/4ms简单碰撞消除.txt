### 解题思路
此处撰写解题思路
我们为了不改变函数传来的引用，先把数组拷贝到v上。
将v从大到小排序；n=v.size();
n>=2时，可以发生碰撞，产生两种结果，第一种同归于尽，此时只要将之后的石头一个个列在前头即可；
第二种是剩下一个碰撞之后的y-x，只要将其插入到应有的位置即可，比它大的提前放入，直到出现第一个不大于它的石头，将a插入
再将之后的石头一个一个插入，即可循环到最后；
至此，返回v【0】即可
### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()<=0)
        return 0;
        vector<int> v=stones;
        sort(v.rbegin(),v.rend());
        int n=v.size();
        int a=v[0];
        while(n>=2)
        {
            a=v[0]-v[1];
            if(a==0)
            {
                v[0]=0;
                v[1]=0;
                for(int i=0;i<n-2;i++)
                {
                    v[i]=v[i+2];
                }
                n-=2;
            }
            else{
                int i=0;
                while(i+2<n && v[i+2]>a)
                {
                    v[i]=v[i+2];
                    i++;
                }
                v[i]=a;
                i++;
                while(i<n-1)
                {
                    v[i]=v[i+1];
                    i++;
                }
                n-=1;
            }
        }
        return v[0];
    }
};
```