 private int []a= new int[100000];#存放key value的数组，key就是数组下标，value就是数组的值
 private int []b=new int[100000];#标记数组，用来指示该key是否被占用。数组值=1表示被占用，其他表不被占用


 public void put(int key, int value) {    
      a[key]=value;#存放键值对
      b[key]=1;#标记该key被占用
    
}
public int get(int key) {
        if(b[key]!=1){
            return -1;
        }else{
            return a[key];
        }
    }
 public void remove(int key) {
        b[key]=0;#移除，只需要标记该key未被占用。
    }