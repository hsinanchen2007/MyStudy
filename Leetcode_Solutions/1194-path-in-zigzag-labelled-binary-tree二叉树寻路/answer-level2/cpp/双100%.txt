### 解题思路
偶数行找到层次遍历的编号，奇数行直接插入，但是要找到上一行对应的下标

### 代码

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> inde;
        int i=0;
        for(i=0;i<=10000;++i)
        {
            if(pow(2,i)<=label&&pow(2,i+1)-1>=label)
                break;
        }
        i++;
        while(label!=1)
        {
            int temp;
            if(i%2==0)
            {
                inde.insert(inde.begin(),label);
                temp=pow(2,i)-1-label+pow(2,i-1);
                label=temp/2;
                i--;
            }
            else
            {
                inde.insert(inde.begin(),label);
                label=pow(2,i-1)-1-label/2+pow(2,i-2);
                i--;
            }
        }
        inde.insert(inde.begin(),1);
        return inde;
    }
};
```