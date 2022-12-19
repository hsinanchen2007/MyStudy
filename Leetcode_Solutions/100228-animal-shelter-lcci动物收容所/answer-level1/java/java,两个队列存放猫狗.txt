使用两个队列存放猫狗，根据动物类别分别入队。

```java
class AnimalShelf {
    
    Queue<int[]> catQueue;
    Queue<int[]> dogQueue;
    int[] na ;
    
    public AnimalShelf() {
         catQueue = new LinkedList<>();
         dogQueue = new LinkedList<>();
         na = new int[]{-1,-1};
    }
    
    public void enqueue(int[] animal) {
        if(animal[1] == 0){
            catQueue.offer(animal);
        }else{
            dogQueue.offer(animal);
        }
    }
    
    public int[] dequeueAny() {
        if(catQueue.isEmpty() && dogQueue.isEmpty()){
            return na;
        }
        
        if(catQueue.isEmpty() || dogQueue.isEmpty()){
            return catQueue.isEmpty() ? dogQueue.poll() : catQueue.poll();
        }
        
        int[] cat = catQueue.peek();
        int[] dog = dogQueue.peek();
        return cat[0] < dog[0] ? catQueue.poll() : dogQueue.poll();
           
    }
    
    public int[] dequeueDog() {
        if(dogQueue.isEmpty()){
            return na;
        }
        return dogQueue.poll();
    }
    
    public int[] dequeueCat() {
     if(catQueue.isEmpty()){
            return na;
        }
        return catQueue.poll();
    }
}

