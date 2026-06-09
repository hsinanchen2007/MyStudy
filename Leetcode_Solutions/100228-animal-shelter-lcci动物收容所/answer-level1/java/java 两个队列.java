**思路**
1. 首先新建一个类Animal用于表示动物，里头包含两个变量(id, enqueueTime)，其中id即动物编号，enqueueTime表示猫或狗加入的时间（从0开始递增）;
2. 然后新建两个队列catQueue和dogQueue,用于存放Animal实例;
3. 当执行**enqueue**的时候，取出动物的类别（猫或狗），然后新建一个Animal实例，插入到对应的队列中;
4. 当执行**dequeueDog**或**dequeueCat**的时候，比较简单，就是直接取出对应队列的头元素（最早插入到队列中的元素）;
5. 稍微有点复杂的是执行**dequeueAny**的时候，可以看成两个有序的队列，要取出最早插入的元素，只要比较两个队列的头元素中的enqueueTime即可，谁的enqueueTime越小，就说明它较早插入;
6. 除此之外，需要注意的是，需要对队列为空的情况进行单独的判断处理。

```java
class AnimalShelf {

        class Animal {
            int id;
            int enqueueTime;
            Animal(int id, int enqueueTime) {
                this.id = id;
                this.enqueueTime = enqueueTime;
            }
        }

        private LinkedList<Animal> dogQueue;
        private LinkedList<Animal> catQueue;
        private int enqueueTime;

        public AnimalShelf() {
            dogQueue = new LinkedList<>();
            catQueue = new LinkedList<>();
            enqueueTime = 0;
        }

        public void enqueue(int[] animal) {
            int type = animal[1];
            int id = animal[0];

            if (type == 0) {
                catQueue.offer(new Animal(id, enqueueTime));
            } else {
                dogQueue.offer(new Animal(id, enqueueTime));
            }

            enqueueTime++;
        }

        public int[] dequeueAny() {
            if (catQueue.isEmpty() && dogQueue.isEmpty()) {
                return new int[]{-1, -1};
            } else if (dogQueue.isEmpty()) {
                return new int[]{catQueue.poll().id, 0};
            } else if (catQueue.isEmpty()) {
                return new int[]{dogQueue.poll().id, 1};
            } else {
                Animal dog = dogQueue.getFirst();
                Animal cat = catQueue.getFirst();
                if (dog.enqueueTime < cat.enqueueTime) {
                    dogQueue.poll();
                    return new int[]{dog.id, 1};
                } else {
                    catQueue.poll();
                    return new int[]{cat.id, 0};
                }
            }
        }

        public int[] dequeueDog() {
            if (dogQueue.isEmpty()) {
                return new int[]{-1, -1};
            }

            return new int[]{dogQueue.poll().id, 1};
        }

        public int[] dequeueCat() {
            if (catQueue.isEmpty()) {
                return new int[]{-1, -1};
            }

            return new int[]{catQueue.poll().id, 0};
        }
    }
```