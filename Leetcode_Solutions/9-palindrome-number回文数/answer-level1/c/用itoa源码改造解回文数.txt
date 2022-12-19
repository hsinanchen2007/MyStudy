### 解题思路
因为itoaz用不了所以去查了查它源码，然后直接把最后数组反转改成了回文验证

### 代码

```c
#include <stdlib.h>

bool isPalindrome(int x){
    int i = 0,k,j;
    char str[100] = {0},ch[100] = {0};

    if(x < 0) return false;
    else if(x >= 0 && x < 10) return true;
    else{
        do	{		
            str[i++]=x%10;//取x的最后一位，并设置为str对应位，指示索引加1
        	x/=10;//x去掉最后一位
        }while(x);//直至x为0退出循环
        str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
        //将顺序调整过来
        int k=0;
        for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1	
        {				
            if(str[j]!=str[i-1+k-j]) return false;//尾部赋值给头部			
        }
        return true;
    }
}
```