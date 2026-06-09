### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> num(n);
        for(int i=0;i<n;++i) num[i]=i+1;
        int kind,loop(n);
        for(int i=0;i<loop;++i){
            kind=(k-1)/fact(n-1);//确定在第几分叉中
            res+=(num[kind]+'0');
            num.erase(num.begin()+kind);
            k=k-kind*fact(n-1);
            --n;
        }
        return res;

    }
    int fact(int num){//阶乘函数
        int res(1);
        while (num >1)
            res=res*(num--);
        return res;
    }
};
```