首先审题从题目给出的题意，与连续的数字个数有关，比如n=2时就是根据n=1的字符串“1”得来的。
此时n=2,应该返回“11”，为什么？其实就是原字符串中有1个1,组合起来就是"11".当n=3时上一
次的字符串为“11”就是2个1，组合起来就是"21"....
到n=5时上一次的字符串为“1211”，为1个1，1个2，2个1组合而成所以将这些字符全部组合起来就是
“111221”
代码：
char* strcat_s(char* t1, char* t2) {            //由于我的vs2019strcat总是报不安全的错误，所以自己写了一个，导致程序比较慢
    char* p;
    int i,j;
    if (t1 == NULL)
        return t2;
    
    p = (char*)malloc(sizeof(char) * (strlen(t1) + strlen(t2) + 1));
    for (i = 0; *(t1+i); i++) {
        p[i] = t1[i];
    }
    for (j = 0; *(t2 + j); j++,i++) {
        p[i] = t2[j];
    }

    
    p[strlen(t1) + strlen(t2)] = '\0';
    return p;
}

char* countAndSay(int n) {
    char *num = 0, *g = 0, *pro = 0;
    int i = 1, j, num_s=0;        

    while(!num)
        num = (char*)malloc(sizeof(char) * 2);
    
    num[0] = '1';
    num[1] = '\0';
    
    while (i < n) {     //n表示第几次
        for (j = 0, num_s = 0, pro = 0; j<= (int)strlen(num); j++) {
            if (num[j] != num[num_s]) {    
                g = (char*)malloc(sizeof(char) * 3);
                g[0] = j - num_s + '0';     //转换为字符
                g[1] = num[num_s];
                g[2] = 0;
                pro = strcat_s(pro, g);
                num_s = j;
            }                                                   
        }
        
        free(num);
        num = pro;
        i++;
    }
    return num;
}
