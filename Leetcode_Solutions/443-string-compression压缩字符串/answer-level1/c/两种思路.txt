### 解题思路
思路1：就是先找到和上一个字母不同得地方，在把数字添进去，让后其余位置置为！ 例如：a a a b b b -> a 3 ! b 3 !
然后循环将 ！处的值与 非！的值替换，并将替换处置 ！  eg: a 3 ! b 3 ! -> a 3 b 3 ! !

思路2：还有一个更简单的办法就是 双指针从头尾往中间遍历，头不动，尾往头走，走到和头不等处，改值并且让 头 == 尾，尾置末在往头走，不断循环

### 代码

```c
int compress(char* chars, int charsSize)
{
    if(charsSize < 2)
        return charsSize ;
   int i = 0,nums = 1,ret = 0;
    char cur = '0';       //定义一个判定值
    while(i < charsSize)
    {
        if(cur != chars[i])      //当出现和判定值不同的值后，更改判定值
        {
            cur = chars[i];
            if(nums > 1)           
            {   
                if(nums < 10) 
                {
                   chars[ret + 1] = '0' + nums;         //更改相同值处为 数字， b b b  -> b 3
                   for(int j = ret + 2; j < i; ++j)   //后面直到出现非相同值的地方都改为字符0
                     chars[j] = '!'; 
                }
                else  //当出现大于10的情况
                {                    
                    int p = nums % 10;
                    chars[ret + 2] = '0' + p;
                    int q = nums;
                    while(q > 9)         //预防出现十位数以上
                    {
                        q /= 10;
                    }
                   chars[ret + 1] = '0' + q;          //更改相同值处为 数字， b b b  -> b 3
                   for(int j = ret + 3; j < i; ++j)   //后面直到出现非相同值的地方都改为字符0
                     chars[j] = '!'; 
                }
            }
            nums= 1;                   //相同次数置一
            ret = i;
        }
        else     
            ++nums;
        ++i;
           
    }
    if(nums > 1)
    {
        if(nums < 10)
        {
           chars[ret + 1] = '0' + nums;
           for(int k = (ret + 2); k < charsSize; ++k)
             chars[k] = '!';
        }
                else  //当出现大于10的情况
                {                    
                    int p = nums % 10;
                    chars[ret + 2] = '0' + p;
                    int q = nums;
                    while(q > 9)         //预防出现十位数以上
                    {
                        q/= 10;
                    }
                   chars[ret + 1] = '0' + q;          //更改相同值处为 数字， b b b  -> b 3
                   for(int k = ret + 3; k < i; ++k)   //后面直到出现非相同值的地方都改为字符0
                     chars[k] = '!'; 
                }
    }
    int m = 0;
    for(int k = 0; k < charsSize; ++k)
    {
        if(chars[k] == '!')
        {
            m = k;
            for(int q = k + 1; q < charsSize; ++q)
            {
                if(chars[q] != '!')
                {
                    chars[m] = chars[q];
                    chars[q] = '!';            //
                    break;
                }
            }
           // printf("%d",m);
            if(chars[m] == '!')
            {
              
               return m;
            }
                
        }
                  
    } 
    //printf("%d",m);
    return charsSize;
        
}
```