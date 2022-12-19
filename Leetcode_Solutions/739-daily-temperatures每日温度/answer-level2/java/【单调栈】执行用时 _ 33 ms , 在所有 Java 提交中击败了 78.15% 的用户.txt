### 解题思路
单调栈

### 代码

```java
class Solution {
    
    public static class Node{
        int index;
        int val;
        public Node(int index,int val){
            this.index=index;
            this.val=val;
        }
    }
    
    public int[] dailyTemperatures(int[] arr) {
        int len=arr.length;
        if(len==1){
            return new int[]{0};
        }
        LinkedList<Node>st=new LinkedList<Node>();
        int[]res=new int[len];

        for(int i=0;i<len;++i){
            Node tmps=new Node(i,arr[i]);
            if(st.isEmpty()||st.getLast().val>=tmps.val){
                st.add(tmps);
            }else{
                    while(!st.isEmpty()&&tmps.val>st.getLast().val){
                            Node n=st.removeLast();
                            res[n.index]=i-n.index;
                    }
                    st.add(tmps);
            }
        }
        while(!st.isEmpty()){
            Node p=st.removeLast();
            res[p.index]=0;
        }
        return res;




    }
}
```