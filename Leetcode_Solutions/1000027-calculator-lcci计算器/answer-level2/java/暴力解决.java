### 解题思路
把优先级高的*/先解决
然后高 强 度 循 环

### 代码

```java
class Solution {
    public int calculate(String s) 
    {
           
        int n = s.length();
        String c1[] = new String[n];
        for(int k =0;k<n;k++)
        {
            c1[k] = "";
        }
        int temp = 0;
        int i = 0;
        int count =0;
        
        for(int j= 0;i<n;i++)
        {
            if(s.charAt(i)==' ')
            {
                continue;
            }
            if(s.charAt(i)=='-')
            {
                j++;
                c1[j]+="-";
                j++;
                count+=2;
            }else if(s.charAt(i)=='+')
            {
                j++;
                c1[j]+="+";
                j++;
                count+=2;
            }else if (s.charAt(i)=='*')
            {
                j++;
                c1[j]+="*";
                j++;
                count+=2;
            }else if(s.charAt(i)=='/')
            {
                j++;
                c1[j]+="/";
                j++;
                count+=2;
            }else
            {
                c1[j]+=s.charAt(i);
            }
        }
      
        int flag =count;
        for(int k  = 0,h = 0;k<=count;k++,h++)
        {
            
            if(c1[k].equals("*"))
            {
                
                int a = Integer.parseInt(c1[h-1])*Integer.parseInt(c1[k+1]);
                c1[h-1] = "";
                c1[h-1]+=a;
                
                flag-=2;
                h--;
                k++;
            }else if(c1[k].equals("/"))
            {
                int a = Integer.parseInt(c1[h-1])/Integer.parseInt(c1[k+1]);
                c1[h-1] = "";
                c1[h-1]+=a;
                System.out.println(c1[h-1]);
                flag-=2;
                h--;
                k++;
            }else
            {
                c1[h] = c1[k];
            }
        }
       
        int tc = 0;

       if(flag<=0)
       {
           return Integer.parseInt(c1[0]);
       }
        for(int k  = 0;k<=flag;k++)
        {

            if(c1[k].equals("-"))
            {
                tc = tc-Integer.parseInt(c1[k+1]);
                k++;
            }else if(c1[k].equals("+"))
            {
                tc = tc+Integer.parseInt(c1[k+1]);
                k++;
            }else
            {
                tc+=Integer.parseInt(c1[k]);
            }

        }
       return tc;

    }
}

```