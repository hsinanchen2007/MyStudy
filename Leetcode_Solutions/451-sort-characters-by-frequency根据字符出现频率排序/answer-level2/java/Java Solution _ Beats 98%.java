先用长度为128的数组统计各个字符的数量，再用优先队列排序
```
class Solution {
    class Node{
        int val;
        int num;
        Node(int v,int n){
            this.val=v;
            this.num=n;
        }
    }
    public String frequencySort(String s) {
        if(s.length()==0)
            return "";
        int[] arr=new int[128];
        for(char t:s.toCharArray())
            arr[t]++;
        PriorityQueue<Node> pq=new PriorityQueue(new Comparator<Node>(){
            public int compare(Node n1,Node n2){
                return n2.num-n1.num;
            }
        });
        for(int i=0;i<128;i++)
            if(arr[i]!=0)
                pq.add(new Node(i,arr[i]));
        StringBuilder sb=new StringBuilder();
        while(!pq.isEmpty()){
            Node t=pq.poll();
            for(int i=0;i<t.num;i++)
                sb.append((char)t.val);
        }
        return sb.toString();
    }
}
```
