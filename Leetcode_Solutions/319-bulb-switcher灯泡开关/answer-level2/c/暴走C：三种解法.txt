/*
有一个简单粗暴的方法。。。就是时间复杂度达到了O（n2）可能会超时，（事实证明果然超时）
方法一：从1遍历到n判断每个数有多少个因数，就是其切换开关的次数，则偶数为关，奇数为开
方法二： 设置一个数组，从i开始遍历，然后将其所有的倍数的count数组都+1
        最后判断数组中奇数的个数，即为结果
        还是runtimeout
方法三：eeeeee通过找规律，我发现如果一个数能够被开平方，它开关的次数就是奇数，也就是开的，于是。。我们又有了以下的算法
        只需算出从1到n到底有几个数能够开平方，
        可以对n进行开平方，得到的数就是结果，这次成功通过，只有一句代码，return pow（n, 0.5);可是用时跟内存消耗也并不小，是不是pow函数用时比较久。。。。
*/

第一种：
    int bulbSwitch(int n){
        int count = 0;
        for(int i = 1; i <= n; i++){
                
            int tmp = 0;
                
            for(int j = 1; j <= i/2; j++){
                if(i % j == 0){
                    tmp++;
                }
            }
            
                tmp++;
                if(tmp %2 == 1){
                count++;
            }
            
        }   
        return count;    
    }
第二种：
    int bulbSwitch(int n){
        int countSwitch[n+1];
            
        for(int i = 0; i < n+1; i++){
            countSwitch[i] = 0;
        }
            
        for(int i = 1; i < n+1; i++){
            for(int j = i; j < n+1; j+=i){
                countSwitch[j]++;
            }
        }
            
        int count = 0;
        for(int i = 1; i < n+1; i++){
            if(countSwitch[i] % 2 == 1){
                count++;
            }
        }
            
        return count;
            
    }
第三种：
    int bulbSwitch(int n){
        return pow(n, 0.5);
    }



