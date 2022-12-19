int a[20][20];
void f(int left,int right,int up,int down,int V)
{
    int i ,j ,k ,l;
    if(left<=right)       //注意递归的边界是left<=right   不要把if写成while造成死循环
    {
      for(i = left;i<=right;i++)
			a[up][i] = V++;
      for(j = up+1;j<=down;j++)
			a[j][right] = V++;
      for(k = right-1;k>=left;k--)
			a[down][k] = V++;
      for(l = down-1;l>up;l--)
			a[l][left] = V++;
      f(left+1,right-1,up+1,down-1,V);
    }

}
int main()
{
    int n,m,i,j;
    scanf_s("%d",&m);
    while(m--)
    {
        scanf_s("%d",&n);
        f(1,n,1,n,1);
        for(i = 1;i<=n;i++)
        {
            for(j = 1;j<n;j++)
            printf("%d\t",a[i][j]);
            printf("%d\n",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
