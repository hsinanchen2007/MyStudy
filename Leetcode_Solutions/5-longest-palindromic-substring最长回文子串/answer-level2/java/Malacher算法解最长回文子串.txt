### 解题思路
主要是右边界的问题，复杂度为0(n),尽可能避免中心拓展

### 代码

```java
class Solution {
    public String longestPalindrome(String si) {
        String so = transform(si);
        int len = so.length();
        if(si.length()==0)return "".toString();
        int rightSide =0;
        int rightCenter =0;
        int center =0;
        int maxLength =0;
        int []halfLe=new int[len];
        for(int i=0;i<len;i++)
        {
            boolean sp = true;//判断是否需要中心拓展
            //在包围范围内
            if(rightSide>i)
            {
                //寻找左对称点
                int leftCenter = 2*rightCenter-i;
                //得到点i中心回文串长度
                halfLe[i]=halfLe[leftCenter];
                if(halfLe[i]>rightSide -i)
                {
                    halfLe[i]=rightSide -i;
                }
                if(halfLe[i]<rightSide-i)
                {
                    sp=false;
                }
            }
            if(sp){
                while(i-halfLe[i]-1>=0&&i+halfLe[i]+1<len)
                {
                    if(so.charAt(i-halfLe[i]-1)==so.charAt(i+halfLe[i]+1))
                        halfLe[i]++;
                    else
                        break;
                }
                rightCenter = i;
                rightSide = i+halfLe[i];
                if(halfLe[i]>maxLength)
                {
                    maxLength=halfLe[i];
                    center=i;
                }
            }//if
        }//for
        StringBuffer st = new StringBuffer();
        int temp = center-halfLe[center];
        if(so.charAt(temp)=='#') temp++;
        for(int i=temp;i<=center+halfLe[center];i+=2)
        {
            st.append(so.charAt(i));
        }
        return st.toString();
    }
    private String transform(String si)
    {
        StringBuffer sb = new StringBuffer();
        int N = si.length();
        for(int i=0;i<N;i++)
        {
            sb.append(si.charAt(i));
            sb.append('#');
        }
        return sb.toString();
    }
}
```