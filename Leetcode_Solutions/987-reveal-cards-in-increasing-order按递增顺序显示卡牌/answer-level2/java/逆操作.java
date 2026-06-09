```
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        
        //1,6,2,10,3,7,4,9,5,8
        //2,10,3,7,4,9,5,8,6
        //3,7,4,9,5,8,6,10
        //4,9,5,8,6,10,7
        //5,8,6,10,7,9
        //6,10,7,9,8
        //7,9,8,10
        //8,10,9
        //9,10
        //10
        //先将数组排好序，每加入一个元素，先把队列最后一个元素弹出加入队首，再加入新值
        
        Arrays.sort(deck);
        int length = deck.length;
        if(length==1) return deck;
        
        LinkedList<Integer> queue = new LinkedList();
        queue.addLast(deck[length-1]);
        
        for(int i=length-2; i>=0; i--){
            int item = queue.removeLast();
            queue.addFirst(item);
            queue.addFirst(deck[i]);
        }
        int[] target = new int[length];
        for(int i=0; i<length; i++)
            target[i] = queue.get(i);
        return target;
    }
}
```
