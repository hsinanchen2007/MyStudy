### 解题思路
辗转相除法原理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
解题原理：两个字符串的最大公因子等于其中较短的那个串和长串减去短串剩下子串的公因子。
1.设长串为A短串为B，两串从头开始比较，如果短串B不是长串A从头开始的子串，则不存在公因子。如果短串B是长串A从头开始的子串，称串C=A-B叫做差串吧，如果AB存在最大公因子那么串C也是由最大公因子组成的。
2.再将串C与串B代入步骤1进行比较。
![11.png](https://pic.leetcode-cn.com/26c43adcd52744995bf79ff57d2530d1df7cd48bdfa95175c54b8fea9aab3ca1-11.png)
划线的是长串减去短串剩下的差串，最后两个子串同时到达'\0'，则最后一次比较的子串就是最大公因子。
时间不会分析....，空间O(1)
### 代码
```c
char * gcdOfStrings(char * str1, char * str2){
    int i=0,j=0,m=0,n=0,sum=0; 
    while(str1[i]!='\0' && str2[j]!='\0'){
        sum = 0;
        while(str1[i]!='\0' && str2[j]!='\0'){
            if(str1[i] != str2[j]){
                char* result = (char*)malloc(sizeof(char)*1);
                result[0] = '\0';
                return result;
            }
            sum++;
            i++;
            j++;
        }
        if(str1[i]=='\0' && str2[j]!='\0'){
            i = m;
            n = j;
        }else if(str1[i]!='\0' && str2[j]=='\0'){
            j = n;
            m = i;
        }
    }
    char* result = (char*)malloc(sizeof(char)*(sum+1));
    for(int k=0;k<sum;k++){
        result[k] = str1[k];
    }
    result[sum] = '\0';
    return result;  
}
```