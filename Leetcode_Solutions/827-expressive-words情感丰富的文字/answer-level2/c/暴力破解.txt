typedef struct{
    char c;
    int num;
}item_s;

void get_letter_group(item_s * ptr, int* tot_num,char* s)
{
    int total_num = 0;
    char cur = s[0];
    int cur_num = 0;

    for(int i = 0; i < strlen(s); i++)
    {
        if(cur != s[i])
        {
            ptr[total_num].c = cur;
            ptr[total_num].num = cur_num;
            cur_num = 1;
            cur = s[i];
            total_num++;
        }
        else
        {
            cur_num++;
        }
    }
    if(cur == s[strlen(s)-1])
    {
         ptr[total_num].c = cur;
         ptr[total_num].num = cur_num;
         total_num++;
    }
    for(int i = 0; i < total_num; i++)
    {
        printf("%c, %d; ", ptr[i].c,ptr[i].num);
    }
    *tot_num = total_num;
    printf("\r\n");
}
bool is_stretchy_word(item_s * src, item_s * des,int tot_num_src, int tot_num_des)
{
   if(tot_num_src != tot_num_des)
   {
       return false;
   }
   for(int i = 0; i < tot_num_des; i++)
   {
       if(src[i].c != des[i].c)
       {
           return false;
       }
       if(src[i].num < 3)
       {
           if(src[i].num != des[i].num)
           {
               return false;
           }
       }
       else
       {
           if(src[i].num < des[i].num)
           {
               return false;
           }
       }
   }

   return true;
}
int expressiveWords(char * S, char ** words, int wordsSize){
    item_s * ptr = NULL;
    int total_num = 0;
     item_s * ptr1 = NULL;
     int total_num1 = 0;
     int num = 0;
     printf("%d", wordsSize);
     if(wordsSize == 1)
     {
         if(strlen(S) == 0 && strlen(words[0]) == 0)
         return 1;
     }
     if(wordsSize < 1)
     {
         return 0;
     }
     if(strlen(S) < 1)
     {
         return 0;
     }

    ptr = malloc(100 * sizeof(item_s));
    get_letter_group(ptr, &total_num,S);

    ptr1 = malloc(100 * sizeof(item_s));
    for(int i =0; i< wordsSize; i++)
    {
         memset(ptr1,0, 100 * sizeof(item_s));
         get_letter_group(ptr1, &total_num1,words[i]);
         if(is_stretchy_word(ptr,ptr1,total_num,total_num1))
         {
             num++;
         }
    }

    free(ptr1);
    free(ptr);
    return num;
}