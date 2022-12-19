### 解题思路
和95题一样，分开递归来解决，只是时间复杂度太大了，于是把部分结果直接储存起来。
通过增加递归出口，来减小时间复杂度
### 代码

```cpp
class Solution {
public:
    int getSubTree(int a,int b){
        int num=0;
        int l,r;
        if(a>b){
            return 1;
        }
        if(b-a==4)
            return 42;
        else if(b-a==2)
            return 5;
        else if(b-a==0)
            return 1;
        else if(b-a==1)
            return 2;
        else if(b-a==3)
            return 14;
        else if(b-a==5)
            return 132;
        else if(b-a==6)
            return 429;
        for(int i=a;i<=b;i++){
            l=getSubTree(a,i-1);
            r=getSubTree(i+1,b);
            num+=l*r;
        }
        return num;
    }
    int numTrees(int n) {
        return getSubTree(1,n);
    }
};
```