### 解题思路
1、先依次比较两个字符串中的字符，获得最大的公共字符串，要求的结果必然包含在公共字符串中
//引入小串的概念。小串就是公共字符串的前若干字符的子串，例如abcd的小串就是a或ab或abc或自身
//引入大字符串的概念，大字符串就是题目给出的原始字符串。
2、在strcompare，匹配小串与大字符串，看是否能divide。
3、如果两个小串和大字符串都能divide，就返回这个小串为结果
用注释的方式解释

真的烦，这个题不难，但很琐碎。秀不起来，总是被控住。
### 代码

```c
int strcompare(char*str,char *substr,int strlen,int sublen){
	int flag=0;
    if(strlen%sublen!=0){//长度上都不能整除，说明内容上也不能divide
        return 1;
    }
	for(int i=0;i<strlen;i++){//内容上的是否divide判断
		if(str[i]!=str[i%sublen]){
			flag=1;
			break;
		}
	}
	return flag;
}
char * gcdOfStrings(char * str1, char * str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    int len =(len1<len2)?len1:len2;
    int maydividlen=0;//公共字符串长度
    for(int i=0;i<len;i++){
        if(str1[i]!=str2[i]){
            break;
        }
        maydividlen++;
    }
    if(maydividlen==0){//第一个字符就不匹配，直接“”
        return "";
    }
    int i;
    for(i=maydividlen;i>0;i--){
        char *dividstr=(char*)malloc(sizeof(char)*(i+1));
        strncpy(dividstr,str1,i);dividstr[i]='\0';//拷贝，候选小串来自公共字符串
        int flag=0;                                //通过了检测可成为返回结果
        flag=strcompare(str1,dividstr,len1,i);
        if(flag==1){
            continue;
        }
        flag=strcompare(str2,dividstr,len2,i);
        if(flag==0){
            return dividstr;
        }
    }
    return "";
}
```