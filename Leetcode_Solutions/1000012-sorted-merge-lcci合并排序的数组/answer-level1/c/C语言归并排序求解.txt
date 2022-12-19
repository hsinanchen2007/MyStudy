![微信图片_20200303180834.png](https://pic.leetcode-cn.com/a4d3d7b80b6bf4b719e01318d026db862657c99429f45f29811c14e88910856c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200303180834.png)


void merge(int* A, int ASize, int m, int* B, int BSize, int n){
   int s[ASize];
   int a = 0;
   int b = 0;
   int i = 0;

   while(a<m && b<n)
   {
       if(A[a]<=B[b])
       {
           s[i] = A[a];
           a++;
       }
       else
       {
           s[i] = B[b];
           b++;
       }`内联代码`
       i++;
   }
  
     while(a<m)
    {
        s[i] = A[a];
        a++;
        i++;
    }
    while(b<n)
    {
        s[i] = B[b];
        b++;
        i++;
    }
    for(int j = 0; j < m+n; j++)
    {
        A[j] = s[j];
    }
}