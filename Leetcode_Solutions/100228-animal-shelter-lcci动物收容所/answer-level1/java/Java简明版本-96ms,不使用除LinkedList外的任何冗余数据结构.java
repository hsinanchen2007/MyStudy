思路非常简单,两个队列queue1,queue2分别保存猫和狗。
enqueue(int[] animal)就是分别让animal[1]=0的进queue1，animal[1]=1的进queue2。
dequeueAny():显然若queue1，queue2均为空，则直接返回{-1,-1};若其中有一个为空，则返回另一个的头部;若均不为空则分别取出头部比较序号即可。
dequeueDog()：queue2为空则返回{-1,-1};否则返回头部。
dequeueCat()：同上道理。 
```
class AnimalShelf 
{
    Queue<int[]> queue1;//for cats
    Queue<int[]> queue2;//for dogs
    public AnimalShelf() 
    {
        queue1=new LinkedList<>();
        queue2=new LinkedList<>();
    }
    
    public void enqueue(int[] animal) 
    {
        if(animal[1]==0)queue1.offer(animal);
        else queue2.offer(animal);
    }
    
    public int[] dequeueAny() 
    {
        if(queue1.isEmpty()&&queue2.isEmpty())return new int[]{-1,-1};
        if(queue1.isEmpty()||queue2.isEmpty())
        {
            return queue1.isEmpty()?queue2.poll():queue1.poll();
        }
        int[] temp1=queue1.peek();
        int[] temp2=queue2.peek();
        if(temp1[0]<temp2[0])return queue1.poll();
        else return queue2.poll();
    }
    
    public int[] dequeueDog() 
    {
        if(queue2.isEmpty())return new int[]{-1,-1};
        return queue2.poll();
    }
    
    public int[] dequeueCat() 
    {
        if(queue1.isEmpty())return new int[]{-1,-1};
        return queue1.poll();
    }
}

```
