### 解题思路
java全排列和判断2的幂

### 代码

```java
import java.util.LinkedList;
class Solution {
   
    public boolean reorderedPowerOf2(int N) {

        if(N<=10) {
            return judy(N);
        }
        List<String> result = new ArrayList<>();
        int n = N;
        while(n>0){
            int t = n%10;
            result.add(t+"");
            n = n/10;
        }
        LinkedList<String> stack = new LinkedList<>();
        boolean[] used = new boolean[result.size()];
        return dfs(result,stack,used);

    }

    boolean dfs(List<String>res, LinkedList<String> stack, boolean[] used){
        if(res.size() == stack.size()){

            StringBuilder sb = new StringBuilder();
            stack.forEach(sb::append);
            String current = sb.toString();
            //System.out.println("ok... " +sb.toString());
            if(!current.startsWith("0")){
                int c = Integer.parseInt(current);
                if(judy(c)){
                    return true;
                }
            }
        }
        for(int i=0;i<res.size();i++){
            if(!used[i]){
                stack.add(res.get(i));
                used[i] = true;
                if(dfs(res,stack,used)){
                    return true;
                }
                used[i] = false;
                stack.removeLast();
            }
        }
        return false;
    }

    boolean judy(int n){
        while(n%2==0){
            n = n/2;
        }
        return n==1;
    }
}
```