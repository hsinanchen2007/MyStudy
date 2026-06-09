```
class Solution {
 public int reverse(int x){
        int max = 0x7fffffff, min = 0x80000000;
        if (x>max||x<min){
            return 0;
        }
        String str =null;
        int flag = 1;
        if (x>0){
            flag = 1;
        }
        else if (x==0){
            flag = 0;
        }else {
            flag = -1;
        }
        x = Math.abs(x);
        str = Integer.toString(x);
        char[] c = str.toCharArray();
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0;i<c.length;i++){
            stack.push(c[i]);
        }
        for (int i =0;i<c.length;i++){
            c[i] = stack.pop();
        }
        str = String.valueOf(c);
                try {
            return Integer.parseInt(str)*flag;
        }catch (Exception e){
            return 0;
        }
    }
}
```
