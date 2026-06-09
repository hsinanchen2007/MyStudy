### 解题思路
题目本身很简单    
这里利用了一下题例的一个设定：全局变量是共享的  一次操作求出所有数列后直接取就行了 

### 代码

```cpp
vector<int>T;
class Solution {
public:
    int tribonacci(int n) {
        if(T.size()==0){
            T.push_back(0);
            T.push_back(1);
            T.push_back(1);
            for(int i=0;i<35;i++){
                T.push_back(T[i+2]+T[i+1]+T[i]);
            }
        }
            return T[n];
    }
};
```