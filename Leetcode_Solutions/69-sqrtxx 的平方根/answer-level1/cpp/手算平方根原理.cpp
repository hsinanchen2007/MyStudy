大家都写的是二分法和牛顿迭代法
这个是手算平方根的原理和写法
```
    int _0To9(int x){
        if(x < 100 && x >= 81){
            return 9;
        }
        if(x < 81 && x >= 64){
            return 8;
        }
        if(x < 64 && x >= 49){
            return 7;
        }
        if(x < 49 && x >= 36){
            return 6;
        }
        if(x < 36 && x >= 25){
            return 5;
        }
        if(x < 25 && x >= 16){
            return 4;
        }
        if(x < 16 && x >= 9){
            return 3;
        }
        if(x < 9 && x >= 4){
            return 2;
        }
        if(x < 4 && x >= 1){
            return 1;
        }
        if(x == 0){
            return 0;
        }
        return -1;
    }

    // 手算平方根原理
    // 基本原理(a*N + b) = (a*N)^2 + b*(b+2*a*N)
    // 下面这个是10进制的
    int mySqrt(int x) {
        // 判断正负
        if(x < 0){
            return -1;
        }
        // 结果
        int res = 0;
        // 如果输入在100以内
        if((res = _0To9(x)) != -1){
            return res;
        }
        // 记录位数
        int digits = 0;
        res = x;
        while(res){
            res /= 10;
            ++digits;
        }
        res = 0;
        if(digits % 2){
            --digits;
            res = x / (int)pow(10, digits);
            res = _0To9(res);
        }
        else{
            digits -= 2;
            res = x / (int)pow(10, digits);
            res = _0To9(res);
        }
        while(digits > 0){
            digits -= 2;
            int b = 100 * res * res;
            int numBuf = x / (int)pow(10, digits);
            numBuf -= b;
            b = numBuf / (20 * res);
            if(b * (b + 20 * res) > numBuf){
                --b;
            }
            res = res * 10 + b;
        }
        return res;
    }
```
