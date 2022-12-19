### 解题思路
 从题目可知，除了部分特殊的字符，罗马数字都是从大到小，特殊字符就是入IV这种后一个字符大于前一个字符。所以依次遍历所有字符并累加对应的值，当后一个字符的值大于上一个字符的值时就减2次上一个字符车值；使用哈数表减少采遍历数组的的次数

### 代码
// 优化版-使用哈希表
int get_num(char c){
    char * romas={"IVXLCDM"};
    int nums[26]={};
    nums['I'-'A']=1;
    nums['V'-'A']=5;
    nums['X'-'A']=10;
    nums['L'-'A']=50;
    nums['C'-'A']=100;
    nums['D'-'A']=500;
    nums['M'-'A']=1000;
    return nums[c];
}

int romanToInt(char * s){
    int last=0;
    int sum=0;
    while(*s!='\0'){
        int current=get_num(*s-'A');
        sum+=current;
        if(current > last){
            sum-=2*last;
        }
        last=current;
        s++;
    }
    return sum;
}
```