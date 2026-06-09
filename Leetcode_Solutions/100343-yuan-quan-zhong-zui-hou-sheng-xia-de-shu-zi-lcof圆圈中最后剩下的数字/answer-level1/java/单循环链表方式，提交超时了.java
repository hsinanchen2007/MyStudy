直接上代码：

```java
class Solution {
    public DataNode head = new DataNode(-1);

    public int lastRemaining(int n, int m) {
        //生成一个长度为n，首尾相连的队列
        addData(n);
        DataNode helper = head; // 定义一个指针指向head的前一个节点
        while(helper.next != head){
            helper = helper.next;
        }

        while(helper != head){
            for(int i=0;i< m-1;i++){
                //head和helper移动到第m个位置
                head = head.next;
                helper = helper.next;
            }
            //当前head指向m元素出队列
            head = head.next; // head先指向在一个节点，下一次的起点
            helper.next = head; //helper指向head的下一个节点，head出队列
        }
        return head.data; //剩下的就是最后一个数字

    }

    public void addData(int nums){
        DataNode cur = null;
        for(int i = 0;i< nums ; i++){
            DataNode data = new DataNode(i);
            if(i == 0){
                // 当只有一个数字时，构造一个在一个节点是自己的队列
                head = data;
                cur = head;
                head.next = head;
            }else{
                data.next = head;
                cur.next = data;
                cur = cur.next;
          }
        }
    }
}

class DataNode{
    public int data;
    public DataNode next;

    public DataNode(int data){
        this.data = data;
    }
}


```
