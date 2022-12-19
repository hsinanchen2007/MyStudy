**思路**

- 向右对齐两个字符串，在短的前面补0，因此需要构造新的字符数组；
- 始终令a为长数组（若b长则交换a/b），将b的值加在a上；
- 第0位单独处理，否则第0位产生进位时会溢出；

**代码**

    char * addBinary(char * a, char * b){
        int i,count = 0;
        
        if(strlen(a) < strlen(b)){
            char *temp = a;
            a = b;
            b = temp;
        }
        int len_a = strlen(a);
        //短字符串前补‘0’，对齐长字符串
        char *c = (char*)malloc(len_a);
        memset(c,'0',len_a);
        memcpy(c+strlen(a)-strlen(b),b,strlen(b));
        //从后往前逐个相加，count为进位标志
        for(i=len_a-1; i>=0; i--){
            if(a[i] -'0' + c[i] - '0' + count < 2){ 
                
                a[i] = a[i] + c[i] + count - '0';
                count = 0;
            }
            else if(a[i] -'0' + c[i] - '0' + count == 2){ 
                a[i] = '0';
                count = 1;
            }
            else if(a[i] - '0' + c[i] -'0' + count == 3){ 
                a[i] = '1';
                count = 1;
            }
        }
        //第0位需单独处理，否则会溢出
        if(count == 1){
            char *res = (char*)malloc(len_a+2);
            memset(res,'0',len_a+2);
            res[0] = '1';
            strcpy(res+1,a);
            return res;
        }
        return a; 
    }
