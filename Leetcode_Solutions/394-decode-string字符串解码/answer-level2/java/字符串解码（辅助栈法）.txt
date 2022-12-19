### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String decodeString(String s) {
        StringBuilder res=new StringBuilder();
        int multi=0;
        //定义一个链栈，储存数字
        LinkedList<Integer> stack_multi=new LinkedList<>();  
        //定义一个链栈，储存字符串
        LinkedList<String> stack_res=new LinkedList<>();

        for(Character c:s.toCharArray())
        {
            if(c=='[')
            {
                stack_multi.addLast(multi);
                stack_res.addLast(res.toString());
                //重新置0
                multi=0;
                res=new StringBuilder();
            }
            else if(c==']')
            {
                StringBuilder tmp=new StringBuilder();
                int cur_multi=stack_multi.removeLast();
                for(int i=0;i<cur_multi;i++)
                    tmp.append(res);
                res=new StringBuilder(stack_res.removeLast()+tmp);
            }
            else if(c>='0'&&c<='9')
                multi=multi*10+Integer.parseInt(c+""); //将字符转为字符串后变为整形,并处理进位
            else
                res.append(c);  //增加函数
        }
        return res.toString();
    }
}
```