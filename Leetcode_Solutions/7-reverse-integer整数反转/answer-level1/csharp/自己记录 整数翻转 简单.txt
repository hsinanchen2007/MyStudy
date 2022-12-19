### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
        int z;
            if (x>0)
            {
                char[] a = x.ToString().ToArray();   // 将数字转为char[]
                Array.Reverse(a);                    // 翻转
                string rev= string.Join("",a);      // 把char[] 转回string
                int.TryParse(rev,out z);            //转成32位int
                return z;
            }
            else
            {
                char[] a = (-x).ToString().ToArray();
                Array.Reverse(a);
                string rev= string.Join("",a);
                int.TryParse(rev,out z);
                return -z;
            }
    }
}
```


数学方法
### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
       int max=int.MaxValue;
        int min= int.MinValue;
        int rev = 0 ;
        while(x!=0)
        {
            int pop=x%10;
            x/=10;
            if (rev>max/10||(rev==max/10 && pop>7)) return 0;
            if (rev<min/10||rev==min/10 && pop<-8) return 0;
            rev=10*rev+pop;
          
        }
          return rev;
    }
}