### 解题思路
枚举，然后递归选出符合要求的数

### 代码

```cpp
class Solution {
public:
vector<int> ans;
int delta;
void func(int i,int len,int num){
    if(!len){
        if(ans.empty()||num!=ans.back())
        ans.push_back(num);
        return;
    }
    if(i<0||i>9)return;
    num=num*10+i;
    func(i+delta,len-1,num);
    func(i-delta,len-1,num);
}
    vector<int> numsSameConsecDiff(int N, int K) {
        delta=K;
        if(N==1)ans.push_back(0);
        for(int len=N,i=1;i<10;i++,len=N)
            func(i,len,0);
        return ans;
    }
};
```