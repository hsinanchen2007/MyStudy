算法： 添加的数先存进ArrayList 然后当前数再当做key存进map， map的value存当前数在ArrayList中的index，find的时候对于每个ArrayList中的数计算是否存在component = value - list.(get) 然后从map中搜索key是否存在 再通过get(key)判断是否是数本身。

```
class TwoSum {

    HashMap<Integer,Integer> map;
    ArrayList<Integer> list;
    int index;
    
    public TwoSum() {
        this.map = new HashMap<>(); 
        this.list = new ArrayList<>();
        this.index = 0;
    }
    
    public void add(int number) {
        list.add(number);
        map.put(number,index);
        index++;
    }
    
    public boolean find(int value) {
        for(int i = 0; i < this.list.size(); i++){

            int component = value - list.get(i);

            if(map.containsKey(component)){
                if(map.get(component) != i) return true;
            }
        }
        
        return false;
    }
}


```
