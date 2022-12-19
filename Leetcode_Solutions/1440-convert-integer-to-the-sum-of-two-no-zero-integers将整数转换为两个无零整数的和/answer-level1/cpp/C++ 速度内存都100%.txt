![image.png](https://pic.leetcode-cn.com/2ae0b4c194b7a4b184458e255c9a4a6ba72c5bbc29eb95d2cd06010c85170bda-image.png)
解题思路：i从1到n，判断i和n-i是否同为无零整数。
```
    vector<int> getNoZeroIntegers(int n) {
        //if()
        vector<int> res;
        for(int i = 1;i<=n;++i){
            int tmp = n-i; int tmpi = i;
           while(tmpi  != 0){
                if(tmpi%10 ==0) break;
                tmpi /= 10;
           }
           if (tmpi != 0) continue;
           while(tmp  != 0){
                if(tmp%10 ==0) break;
                tmp /= 10;
           }
              if(tmp == 0) {res.push_back(i);res.push_back(n-i);break;}
        }
        return res;
    }
```
