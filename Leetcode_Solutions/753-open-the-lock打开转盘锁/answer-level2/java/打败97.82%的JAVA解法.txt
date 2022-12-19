### 解题思路
执行用时 :9 ms, 在所有 Java 提交中击败了97.82% 的用户
内存消耗 :41.1 MB, 在所有 Java 提交中击败了62.44%的用户

思想就是双端BFS，用java实现了一下，执行速度果然很快

### 代码

```java
class Solution {
    public int openLock(String[] deadends, String target) {
        if (target.equals("0000")){
            return 0;
        }
        int startArray[] = new int[10000];
        int endArray[] = new int[10000];
        // 将字符串转成数字
        for (int i = 0; i < deadends.length; i++){
            int dead = Integer.valueOf(deadends[i]);
            if (dead == 0){
                return -1;
            }
            startArray[dead] = -1;
            endArray[dead] = -1;
        }
        Queue<Integer> startQueue = new LinkedList<>();
        Queue<Integer> endQueue = new LinkedList<>();
        int targetKey = Integer.valueOf(target);
        startQueue.add(0);
        endQueue.add(targetKey);
        startArray[0] = 1;
        endArray[targetKey] = 1;
        while (!startQueue.isEmpty() || !endQueue.isEmpty()){
            int bfs = bfs(startQueue, startArray, endArray);
            if (bfs != -1){
                return bfs;
            }
            bfs = bfs(endQueue,endArray,startArray);
            if (bfs != -1){
                return bfs;
            }
        }
        return -1;
    }

    private int bfs(Queue<Integer> queue,int[] array, int[] valueArray) {
        if (!queue.isEmpty()) {
            int num = queue.poll();
            if (array[num] == -1) {
                return -1;
            }
            if (array[num] != 0 && array[num] != -1 && valueArray[num]!=0 && valueArray[num] != -1) {
                return array[num] + valueArray[num] - 2;
            }
            addKey(num, queue, array);
        }
        return -1;
    }

    private void addKey(int key, Queue<Integer> keyQueue,int[] alreadyArray){
        int thousand = key / 1000;
        int hundred = key % 1000 / 100;
        int ten = key % 100 / 10;
        int digits = key % 10;
        // 操作密码
        int thousand1 =  add(thousand);
        int thousand2 = subtraction(thousand);
        int hundred1 = add(hundred);
        int hundred2 = subtraction(hundred);
        int ten1 = add(ten);
        int ten2 = subtraction(ten);
        int digits1 = add(digits);
        int digits2 = subtraction(digits);
        int value = thousand * 1000 + hundred * 100 + ten * 10 + digits;
        if (thousand1 != -1){
            judgeRepeat(thousand1, hundred, ten, digits, value, keyQueue, alreadyArray);
        }

        if (thousand2 != -1){
            judgeRepeat(thousand2,hundred,ten,digits,value,keyQueue,alreadyArray);
        }

        if (hundred1 != -1){
            judgeRepeat(thousand,hundred1,ten,digits,value,keyQueue,alreadyArray);
        }

        if (hundred2 != -1){
            judgeRepeat(thousand,hundred2,ten,digits,value,keyQueue,alreadyArray);
        }

        if (ten1 != -1){
           judgeRepeat(thousand,hundred,ten1,digits,value,keyQueue,alreadyArray);
        }

        if (ten2 != -1){
            judgeRepeat(thousand,hundred,ten2,digits,value,keyQueue,alreadyArray);
        }

        if (digits1 != -1){
            judgeRepeat(thousand, hundred, ten, digits1, value, keyQueue, alreadyArray);
        }

        if (digits2 != -1){
            judgeRepeat(thousand,hundred,ten,digits2,value,keyQueue,alreadyArray);
        }
    }


    private void judgeRepeat(int thousand, int hundred, int ten,
                                int digits, int value,
                                Queue<Integer> keyQueue, int[]alreadyArray){

        int num = thousand * 1000 + hundred * 100 + ten * 10 + digits;
        if (alreadyArray[num] == 0){
            alreadyArray[num] = alreadyArray[value] + 1;
            keyQueue.add(num);
        }
    }

    private int add(int num){
        int high = num + 1;
        if (high == 10){
            high = 0;
        }
        return high;
    }

    private int subtraction(int num){
        int low = num - 1;
        if (low == -1){
            low = 9;
        }
        return low;
    }
}
```