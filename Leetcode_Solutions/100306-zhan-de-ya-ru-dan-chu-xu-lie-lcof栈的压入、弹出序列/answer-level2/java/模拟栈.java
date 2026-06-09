```
class Solution {
    public static boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> A=new Stack<>();
        int i=0,j=0;
        while(i<pushed.length){
            A.push(pushed[i]);
            i++;
            while(A.peek()==popped[j]){
                A.pop();
                j++;
                if(A.empty()) break;
            }
        }
        if(A.empty()) return true;
        return false;
    }
}
```
