
```

class LFUCache {
    int capacity;
    int minfre;
    int cur;
    HashMap<Integer,doubleList> fre;
    HashMap<Integer,Node> map1;
    public LFUCache(int capacity) {
        this.capacity=capacity;
        fre = new HashMap<>();
        map1 = new HashMap<>();
        this.cur=0;

    }
    public int get(int key) {
        if(capacity==0) return-1;
        if(cur==0) return -1;
        if(map1.containsKey(key)){
            //System.out.println("-----1");
            Node node=map1.get(key);
            doubleList list = fre.get(node.fre);
            //System.out.println("-----2");
            if(list.size==1){
                fre.remove(node.fre);
                if(minfre==node.fre) minfre++;
                node.fre++;
                if(fre.containsKey(node.fre)){
                  //  System.out.println("-----3.1");
                    doubleList list1 = fre.get(node.fre);
                  //  System.out.println("---111");
                    list1.add(node);
                  //  System.out.println("---123");
                }
                else{
                 //   System.out.println("---4");
                    doubleList list2 =new doubleList();
                    list2.add(node);
                    fre.put(node.fre,list2);
                }
              //  System.out.println("---4.1");
            }
            else{
              //  System.out.println("----5");
                node.fre++;
                list.remove(node);
               
                if(fre.containsKey(node.fre)){
              //      System.out.println("3.1");
                    doubleList list1 = fre.get(node.fre);
                //    System.out.println("111");
                    list1.add(node);
                  //  System.out.println("123");
                }
                else{
                 //   System.out.println("4");
                    doubleList list2 =new doubleList();
                    list2.add(node);
                    fre.put(node.fre,list2);
                }
            }

            return node.val;
        }
        else return -1;

    }
    
    public void put(int key, int value) {
      //  System.out.println(key);
        if(capacity==0) return;
        if(map1.containsKey(key)){
           
            Node node=map1.get(key);
            node.val=value;
            get(key);
        }
        else{
         //   System.out.println(key);
            if(cur==capacity){
                doubleList list = fre.get(minfre);
                int thekey=list.first.next.key;
                if(list.size==1){
                    fre.remove(minfre);
                    list=null;
                }
                else{
                    list.removeFirst();
                }
                map1.remove(thekey);
                cur--;
            }
         //   System.out.println(key);
            Node node = new Node(key,value);
            map1.put(key,node);
           // System.out.println(key);
            if(fre.containsKey(1)){
              //  System.out.println(key);
                doubleList list = fre.get(1);
                list.add(node);
            
            }
            else{
            //    System.out.println(key+"%");
                doubleList list = new doubleList();
                list.add(node);
                fre.put(1,list);
                
            }
        cur++;
        minfre=1;
        }
        
        
    }
}
class Node{

    int fre;
    int val;
    int key;
    Node pre;
    Node next;
    public Node(int key,int value){
        this.fre=1;
        this.val=value;
        this.key=key;
    }
    public Node(){
        val=11;
    }
}
class doubleList{
    int size;
    Node first;
    Node last;
    public doubleList(){
        size=0;
        first=new Node();
        last=new Node();
        last.pre=first;
        first.next=last;

    }
    public void add(Node node){
        node.pre=last.pre;
        last.pre.next=node;
        node.next=last;
        last.pre=node;
        size++;
    }
    public void removeFirst(){
        first.next.next.pre=first;
        first.next=first.next.next;
        size--;
    }
    public void remove(Node node){
        node.pre.next=node.next;
        node.next.pre=node.pre;
        size--;
        node=null;
    }
}


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```
