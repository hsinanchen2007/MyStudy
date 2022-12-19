看别的语言几行就搞定，C语言要哭死，根据测试同理调试了多次，终于搞出来了

#define MAXSIZE 10000

//注意多重嵌套的情况
//注意数字多位的情况
void decode(char *s, int beginIndex, int endIndex, int tempIndex);
char * decodeString(char * s){
    char *str;
    str = (char *)malloc(sizeof(char) * MAXSIZE);
    memset(str, 0, sizeof(char) * MAXSIZE);
    strncpy(str, s, strlen(s) + 1);
    
    int beginIndex = 0;
    int endIndex = 0;
    int tempIndex = 0;
    int flag = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ']') {
           continue;
        } else {
            flag = 0;
            endIndex = i;
            tempIndex = i;
            while(--tempIndex >= 0) {
                if (isalpha(str[tempIndex]) && flag == 0){
                    continue;
                } else if (str[tempIndex] == '[' && flag == 0) {  // 这里要注意flag标志，除了数字意外，其他情况都要判断flag，避免多重嵌套时出现异常。
                    beginIndex = tempIndex;
                    flag =1;
                    continue;
                } else if (isdigit(str[tempIndex])) {
                            continue;
                } else {
                            break;
                } 
            }
            decode(str, beginIndex, endIndex, tempIndex + 1);
            i = -1;
        }
    }
    return str;
}

void decode(char *s, int beginIndex, int endIndex, int tempIndex)
{
    char *temp;
    int total = 0;
    int tempLen = 0;
    int temp1Len = 0;
    temp = (char *)malloc(sizeof(char) * MAXSIZE);
    memset(temp, 0, sizeof(char) * MAXSIZE);

    
    //取出数字
    for (int i = tempIndex; i < beginIndex; i++) {
        int num1 = s[i] - '0';  //这里之前不小心把s[i]写成是[temoIndex],测试了好久。
        total = total*10 + num1;
    } 
       
    //取出字符串
    for (int i = 0; i < total; i++) {
        for (int j = beginIndex + 1; j < endIndex; j++) {
            temp[(j - beginIndex - 1) + i * (endIndex - beginIndex - 1)] = s[j];
            tempLen++;
        }
    }
    
    //用temp替换S字符串
    //保存后半段字符串
    char *temp1;
    temp1 = (char *)malloc(sizeof(char) * MAXSIZE);
    memset(temp1, 0, sizeof(char) * MAXSIZE);
    
    for (int i = endIndex + 1; s[i] != '\0'; i++) {
        temp1[i - endIndex - 1] = s[i];
        temp1Len++;
    }
    
    for (int i = tempIndex; i < tempIndex + tempLen; i++) {
        s[i] = temp[i - tempIndex];
    }
    for (int i = tempIndex + tempLen; i < tempIndex + tempLen + temp1Len; i++) {
        s[i] = temp1[i - tempIndex - tempLen];
    }
    s[tempIndex + tempLen + temp1Len] = '\0';
    
}

