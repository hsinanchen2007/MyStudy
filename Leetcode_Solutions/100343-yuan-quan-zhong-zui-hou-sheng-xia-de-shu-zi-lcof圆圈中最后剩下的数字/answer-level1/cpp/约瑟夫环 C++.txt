1. 直接模拟，显然超时
```
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> a(n);
        int i = 1;
        while(i < n){a[i]=i;}
        i = 0;
        while(a.size()>1){
            int j = 1;
            while(j%m != 0){
                if(i == a.size()-1) i=0;
                i++; j++;
            }
            if(i == a.size()-1){
                a.erase(a.begin()+i);
                i=0;
            }else{
                a.erase(a.begin()+i);
            }
        }
        return a[0];
    }
};
```

2. 约瑟夫环问题 `f(N,M)=(f(N−1,M)+M)%N`
推荐讲解：[约瑟夫环——公式法（递推公式）](https://blog.csdn.net/u011500062/article/details/72855826)
```
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (m == 0 || n == 0) return -1;
        int p = 0;
        for(int i =2; i<=n; i++){
            p = (p+m)%i;
        }
        return p;
    }
};
```

