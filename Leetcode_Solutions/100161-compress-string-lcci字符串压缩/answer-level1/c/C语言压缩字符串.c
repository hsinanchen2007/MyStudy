### 解题思路
参考官方题解思路

### 代码

```c

char* compressString(char* S){
    int size = strlen(S);
    //申请新的字符串空间，长度与原字符串相同，因为超出原字符串长度会直接返回原字符串
    char *arr = (char *)malloc(sizeof(char) * (size + 1));
    int count = 1,index = 0;
    char ch = S[0]; //用一个字符记录前一个访问到的字符
    for(int i=1;i<=size;i++){
        if(S[i] == ch){
            count++;//当前字符与前一个相同，count+1
        }
        else{//当前字符与前一个不同，将当前字符的count的值写入字符串
            arr[index] = ch;
            int num = log10(count) + 1;//判断count的数字位数
            int num1 = num;
            while(count != 0){//将count从低位到高位转化为字符写入到字符串中
                arr[index + num] = count % 10 + '0';
                count = count / 10;
                num--;
            }
            index += num1 + 1;//更新下一次的写入位置
            ch = S[i];
            count = 1;
        }
        if(index >= size) return S;
    }
    arr[index] = '\0';
    return arr;
}


```