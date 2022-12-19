### 解题思路


### 代码

```c
char * countAndSay(int n){
    if(n==1)
        return "1";
    char pre_str[10000]="1",str[10000]="",*p;   //pre表示前一项字符串，str表示对前一项的描述，p是因为直接返回str为空（不知道为什么）
    int count=1;    //count表示重复数量，如11，count=1;21,count=2;12,count=1;
    for(int i=1;i<n;i++){
        int k=0;    //k记录str字符串中位置
        char number;    //number表示重复字符，如11，number='1';21,number='1';12,number='2';
        for(int j=0;j<strlen(pre_str);j++){
            if(pre_str[j+1]=='\0'||pre_str[j]!=pre_str[j+1]){   //如果为数组最后一个字符或者相邻两个字符不等记录个数和字符
                number=pre_str[j];
                str[k++]='0'+count;
                str[k++]=number;
                count=1;
            }
            else{
                count++;
            }
        }
        strcpy(pre_str,str);
    }
    p=str;
    return p;
}

```