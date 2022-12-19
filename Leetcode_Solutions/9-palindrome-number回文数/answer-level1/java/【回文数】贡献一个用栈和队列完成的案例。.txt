import java.util.Stack;
import java.util.LinkedList;
class Solution {
    public boolean isPalindrome(int x) {
        if (x<0 || (x>0&&x%10==0)) return false;
        Stack stack = new Stack();
        Queue queue = new LinkedList();
        x = Math.abs(x);
        while(x!=0){
            stack.push(x%10);
            queue.add(x%10);
            x /= 10;
        }
        while(!stack.isEmpty()){
            if (stack.pop() != queue.remove())
                return false;
        }

        return true;
    }
}