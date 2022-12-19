### 解题思路
是用List
由于不能边查边删，push_back的复杂度更像是"O(2)"

### 代码

```java
class MaxQueue {
    List<Integer> queueList;
    List<Integer> maxQueueList;
    int maxNum;

    public MaxQueue() {
        queueList = new ArrayList<>();
        maxQueueList = new ArrayList<>();
        maxNum = -1;
    }

    public int max_value() {
        return maxNum;
    }

    public void push_back(int value) {
        queueList.add(value);
        if(maxNum < value){
            maxNum = value;
        }
        int count = 0;
        if(!maxQueueList.isEmpty()){
            for(int i = maxQueueList.size()-1; i > -1; i--){
                if(value > maxQueueList.get(i)){
                    count++;
                }else {
                    break;
                }
            }
            for (int i = 0; i < count; i++){
                maxQueueList.remove(maxQueueList.size()-1);
            }
        }
        maxQueueList.add(value);
    }

    public int pop_front() {
        if(queueList.isEmpty()){
            return -1;
        }
        int value = queueList.get(0);
        queueList.remove(0);
        if(value == maxNum) {
            maxQueueList.remove(0);
            if(maxQueueList.isEmpty()){
                maxNum = -1;
            }else {
                maxNum = maxQueueList.get(0);
            }
        }

        return value;
    }
}
```