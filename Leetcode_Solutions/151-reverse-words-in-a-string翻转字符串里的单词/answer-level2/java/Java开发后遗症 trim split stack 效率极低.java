```
class Solution {
    public String reverseWords(String s) {
        Stack stack = new Stack<String>();
        String[] strs = s.split("\\s+");
        if(strs.length==0) return "";
        int count = 0;
        for(int i=0;i<strs.length;i++)
        {
            if(strs[i].equals(" ")||strs[i]==null) break;
            stack.push(strs[i]);
            count++;
        }
        String result = "";
        result+=stack.pop();
        for(int i=0;i<count-1;i++)
        {
            result+=" ";
            result+=stack.pop();
        }
        
        return result.trim();
    }
}
```
