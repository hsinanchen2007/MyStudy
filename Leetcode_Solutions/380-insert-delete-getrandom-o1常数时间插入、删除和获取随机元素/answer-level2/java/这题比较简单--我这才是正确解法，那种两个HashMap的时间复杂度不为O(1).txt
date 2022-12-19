```
HashMap<Integer,Integer> map=new HashMap<>();
    LinkedList<Integer> list=new LinkedList<>();
 int size;
    /** Initialize your data structure here. */
    public RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(map.containsValue(val)){
            return false;
        }
        map.put(val,val);
        list.add(val);
size++;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(map.containsValue(val)){

            map.remove(val);
            list.remove((Integer)val);
            size--;
            return true;
        }

        return false;

    }

    /** Get a random element from the set. */
    public int getRandom() {


        Random random=new Random();
        if(size>0) {
            int fanhui = -1;
            fanhui = random.nextInt(size);
            System.out.println(list.get(fanhui));
            return list.get(fanhui);
        }
        return -1;


    }
```
