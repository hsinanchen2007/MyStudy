class Solution {
    public int balancedStringSplit(String s)
    {   int nums=0;
        Stack <Character>stack = new Stack();
        for(int i=0;i<s.length();i++)
        {   
            char x =s.charAt(i);
            if(stack.isEmpty())
            {
                nums++;
                stack.push(x);
                continue;
            }
            if (x==stack.peek())
            {
                stack.push(x);
            }
            else
            {
                stack.pop();
            }
        }
     return nums;
    }
}
遍历字符串，栈空则数量加一，否则判断栈顶元素是否与当前元素相同，相同入栈，不同出栈。