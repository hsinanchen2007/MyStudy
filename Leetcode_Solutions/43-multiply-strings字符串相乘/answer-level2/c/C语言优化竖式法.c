### 解题思路
![图片.png](https://pic.leetcode-cn.com/9f78871fe3a060445a2f577c527836d179132219948d61f9f206af519c8152e2-%E5%9B%BE%E7%89%87.png)

为了方便阅读，把一些步骤写成了函数。
解题方法就是优化竖式法

### 代码

```c
/*
outputnum short数组，存放结果
a           参与乘法运算的数
b           参与乘法运算的数
i、j        下标
a*b的结果有两位，这两位分别与数组outputnum[j+i]和outputnum[j+i+1]相加进位后，再存回数组中
函数返回值为进位carry，如果产生了进位就返回1
*/
short cacul(short *outputnum,short a,short b,int i,int j){//
        short c=a*b;
        short first=(a*b)/10;
        short second=(a*b)%10;
        short carry=0;
        outputnum[i+j]=first+outputnum[i+j];
        outputnum[i+j+1]=second+outputnum[i+j+1];
        if(outputnum[i+j+1]>9){
            outputnum[i+j+1]=outputnum[i+j+1]-10;
            carry=1;
        }
        outputnum[i+j]=outputnum[i+j]+carry;
        if(outputnum[i+j]>9){
            outputnum[i+j]=outputnum[i+j]-10;
            return 1;
        }
        return 0;
}
/*
    进位处理函数
    carry为进位，1代表进位。例如：999.....，第三个9接受了进位后会加1，产生连锁进位
    处理进位，修正各个数组元素的值，是这个函数的目的
*/
void carrypro(short *outputnum,int i,int j,short carry){
    for(int k=i+j-1;k>=0;k--){
		outputnum[k]=outputnum[k]+carry;
        if(outputnum[k]>9){
            outputnum[k]=outputnum[k]-10;
            carry=1;
			continue;
		}else{
			carry=0;
			break;
		}
    }
}
/*
    将short数组变成char数组，后者经过简单加工就是我们想要的结果
*/
void shortostring(short *outputnum,char *output,short len){
    for(int i=0;i<len-1;i++){
        output[i]='0'+outputnum[i];
    }
	output[len-1]='\0';
}
/*
    主体函数
*/
char * multiply(char * num1, char * num2){
    short len1=strlen(num1);
    short len2=strlen(num2);
    short *numnum1= (short*)malloc(sizeof(short)*len1);
    short *numnum2= (short*)malloc(sizeof(short)*len2);
    short *outputnum=(short*)malloc(sizeof(short)*(len1+len2));
    char *output=(char*)malloc(sizeof(char)*(len1+len2+1));
    for(int i=0;i<(len1+len2);i++){
		outputnum[i]=0;
	}
    for(int i=0;i<len1;i++){
        numnum1[i]=num1[i]-'0';
    }
    for(int i=0;i<len2;i++){
        numnum2[i]=num2[i]-'0';
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            int carry=0;//进位
            carry=cacul(outputnum,numnum1[i],numnum2[j],i,j);
            carrypro(outputnum,i,j,carry);
        }
    }
    shortostring(outputnum,output,len1+len2+1);
    int r=0;
    while(output[r]=='0'&&r<len1+len2-1){
        r++;
    }
    return output+r;
}
```