### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String decodeString(String s) {
int multi = 0;
StringBuilder res =new StringBuilder();
LinkedList<Integer> stack_multi=new LinkedList<>();
LinkedList <String> stack_res=new LinkedList<>();
for(Character c:s.toCharArray())
{
    if(c=='[')
    {

stack_multi.addLast(multi);
stack_res.addLast(res.toString());
multi=0;

 res = new StringBuilder();

    }
   else if(c==']')
    {
int cruit_multi=stack_multi.removeLast();
StringBuilder temp=new StringBuilder();
for(int i=0;i<cruit_multi;i++)
temp.append(res);
    res=new StringBuilder(stack_res.removeLast()+temp);


}
    else if(c >= '0' && c <= '9')
    {
        multi =multi * 10+Integer.parseInt(c+"" );
    }
    else res.append(c);
} return res.toString();
    }
}
```