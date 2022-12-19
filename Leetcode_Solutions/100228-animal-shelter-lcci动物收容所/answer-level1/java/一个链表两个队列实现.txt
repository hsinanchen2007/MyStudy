### 解题思路
物种使用list存储
猫和狗的编号使用队列存储
当不区分物种领养时，先判断kindList是否为空，不为空时
根据kindList拿到最早入园的动物种类并在相应的队列中出队拿到编号
当区分物种领养时，先判断对应的队列是否为空，不为空时，
将对应队列出队并删除kindList中最早出现的记录

### 代码

```java
class AnimalShelf {

    List<Integer> kindList;
    Queue<Integer> dogList;
    Queue<Integer> catList;
    public AnimalShelf() {
        kindList = new LinkedList<>();
        dogList = new LinkedList<>();
        catList = new LinkedList<>();
    }

    public void enqueue(int[] animal) {
        kindList.add(animal[1]);
        if(animal[1]==0){
            catList.add(animal[0]);
        }else{
            dogList.add(animal[0]);
        }
    }

    public int[] dequeueAny() {
        if(kindList.isEmpty()){
            return new int[]{-1,-1};
        }
        int[] res = new int[2];
        if(kindList.get(0)==1){
            res[1] = 1;
            res[0] = dogList.poll();
        }else{
            res[1] = 0;
            res[0] = catList.poll();
        }
        kindList.remove(0);
        return res;
    }

    public int[] dequeueDog() {
        if(dogList.isEmpty()){
            return new int[]{-1,-1};
        }
        int[] res = new int[2];
        res[0] = dogList.poll();
        res[1] = 1;
        for(int i=0;i<kindList.size();i++){
            if(kindList.get(i)==1){
                kindList.remove(i);
                break;
            }
        }
        return res;
    }

    public int[] dequeueCat() {
        if(catList.isEmpty()){
            return new int[]{-1,-1};
        }
        int[] res = new int[2];
        res[0] = catList.poll();
        res[1] = 0;
        for(int i=0;i<kindList.size();i++){
            if(kindList.get(i)==0){
                kindList.remove(i);
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