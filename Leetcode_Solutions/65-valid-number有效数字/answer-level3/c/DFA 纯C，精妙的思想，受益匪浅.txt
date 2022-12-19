状态机驱动，效率稳定双100，学习了
![image.png](https://pic.leetcode-cn.com/e360e7151ea2e89765042a0599baea50e8a87bf8fd3cdfbcfdb47a0b4bda6ed5-image.png)


最完整的数字表示，N表示数字
**(±N.Ne±N)**
![微信图片_20200401232934.jpg](https://pic.leetcode-cn.com/599920486082c6bc51553d9fdc9d27db4cf7e5ea0b0f33929556224bc34ad08a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200401232934.jpg)
状态表
![image.png](https://pic.leetcode-cn.com/18ac3abe1481bf78db4c0f8047dc1de943acb145a047afd4ea69483696252044-image.png)

为了方便对比理解，状态序号已调整与精选一致。
中间有一处差异，状态6时小数点进来是走向2还是走向3，本质是“3.”是否算自然数
用例结果是True

int move(char s)
{
    switch(s)
    {
        //space/+-/小数点/E/数字/字母
        case ' ': return 0;
        case '+':
        case '-': return 1;
        case '.': return 2;
        case 'e': return 3;
        default:
            if(s >= 48 && s <= 57) 
            {
                return 4;
            }

            else
            {
                return -1;
            }
    }
}

bool isNumber(char * s){
    int transfer[9][5] = {
        {0, 1, 2, -1, 6},
        {-1, -1, 2, -1, 6},
        {-1, -1, -1, -1, 3},
        {8, -1, -1, 4, 3},
        {-1, 7, -1, -1, 5},
        {8, -1, -1, -1, 5},
        {8, -1, 3, 4, 6},
        {-1, -1, -1, -1, 5},
        {8, -1, -1, -1, -1},
    };
    int s_len = strlen(s);
    int i, id;
    int finals = 0b101101000;
    int state = 0;

    for(i=0; i < s_len; ++i) {
        id = move(s[i]);
        if (id < 0) return false;
        state = transfer[state][id];
        if (state < 0) return false;
    }
    
    return (finals & (1 << state)) > 0;
}