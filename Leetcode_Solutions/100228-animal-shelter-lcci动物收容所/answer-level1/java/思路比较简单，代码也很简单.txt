```
class AnimalShelf {

    private Queue<int[]> animalQueue = new LinkedList();
    private Queue<int[]> catQueue = new LinkedList();
    private Queue<int[]> dogQueue = new LinkedList();
    
    private static int[] notFound = new int[] {-1, -1};
    
    public AnimalShelf() {

    }
    
    public void enqueue(int[] animal) {
        animalQueue.offer(animal);
    }
    
    public int[] dequeueAny() {
        if (!catQueue.isEmpty()) {
            return catQueue.poll();
        }
        
        if (!dogQueue.isEmpty()) {
            return dogQueue.poll();
        }
        
        if (!animalQueue.isEmpty()) {
            return animalQueue.poll();
        }
        
        return notFound;
    }
    
    public int[] dequeueDog() {
        if (!dogQueue.isEmpty()) {
            return dogQueue.poll();
        }
        
        while(!animalQueue.isEmpty()) {
            int[] animal = animalQueue.poll();
            if (animal[1] == 0) {
                catQueue.offer(animal);
            } else {
                return animal;
            }
        }
        
        return notFound;
    }
    
    public int[] dequeueCat() {
        if (!catQueue.isEmpty()) {
            return catQueue.poll();
        }
        
        while(!animalQueue.isEmpty()) {
            int[] animal = animalQueue.poll();
            if (animal[1] == 1) {
                dogQueue.offer(animal);
            } else {
                return animal;
            }
        }
        
        return notFound;
        
    }
}
```
