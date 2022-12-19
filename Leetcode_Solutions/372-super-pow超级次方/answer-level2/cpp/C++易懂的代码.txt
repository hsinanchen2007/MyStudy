### 解题思路
1. 注意到b是一个非常大的数组，所以无法直接计算出这个正整数。
2. 利用数学知识拆分幂次方取模 
3. 计算幂次方使用循环替换递归，提高时间性能。

### 代码

```cpp
class Solution {
public:
    const int modNumber=1337;
    int superPow(int a, vector<int>& b) {
        a =a %modNumber;
        int len=b.size();
        if(len<2){
            return pown(a,b[0]);
        }
        int result=1;
        for(int i=len-1;i>=0;i--){  
            result= result * pown(a,b[i]) % modNumber;         
            a=pown(a,10);
        }
        return result;
    }
    int pown(int number,int n){
            int result=1;
            while(n-->0){
               result=result* number % modNumber;
            }
            return result;
    }
};
```