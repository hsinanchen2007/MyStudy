### 解题思路
运用递归：生成所有情况，然后再去删选出对的
    生成的每一个情况：第1个+（n+1）个
### 代码

```java
class Solution {
    /*
    *运用递归：生成所有情况，然后再去删选出对的
    *生成的每一个情况：第1个+（n+1）个
    **/
    public List<String> generateParenthesis(int n) {
        List<String> list=new ArrayList<String>();
        selectAll(new char[2*n],0,list);
        return list;
    }
    public void selectAll(char[] current,int pos,List<String> list)
    {
        if(pos==current.length)
        {
            if(valid(current))
            {
                list.add(new String(current));
            }
        }
        else{
            //第一种情况：
            //第0个有了
            current[pos]='(';
            //第1个的位子可能是1或者0
            selectAll(current,pos+1,list);
            //或者，第二种情况
            //第0个有了
            current[pos]=')';
            //第1个的位子可能是1或者0
            selectAll(current,pos+1,list);
        }
    }
    public boolean valid(char[]  current)
    {
        int balance=0;
        for(int i=0;i<current.length;i++)
        {
            if(current[i]=='(')
            {
                balance++;
            }
            else{
                balance--;
                if(balance<0)
                {
                    return false;
                }
            }
        }
        return balance==0;
    }
}
```