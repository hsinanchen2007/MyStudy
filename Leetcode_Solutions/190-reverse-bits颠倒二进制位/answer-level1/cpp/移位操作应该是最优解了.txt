不断的把n的最后一位输送到res的最后一位，res再不断的左移。  

 uint32_t res = 0;
    int index = 32; //操作32次移位操作
        while(index--)
        {
            res<<=1;//结果左移一位，空出位置与n最后一位相加
            res+=n&1; //加上n的最后一位
            n>>=1;    //n右移一位，供下一轮与结果相加
        }
        return res;
    }