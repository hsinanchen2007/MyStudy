1. 如何字符串转数字
atoi(char*), return int
2. 如何数字转字符串
sprintf(str,"%d",value)
itoa(int value,char* str,int base)
3. 如何string转char*
(char*)string.c_str
4. 如何获取子字符串
str.substr()
5. 如何查找字符或子字符串位置
str.find()，注意输入的pos和返回的pos都为size_t类型，若找不到需与string::npos比较判断
6. 如何拼接字符串
直接+
