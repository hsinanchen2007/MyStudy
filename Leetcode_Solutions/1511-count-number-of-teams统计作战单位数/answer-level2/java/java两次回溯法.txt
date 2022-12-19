### 解题思路
java两次回溯法，但似乎意义不大

### 代码

```java
class Solution {
    int ans = 0;
    public int numTeams(int[] rating) {
        if(rating==null || rating.length==0){
            return 0;
        }
        int len = rating.length;

        List<Integer> list = new ArrayList<>();
        int pre = Integer.MIN_VALUE;
        int preMin = Integer.MAX_VALUE;
        dfsAsc(len,rating,0, 0, pre, new LinkedList<Integer>(),true);
        dfsAsc(len,rating,0, 0, preMin, new LinkedList<Integer>(),false);
        return ans;
    }

    private void dfsAsc(int len, int[] rating, int start, int level, int pre, LinkedList<Integer> stack,boolean asc) {
        if(level == 3){
            ans++;
            return;
        }
        
        for(int i=start;i<len;i++){
            if(asc && rating[i]> pre){
               // stack.add(rating[i]);
                dfsAsc(len,rating,i+1, level+1, rating[i], stack,true);
                //stack.removeLast();
            }
            else if(!asc && rating[i]<pre){
                //stack.add(rating[i]);
                dfsAsc(len,rating,i+1, level+1, rating[i], stack,false);
                //stack.removeLast();
            }
        }
    }
}
```