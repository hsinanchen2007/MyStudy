### 解题思路
两个数组挨个字符进行比较，若两数组中的字符不相等，则判断typed中的字符是否与前一个字符重复，若重复，则比较下一个typed中的字符，直到其中一个数组比较完成。若name中有剩余，则返回0，若typed中有剩余，则应该都与前一个字符相同。

### 代码

```c
bool isLongPressedName(char * name, char * typed){
    int i=0,j=0;
    while(i<strlen(name)&&j<strlen(typed)){
        if(name[i]==typed[j]){
            i++;
            j++;
        }
        else {
            if(j>0&&typed[j]==typed[j-1])j++;
            else return false;
        }//else
    }//while
  if(i!=strlen(name))  return false;
  else if(j!=strlen(typed)){
      j++;
      while(j<strlen(typed)){
          if(typed[j]!=typed[j-1])return false;
      }//while
  }//else if
  return true;
}
```