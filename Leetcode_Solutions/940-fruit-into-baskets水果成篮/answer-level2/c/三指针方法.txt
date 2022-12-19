
三指针法：

```
int totalFruit(int* tree, int treeSize){

   int start = 0;
   int num[2][3]={{0,0,0}, {0,0,0}}; 
   int max = 0;

   if(treeSize < 3)
   {
       return treeSize;
   }

   for(int i = 0; i < treeSize; i++)
   {
       if(num[0][0] == 0)
       {
           start = i;
           num[0][0] = 1;
           num[0][1] = tree[i];
           num[0][2] = i;
       }
       else if(num[0][0] == 1 && num[0][1] == tree[i])
       {
            num[0][2] = i;
       }
       else if(num[0][0] == 1 && num[0][1] != tree[i] && num[1][0] == 0)
       {
           num[1][0] = 1;
           num[1][1] = tree[i];
           num[1][2] = i;
       }
       else if(num[0][0] == 1 && num[0][1] != tree[i] && num[1][0] == 1 && num[1][1] == tree[i])
       {
          num[1][2] = i;
       }
       else
       {
           int tmp = 0;
           tmp = i - start;
           if(max < tmp)
           {
               max = tmp;
           }
           if(num[0][1] == tree[i-1])
           {
             start = num[1][2] + 1;
             num[1][0] = 1;
             num[1][1] = tree[i];
              num[1][2] = i;
           }
           else
           {
              start = num[0][2] + 1;
              num[0][0] = 1;
              num[0][1] = num[1][1];
              num[0][2] = num[1][2];

              num[1][0] = 1;
              num[1][1] = tree[i];
              num[1][2] = i;
           }
       }
   }
   if(treeSize - start > max)
   {
       return treeSize - start;
   }
   return max;
}
```
