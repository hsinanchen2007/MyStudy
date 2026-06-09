
看了其他大佬的题解，我深深膜拜，但是还是想说一下自己的小想法hahahhahah
主要思路：
第一步：先将一些特殊的情况判断了：
    比如除数是1的情况，就直接返回被除数就好
    除数是-1时也不能贸然返回被除数的负数，万一溢出了呢？此时判断一次啊就好
    除数是INT_MIN时很明显，没有人比他的绝对值更大了，所以判断是否被除数与其相同，相同返回1，不同返回0
    除数不能是零但是被除数可以，当被除数为零时，直接返回结果0
第二步：将负数转换成正数运算（看了之前一位大佬的题解之后觉得好像转换为负数更好算一点，毕竟正数边界很烦。。。。）
    设置一个变量fu用来标记结果的正负，fu有三种可能性，0，1，2，分别表示有0个负数1个负数2个负数，其中为1时就要返回负的结果
    判断除数是否为负，如果是，fu++，并且将其转换为相应正数
    判断被除数是否为负，如果是，fu++，并且将其转换为相应正数（需要注意，此时如果被除数是INT_MIN，直接转换会溢出，这时我的做法是将其加上已经转换为正数的divisor然后在转换，只需i++记录一下即可，）
    （转换为负数应该更轻松一点，不用考虑那么多）
第三步：关键步骤
    设置变量j来记录i此时的变化
    设置变量sum来记录i个divisor的和
    设置变量count来记录此轮sum增加了多少
    进入循环，首先判断sum+count是否超过了dividend（为了避免越界，使用sum<=dividend-count来判断）
            如果没有超过，更新sum ，sum+=count; count+=count;(每次sum增加的值都倍增，提高算法效率)
            如果超过了，判断count是否等于divisor如果是，则表明此时的i已经是最终结果 跳出循环
                                    如果不等，将count赋为divisor，继续循环（从最小的再开始加）
第四步：返回结果
    判断fu的值，fu为1时返回-i，其他返回i


    int divide(int dividend, int divisor){
        
        //判断几种特殊情况
        if(divisor == 1){
            return dividend;
        }else if(divisor == -1){
            if(dividend == -pow(2, 31)){
                return pow(2,31)-1;
            }
        }else if(divisor == INT_MIN){       //除数是INT_MIN的情况没有考虑到
            if(dividend != INT_MIN){
                return 0;
            }else
            {
                return 1;
            }
        }
        if(dividend == 0)    return 0;
        
        int i = 0;
        int fu = 0;
        if(divisor < 0){
            fu++;
            divisor = -divisor;
        }
        if(dividend < 0){
            fu++;
            //如果被除数是INT_MIN如果直接将其变为正数就会溢出，为了避免这种情况，我的做法是将其加上divisor，然后再变为正数，这样就可以避免溢出
            if(dividend == INT_MIN){
                dividend = -(dividend+divisor);
                i++;
            }else{
                dividend = -dividend;
            }
        }
        
        int j = 1;
        int count = divisor;
        int sum = 0;
        while(sum < dividend){
            if(sum <= dividend - count){
                sum+=count;
                if(count <= INT_MAX -count){
                    count+=count;                
                }
                i+=j;
                j+=j;
            }else if(count != divisor){
                count = divisor;
                j = 1;
            }else {
                break;
            }  
        }

        if(fu == 1)    
            return -i;
        else 
            return i;
        
    }