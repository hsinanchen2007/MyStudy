8ms版本
```
public class Solution {
    public int longestOnes(int[] A, int K) {
        int i=0;//用来指向窗口起始位置
        int j=0;//用来指向当前遍历的位置
        int n=A.length;
        int m=0;//记录零的个数
        int ans = 0;
        while(j<n){
            //j为当前遍历的点
            while(j<n){
                if(A[j]==0){
                    m++;
                }
                if(m==K+1){
                    break;
                }//找到第K+1个零则跳出
                j++;
            }
            ans = Math.max(ans,j-i);//窗口大小为j-i
            while(i<n&&A[i]==1){
                i++;
            }//i此时指向窗口内第一个0
            i++;
            //i此时指向窗口内第一个值
            m--;
            //窗口内0的个数
            j++;
        }
        return ans;
    }
}
```

改用队列来实现，29ms
```
public class Solution {
    public int longestOnes(int[] A, int K) {
        int i=0,j=0;
        Queue<Integer> q = new ArrayDeque<>();
        int n = A.length;
        int ans = 0;
        while(j<n){
            while(j<n){
                if(A[j]==0){
                    q.add(j);
                }
                if(q.size()==K+1){
                    break;
                }
                j++;
            }
            ans = Math.max(ans,j-i);
            if(!q.isEmpty())
                i = q.poll()+1;
            j++;
        }
        return ans;
    }
}
```