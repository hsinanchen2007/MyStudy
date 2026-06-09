执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.3 MB, 在所有 Java 提交中击败了88.49%的用户

```
public String getPermutation(int n, int k) {

        boolean[] flag=new boolean[n];
        StringBuilder stringBuilder=new StringBuilder();
        int up=0,down=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<flag.length;j++)
            {
                if(flag[j])
                    continue;
                up=down+1;
                down=up+factorial(n-1-i)-1;
                if(up<=k && k<=down)
                {
                    stringBuilder.append(String.valueOf(j+1));
                    flag[j]=true;
                    break;
                }
            }
            down=up-1;
        }
        return stringBuilder.toString();
    }

    public static int factorial(int n)
    {
        int r=1;
        for(int i=1;i<=n;i++)
            r*=i;
        return r;
    }
```