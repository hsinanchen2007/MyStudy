```
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] inDegrees = new int[numCourses];
        for(int[] p : prerequisites){
            inDegrees[p[0]]++;
        }
        LinkedList<Integer> queue = new LinkedList<Integer>();
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i] == 0){
                queue.addLast(i);
            }
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        while(!queue.isEmpty()){
            int num = queue.removeFirst();
            list.add(num);
            for(int[] p : prerequisites){
                if(p[1] == num){
                    inDegrees[p[0]]--;
                    if(inDegrees[p[0]] == 0)
                        queue.addLast(p[0]);
                }
            }
        }
        
        int[] ret = new int[numCourses];
        if(list.size() == numCourses){
            for(int i=0;i<numCourses;i++){
                ret[i] = list.get(i);
            }
            return ret;
        }else{
            return new int[0];
        }
        
    }
}
```
