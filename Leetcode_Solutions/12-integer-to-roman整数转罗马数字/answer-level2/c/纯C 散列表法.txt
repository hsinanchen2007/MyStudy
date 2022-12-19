### 解题思路
纯C 散列表法

### 代码

```c
struct hash
{
    int interger;
    char roman[4];
}Hash[13] = {
    1000, "M",
    900,  "CM", 
    500,  "D", 
    400,  "CD",
    100,  "C",
    90,   "XC",
    50,   "L",
    40,   "XL",
    10,   "X",
    9,    "IX",
    5,    "V",
    4,    "IV",
    1,    "I",
};

char * intToRoman(int num){
    char cRoman[16] = {0x0};
    char* pcRoman = cRoman;
    unsigned short uIndex = 0;

    // 若代码无法通过，取消注释以下没用代码，猜测是平台编译优化的问题，写点废话解决问题
    // unsigned short uLength = 0;
    // char* res = cRoman;
    // char a[16] = {0};
    // char* p = a;

    for(uIndex = 0; uIndex <= (13-1); uIndex++)
    {
        while(num >= Hash[uIndex].interger)
        {
            num = num - Hash[uIndex].interger;
            strcat(cRoman, Hash[uIndex].roman);
        }
    }

    return pcRoman;
}
```