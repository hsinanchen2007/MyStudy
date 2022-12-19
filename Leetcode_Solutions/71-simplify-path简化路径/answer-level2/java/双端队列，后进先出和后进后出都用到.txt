### 解题思路
用双端队列解决问题，每次先while循环过滤/////斜杠，然后判断字符串，送进队列里面
送进队列的时候对字符串进行判定，..的话就突出前一个，.就放弃该字符串。

### 代码

```java
class Solution{
    public String simplifyPath(String path) {
        Stack<String> st=new Stack<>();
        Deque que=new LinkedList();
        StringBuffer sb=new StringBuffer();
        for (int i=1;i<path.length();i++)
        {
//            if (path.charAt(i)=='/')
//            {
//                if (path.charAt(i-1)=='/')
//                {
//                    continue;
//                }
//                else
//                {
//                    while(path.charAt(i)!='/' )
//                    sb.append(path.charAt(i));
//                }
//            }
            while (i<path.length() && path.charAt(i)=='/' )
            {
                i++;
            }
            while(i<path.length()&& path.charAt(i)!='/')
            {
                sb.append(path.charAt(i));
                i++;
            }
            if (sb.length()==0)
                continue;
            String temp=sb.toString();

            if (temp.equals(".."))
            {
                if (!que.isEmpty())
                {
                    que.removeLast();
                    sb.setLength(0);
                    continue;
                }
                else
                {
                    sb.setLength(0);
                    continue;
                }
            }
            if (temp.equals("."))
            {
                sb.setLength(0);
                continue;
            }
            que.add(sb.toString());
            sb.setLength(0);
        }
        StringBuffer res_sb=new StringBuffer();
        if (que.isEmpty())
            return "/";
        while(!que.isEmpty())
        {
            res_sb.append("/");
            res_sb.append(que.removeFirst());
//            sb.append()
        }
        return res_sb.toString();
    }
}

```