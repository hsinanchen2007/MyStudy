### 解题思路

注意数据的唯一性就好，这样写运行速度慢了些

### 代码

```java
class AnimalShelf {

    private LinkedList<int[]> setOfAnimalShelf;
    private final int[] emptyVal = {-1, -1};

    public AnimalShelf() {
        setOfAnimalShelf = new LinkedList<>();
    }
    
    public void enqueue(int[] animal) {
        if(setOfAnimalShelf.size() < 20000) {
            setOfAnimalShelf.add(animal);
        }
    }
    
    public int[] dequeueAny() {
        if(setOfAnimalShelf.isEmpty()) {
            return emptyVal;
        }
        return setOfAnimalShelf.pop();
    }
    
    public int[] dequeueDog() {
        for(int[] arr :setOfAnimalShelf) {
            if(arr[1] == 1) {
                setOfAnimalShelf.remove(arr);
                return arr;
            }
        }
        return emptyVal;
    }
    
    public int[] dequeueCat() {
        for(int[] arr :setOfAnimalShelf) {
            if(arr[1] == 0) {
                setOfAnimalShelf.remove(arr);
                return arr;
                
            }
        }
        return emptyVal;
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