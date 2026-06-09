### 解题思路
![微信图片_20200315150126.png](https://pic.leetcode-cn.com/42dfb5203c5a5105c61496981aacaa4b65b94074172a1cbb3493ead436bbfe54-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315150126.png)


### 代码

```c
int attach_str(char* cha,int indx,char* str,int cnt);

char * intToRoman(int num){
    int count=0;
    int count_index=0;
    char* result=(char*)malloc(20);
    int numbers[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *pool[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int m[13]={0};//存储pool中每个字符串的个数
    for(int i=0;i<13;i++){
        if(num==count){break;}
        m[i]=(num-count)/numbers[i];
        count+=m[i]*numbers[i];
    }
    for(int i=0;i<13;i++){
        count_index=attach_str(result,count_index,pool[i],m[i]);
    }
    result[count_index]='\0';//最后一个字符以‘\0’结尾
    return result;
}

int attach_str(char* cha,int indx,char* str,int cnt){//在字符串尾部添加字符
    for(int j=0;j<cnt;j++){
        for(int i=0;i<2;i++){
            if(!str[i]){break;return indx;}
            cha[indx++]=str[i];
        }
    }
    return indx;
}
```