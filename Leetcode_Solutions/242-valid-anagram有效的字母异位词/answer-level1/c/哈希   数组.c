### 解题思路
先判断字符串长度是否想等
然后分别用s和t去遍历两个数组 如果s和t是字母异位词 遍历后的数组mapS和mapTs应该是一样的
比较两个数组 若不一样 返回false
（参考了两个大佬的代码 以上）
### 代码

```c
bool isAnagram(char * s, char * t){
      int Len_t=strlen(s),Len_s=strlen(t);

      if(Len_s!=Len_t) return false;
      else
      {
          int mapS[26]={0};
          int mapT[26]={0};

          for(int i=0;i<Len_s;i++) mapS[s[i]-'a']++;
          for(int i=0;i<Len_t;i++) mapT[t[i]-'a']++;

          for(int i=0;i<26;i++)
          {
              if(mapS[i]!=mapT[i]) return false; 
          }

          return true;
      } 
    }
```