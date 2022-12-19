### 解题思路
路径压缩比暴力排序用的时间还多。。。不过学到了一种方法，顺便复习了数据结构
但是，，，C++不能声明全局数组吗？findPos必须传数组进去可太难受了。。。

### 代码

```cpp
class Solution {
    
public:
    int minIncrementForUnique(vector<int>& A) {
        //线性探测+压缩路径
        if (A.empty()) return 0;
        // -1表示空位
        vector<int> pos(80000, -1); 
        int move=0;
        for(int a:A){
            int b=findPos(a,pos);
            move += b-a;
        }
        return move;
    }
    int findPos(int a,vector<int> &pos){
        int b=pos[a];
        if(b==-1){
            //a这个位置还有空
            pos[a]=a;
            return a;
        }else{//否则向后寻找空位
            b=findPos(b+1,pos);//递归寻找后一个位置，直到这个位置为空
            pos[a]=b;//压缩路径
            return b;
        }        
    }
};
```

#### 暴力破解

```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n=A.size();
        sort(A.begin(),A.end());
        int move=0;
        for(int i=1;i<n;i++){
            if(A[i]<=A[i-1])
                {
                    int pre=A[i];
                    A[i]=A[i-1]+1;
                    move+=A[i]-pre;
                }
        }  
        return move;
    }
};
```