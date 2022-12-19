题目说的有点绕，我们可以这样理解：  
对于A中的每个字符串，它们都是某个图的点，这个图的顶点个数就是A数组的长度。   
那么如何判断图中的顶点是否相连呢？题目中给出了判定两个字符串是否相似的方法：  
即如果交换两个字符后，它们相同，可判定为相似，也就是图中的顶点连通。  
判定相似的方法如下：  
```
public boolean Similar(String a,String b) {
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();
        int count = 0;
        for(int i = 0; i < ca.length; i ++) {
            if(ca[i] != cb[i]) {
                count++;
            }
        }
        if(count == 2 || count == 0) return true;
        return false;
    }
```  
于是我们得到了一个图，问题是求有多少组是相似的，也就是有多少组是连通的。  
图的极大连通子图称为连通分量，此题也就是求图的连通分量个数。
求图的连通分量个数可以采用BFS和DFS，当然采用并查集的方法也是好的。  
这里贴出BFS和并查集的方法，仅供参考：  
```
class Solution {
    public int numSimilarGroups(String[] A) {
           /*
           采用队列，广度优先算法，等到队列为空的时候一组就结束了。
           所以我们一般采用mark数组标记此元素是否已经访问过了。
           */
        int n = A.length;
        if(n <= 1) return n;
        int ans = 0;
        boolean[] mark = new boolean[n];  //初始化为false，代表没有访问过
        for(int i = 0; i < n; i ++) {
            if(mark[i] == false) {
                ans ++;
                InsertIntoGroups(A,i,mark);
            }
        }
        return ans;
    }
    /****************************************************************/
    public void InsertIntoGroups(String[] A,int root,boolean[] mark) {
        Queue<String> q = new LinkedList<>();
        mark[root] = true;
        q.add(A[root]);
        while(!q.isEmpty()) {
            String tmp = q.remove();
            for(int i = 0; i < A.length; i ++) {
                if(mark[i] == false && Similar(tmp,A[i])) {
                    mark[i] = true;
                    q.add(A[i]);
                }
            }
        }
    }
    /********************************************************************/
    public boolean Similar(String a,String b) {
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();
        int count = 0;
        for(int i = 0; i < ca.length; i ++) {
            if(ca[i] != cb[i]) {
                count++;
            }
        }
        if(count == 2 || count == 0) return true;
        return false;
    }
}  
  
``` 
```
public int numSimilarGroups(String[] A) {
         /*并查集方法*/
        int n = A.length;
        if(n <= 1) return n;
        int[] mark = new int[n];
        int count = 0;
        for(int i = 0; i < n; i ++) {
            mark[i] = -1;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0;j < i; j ++) {
                int x = find(mark,i);
                int y = find(mark,j);
                if( x != y && Similar(A[i],A[j])) {
                    mark[x] = y;
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            if(mark[i] == -1) {
                count++;
            }
        }
        return count;
}
public int find(int[] mark,int x){
        if(mark[x] == -1) {
            return x;
        } else {
            mark[x] = find(mark,mark[x]);
            return mark[x];
        }
        //return x == mark[x] ? x : mark[x] = find(mark[x]);    
}
public boolean Similar(String a,String b) {
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();
        int count = 0;
        for(int i = 0; i < ca.length; i ++) {
            if(ca[i] != cb[i]) {
                count++;
            }
        }
        if(count == 2 || count == 0) return true;
        return false;
    }
```
