map+queue实现：                                        
`

    /*

    1.一个map（key,node），一个优先队列(node)实现。
        注：node包含：key，value，times：操作次数，clock：最后一次操作时间戳。

    2.两个条件影响是否淘汰,
        1) 使用的次数最少（放入 的那一次统一加上，以后重新放入覆盖，也要做++计算）
        2）使用次数相等时，比较最近一次get或put的时间戳，即最久没活跃的淘汰;

    具体细节：可以设置一个全局时钟，每次get或put操作都让时钟CLK++,并写入当前操作的key对应的node，
    可以理解为node打上时间戳;

    注：时间的流逝CLK++是线性的，不存在两个node.clock相等的情况；

    其中一个不得不注意的要点，node放进优先队列之后，改变它的值不会重新调整排序，
    也就是要将其拿出来再重新放入，使排序生效。
    */
class LFUCache {

    int CLK=0;
    int size;
    Map<Integer,Node> map;
    PriorityQueue<Node> q;
    public LFUCache(int capacity) {
        if(capacity>0){
        q=new PriorityQueue(capacity);
        map=new HashMap(capacity);
        size=capacity;
        }
        
    }
    
    public int get(int key) {
        
        if(size==0)return -1;
        
        if(map.containsKey(key)){
            Node node=map.get(key);
            
            
            node.times++;
            node.clock=++CLK;
            
            q.remove(node);
            q.offer(node);
            
            return node.value;
            
        }
        return -1;
        
    }
    
    public void put(int key, int value) {
         if(size==0)return ;

        if(map.containsKey(key)){

            Node node=map.get(key);
            node.times+=1;
            node.clock=++CLK;
            node.value=value;
            
            //-------------------------------------------------这里也要从新储存 优先队列；
            q.remove(node);
            q.offer(node);
            
            

        }else{
            if(map.size()==size){
                Node node_0=q.poll();
                

                map.remove(node_0.key);
            }
            Node node=new Node(1,++CLK,key,value);
            q.offer(node);
            map.put(key,node);
        }
    }
}

class Node implements Comparable<Node>{
    int times;
    int clock;//最后一次操作的时间戳
    int value;
    int key;
    
    public Node(int times, int clock,int key, int value) {
    this.times = times;
    this.clock = clock;
    this.value = value;
    this.key=key;
}
    
        @Override
    public int compareTo(Node o) {
        
        int sub=times-o.times;
         return sub==0?clock-o.clock:sub;
        
    }
}
`