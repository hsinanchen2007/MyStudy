解题思想：建立一个对应长度的HightLight数组，数组中置1代表需要加粗，否则不需要，对于每个查询词都进行查询，记录出所有需要置1的地方，然后按照HightLight数组的连续0和连续1的位置加入<b> </b>

Strstr函数超长查询出错。。。（70/72）
自己写HighLightWords1 就不会出错。。。
解题使用的是HighLightWords1,大家可以尝试下使用strstr，会有诡异的错误。。。。

void HighLightWords(char *input, char *word, int *highLight)
{
  int pos = 0;
  int len = strlen(input);
  int wordSize = strlen(word);
  char *temp = input;

  while (pos < len - 1) {
    char *pos1 = strstr(temp, word);
    if (pos1 != NULL) {
      pos = pos1 - input;
      for (int i = 0; i < wordSize; i++) {
        highLight[pos + i] = 1;
        pos1++;
      }
      if(wordSize!=1){
        pos1--;
      }
      temp = pos1;
    } else {
      pos = len;
    }
  }
}

/*对传入的word和input，标记相应的位置*/
void HighLightWords1(char *input, char *word, int *highLight) {
  int pos = 0;
  int len = strlen(input);
  int wordSize = strlen(word);
  char *temp = input;
  int flag = 0;
  int wordPos=0;

  while (pos <=len - 1) {
    if (input[pos]==word[wordPos]){
      flag =1;

      for(int i=1;i<wordSize;i++){
        if(pos+i>len-1){
          flag = 0;
          break;
        }
        if(input[pos+i]!=word[wordPos+i]){
          flag = 0;
        }
      }

      if(flag==1){
        for (int i = 0; i < wordSize; i++) {
          highLight[pos + i] = 1;
        }
      }
    }
  
  wordPos=0;
  pos++;
  }
}

  wordPos=0;
  pos++;
  }
}

/*处理输出，实际上是一次遍历*/
char *GetOut(char *input, int *highLight) {
  int inputLen = strlen(input);
  char *out = (char *)malloc(8048 * sizeof(char));
  int start = 0;
  for (int i=0; i < inputLen; i++) 
  {
    if (highLight[i] == 0) {
      out[start] = input[i];
      start++;
    } else {
      out[start] = '<';
      start++;
      out[start] = 'b';
      start++;
      out[start] = '>';
      start++;

      while (i < inputLen) {
        if (highLight[i] == 0) {
          break;
        }
        out[start] = input[i];
        start++;
        i++;
      }
      i--;
      out[start] = '<';
      start++;
      out[start] = '/';
      start++;
      out[start] = 'b';
      start++;
      out[start] = '>';
      start++;
    }
  }
  out[start] = '\0';
  return out;
}

char * boldWords(char ** words, int wordsSize, char * S){
  int *highLight =(int *)malloc(512*sizeof(int));
  memset(highLight, 0, sizeof(int) * 512);
  for (int i = 0; i < wordsSize; i++) {
        HighLightWords1(S, words[i],highLight);
  }
  char *output = GetOut(S, highLight);
  return output;
}
