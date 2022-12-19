![QQ截图20190719073000.png](https://pic.leetcode-cn.com/d0f86c219dc897804f3b1da7a77e2211c9cb266508802845a0b8ae8f2162f287-QQ%E6%88%AA%E5%9B%BE20190719073000.png)

```
char * complexNumberMultiply(char * stra, char * strb){
    if (stra == NULL) return strb;
    if (strb == NULL) return stra;
    char *ret_str = (char *)malloc(64);
    if (ret_str == NULL) return NULL;//上面为初始化
    
    int stra_real;  //字符串a的实部
    int stra_comp;  //字符串a的虚部
    extraction_numbers(stra, &stra_real, &stra_comp);

    int strb_real;  //字符串b的实部
    int strb_comp;  //字符串b的虚部
    extraction_numbers(strb, &strb_real, &strb_comp);

    int ret_str_real = stra_real*strb_real + -stra_comp*strb_comp; //用公式
    int ret_str_comp = stra_real*strb_comp +  stra_comp*strb_real;
    
    sprintf(ret_str,"%d+%di", ret_str_real, ret_str_comp);
    return ret_str;
}
//提取数字
void extraction_numbers(char *str, int *real, int *complex)
{
    int i = 0;
    int sy_rea = 1;        //求虚部的符号，是正数还是负数
    if (str[0] == '-') {
        sy_rea = -1;
        ++i;
    }   
    *real = 0;
    for (; isdigit(str[i]); ++i) {
        *real *= 10;
        *real += str[i] - '0';
    }
    *real *= sy_rea;
    
    int sy_com = 1;        //求虚部的符号，是正数还是负数
    if (str[i+1] == '-') {
        sy_com = -1;
        ++i;
    }

    *complex = 0;
    for (++i; isdigit(str[i]); ++i) {
        *complex *= 10;
        *complex += str[i] - '0';
    }
    *complex *= sy_com;
}
```
