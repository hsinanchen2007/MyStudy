### 解题思路
此处撰写解题思路

### 代码

```c
int maximum69Number (int num){
    int del=(int)log10((double)num);
    int num_=0,del_=0,flag=0,num_2=num;

    do{
        del_=num/pow(10.0,del);
        if(del_==6){flag=1;break;}
        num_+=del_*pow(10.0,del);
        num-=del_*pow(10.0,del);
        del--;
    }while(num!=0);
    if(flag==1) return num_+9*pow(10.0,del)+num%(int)pow(10.0,del);
    else return num_2;
}
```