### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {

   private int[][] container = null;

    private int count = 0;

    private int time = 0;

    public LFUCache(int capacity) {
        if (capacity > 0)
            container = new int[capacity][4];
        /*数组定义：
            [x][0]:key，
            [x][1]:value,
            [x][2]:引用和put次数
            [x][3]：最后操作的时间戳
        */
    }

    public int get(int key) {

        if (container != null)
            for (int i = 0; i < count; i++)
                if (container[i][0] == key) {
                    container[i][2]++;

                    container[i][3] = ++time;

                    return container[i][1];
                }

        return -1;
    }

    public void put(int key, int value) {

        boolean isComplete = false;
/*
1、先查找是否存在key，有直接进行修改
2、若无key且count小于容量，直接添加
3、容量已满，查找操作次数最少的集合
4、根据修改时间戳判断抛弃项
*/
        if (container != null) {
            for (int in = 0; in < count; in++)
                if (container[in][0] == key) {
                    container[in][1] = value;
                    container[in][2]++;
                    container[in][3] = ++time;

                    isComplete = true;
                }

            if (isComplete == false) {

                if (count < container.length) {
                    container[count][0] = key;
                    container[count][1] = value;
                    container[count][3] = ++time;

                    count++;
                } else {
                    int size = 0;
                    int[][] min = new int[container.length][3];
                    /*数组定义:
                     [x][0]:时间戳
                    [x][1]：操作次数
                    [x][2]：数组index
                    */
                    min[size][0] = container[0][3];
                    min[size][1] = container[0][2];
                    min[size][2] = 0;
                    for (int i = 1; i < container.length; i++) {
                        if (container[i][2] < min[0][1]) {
                            size = 0;
                            min[size][0] = container[i][3];
                            min[size][1] = container[i][2];
                            min[size][2] = i;
                        } else if (container[i][2] == min[0][1]) {
                            ++size;
                            min[size][0] = container[i][3];
                            min[size][1] = container[i][2];
                            min[size][2] = i;
                        }
                    }

                    int index = min[0][2];
                    if (size >= 1) {
                        int localTime = min[0][0];
                        for (int i = 1; i <= size; ++i) {
                            if (min[i][0] < localTime) {
                                index = min[i][2];
                                localTime = min[i][0];
                            }
                        }
                    }
                    container[index][0] = key;
                    container[index][1] = value;
                    container[index][2] = 0;
                    container[index][3] = ++time;

                }
            }
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```