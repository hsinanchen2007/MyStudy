### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=1)
            return n;
        vector<int> rec(n+1,0);
        rec[0]=1;
        rec[1]=1;
        int temp=0;
        for(int i=2;i<n;++i){//前n-1长度可以不剪
            for(int j=1;j<=i;++j){
                temp=j*rec[i-j];
                if(temp>rec[i])
                    rec[i]=temp;
            }
        }
        for(int k=1;k<n;++k){
            temp=k*rec[n-k];
            if(temp>rec[n])
                rec[n]=temp;
        }
        return rec[n];
    }
};
```