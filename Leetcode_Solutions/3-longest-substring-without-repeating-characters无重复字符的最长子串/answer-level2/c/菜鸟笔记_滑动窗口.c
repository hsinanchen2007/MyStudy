### 解题思路
1.写代码的时候，如果出现多次调试熟悉代码，却始终无法得到正确结果，请检查sh一下自己的代码，看看哪里有没有多一个符合比如';'
2.滑动窗口：需两个指针，一个在窗口的前沿，一个在后沿。前面标记起始位置，后沿更多用来工作移动。
3.检查重复字符的办法可以用空间换时间，构建hashtable进行映射，这个思路应该好好体会，另外学习一个初始化函数memset(数组名称， 初始化的值， 数组大小)；
4.加油奥里给！
### 代码

```c

char gHashTable[256];

bool isDuplicated(char* ch){//如果已经有相同的字符了，那么会返回true
       if (gHashTable[*ch]){
           return true;
       }
       else{
           return false;
       }
   }
int lengthOfLongestSubstring(char * s){
   int MaxLength = 0;
   memset(gHashTable, 0, sizeof(gHashTable));
   char* p = s;//工作指针指向s的开头
   char* head = s;//记录当前字串的头
   int size;//记录字符串数组的长度
   size = strlen(s);//获取数组长度

   if (s == NULL){
       return 0;
   }
   if (size == 1){
       return 1;
   }
   int cnt;
   int i = 0;
   while (*p){
        cnt = p - head;
        if (cnt > MaxLength){
            MaxLength = cnt;            
            printf("第%d遍,cnt = %d, MaxLength = %d\n", ++i, cnt, MaxLength);
        }
        if (isDuplicated(p)){//重复

           while (*p != *head){
               gHashTable[*head] = 0;
               head++;
           }
           gHashTable[*head] = 0;
           head++;;
       }
       else{//不重复
           gHashTable[*p] = *p;
           p++;
       }
   }
   int num = p - head;;
    if (num > MaxLength){
           MaxLength = num;
    }
    return MaxLength;
}
```