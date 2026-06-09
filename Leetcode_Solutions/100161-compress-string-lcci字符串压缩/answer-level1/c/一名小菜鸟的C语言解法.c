### 解题思路
此处撰写解题思路

### 代码

```c
char* compressString(char* S){
    int t=0,j=0,i=0;
    int count=1;    //计数
    char temp[50001]="\0";       //临时数组存放压缩后的数组
    char number[10];    //数字0到9的字符数组
    char inttoChar[5];  //存放count转化的字符串
    for(int i=0;i<10;i++){ //number[0]='0'
        number[i]=48+i;
    }
    for(i=0;S[i]!='\0';i++){
        if(S[i+1]==S[i]){
            count++;
        }else if(j<50000){
            temp[j++]=S[i]; 
            while(count>0){ //count转化成字符串
                inttoChar[t++]=number[count%10];
                count/=10;
            }
            while(t>0){     //把count字符串加入temp临时数组
                if(j<50000){
                    temp[j++]=inttoChar[--t];
                }else{
                    break;
                }
            }
            count=1;
        }else{
            break;
        }
    }
    if(i>j){
        S=temp;
    }
    return S;
}
```