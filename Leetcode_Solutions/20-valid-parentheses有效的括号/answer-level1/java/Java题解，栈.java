```
class Solution {
    public boolean isValid(String s) {
        HashMap<Character,Character> hashMap = new HashMap<Character,Character>();
        hashMap.put(')','(');
        hashMap.put('}','{');
        hashMap.put(']','[');
        Stack<Character> stack = new Stack<Character>();
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length;i++){
            if(hashMap.containsKey(chars[i])){
                char c = stack.isEmpty()?'#':stack.pop();
                if(c != hashMap.get(chars[i])){
                    return false;
                }
            }else{
                stack.push(chars[i]);
            }
        }
        return stack.size()==0;
    }
}
```
