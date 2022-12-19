**优点**：用时短
**思路**：通过数组下标将罗马数字与整数数值联系（想法来自[hello_pretty的罗马数字转整数（C语言）](https://leetcode-cn.com/problems/roman-to-integer/solution/luo-ma-shu-zi-zhuan-zheng-shu-cyu-yan-by-zed-65536/)）。然后map函数检索s中罗马数字对应的下标值，进行与下一个数字的比较，之后依据下标值获取整数数值。

**代码**
char roman[7]="IVXLCDM";
int Int[7]={1,5,10,50,100,500,1000};
int map(char c){
    int i = -1;
    for(i=0;i<7;i++){
        if(roman[i] == c){
            break;
        }
    }
    if(i >= 0){
        return i;
    }
    else{
        return 0;
    }
}
int romanToInt(char * s){
    int i,sum = 0;
    for(i=0;i<strlen(s)-1;i++){
        if(map(s[i])>=map(s[i+1])){
            sum += Int[map(s[i])];
        }
        else{
            sum -= Int[map(s[i])];
        }
    }
    sum = sum+Int[map(s[strlen(s)-1])];
    return sum;
}