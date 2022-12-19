__暴力法，从left一直遍历到right，判断每个数是否是自除数。__

__结果：__

![image.png](https://pic.leetcode-cn.com/36c81c28748664c14f750b34edd0d2368bb56ff6a7340b2466d5758769592a93-image.png)

__代码：__
```
vector<int> selfDividingNumbers(int left, int right){
        vector<int> res; //结果数组
        for(int i=left; i<=right; i++){
            int num = i;
            int flag = 0; // 是否是自除数标志变量，0不是，1是
            while(num){
                int digit = num % 10;
                if( digit != 0 && i%digit == 0 ){
                    flag = 1;
                    num /= 10;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag){
                res.push_back(i);
            }
        }
        return res;
    }
```