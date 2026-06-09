
```java
class AnimalShelf {

    private final static int[] NULL = {-1, -1};
    
    private LinkedList<int[]> list;
    
    public AnimalShelf() {
        list = new LinkedList<>();
    }

    public void enqueue(int[] animal) {
        list.add(animal);

    }

    public int[] dequeueAny() {
         if (list.isEmpty()) {
            return NULL;
        }
        return list.removeFirst();
    }

    // 1
    public int[] dequeueDog() {
        return getAnimal(1);
    }
    // 0
    public int[] dequeueCat() {
        return getAnimal(0);
    }

    private int[] getAnimal(int flag) {
        Iterator iterator = list.iterator();
        int[] res = NULL;
        while (iterator.hasNext()) {
            int[] temp = (int[]) iterator.next();
            if (temp[1] == flag) {
                res = temp;
                iterator.remove();
                break;
            }
        }
        return res;
    }
}

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf obj = new AnimalShelf();
 * obj.enqueue(animal);
 * int[] param_2 = obj.dequeueAny();
 * int[] param_3 = obj.dequeueDog();
 * int[] param_4 = obj.dequeueCat();
 */
```