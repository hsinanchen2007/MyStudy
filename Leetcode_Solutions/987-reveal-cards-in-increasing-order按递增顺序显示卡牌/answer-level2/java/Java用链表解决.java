### 解题思路
使用了链表。
先用了希尔排序，将原数组进行升序排序。

然后分析题目，发现可以视为约瑟夫为题，用链表解决了。

### 代码

```java
class Solution {
    class NodeList {
        int val;
        NodeList next;
        NodeList pre;

        NodeList(int a) {
            val = a;
        }
    }

    

    public int[] deckRevealedIncreasing(int[] deck) {
        shellSort(deck);
        int[] result = new int[deck.length];
        NodeList nodeList = new NodeList(0);
        nodeList.next = nodeList;
        nodeList.pre=nodeList;
        NodeList temp = nodeList;

        for (int x = 1; x < deck.length; x++) {
            NodeList teemp = new NodeList(x);
//            System.out.println(x);
            teemp.next = nodeList;
            teemp.pre=temp;
            nodeList.pre=teemp;
            temp.next = teemp;
            temp = temp.next;
        }
       /* System.out.println("检查链表");
        temp = nodeList;
        for (int x=0;x<14;x++){
            System.out.println(temp.val);
            temp=temp.next;
        }
        System.out.println("结束");*/
        temp = nodeList;
        int num = 0;
        int nn=0;
        while (temp.next != temp) {
            //System.out.println(temp.val);
            if (num%2==0){
                //System.out.println(temp.val);
//                System.out.println(nn);
                result[temp.val]=deck[nn];
                temp.pre.next=temp.next;
                temp.next.pre=temp.pre;
                nn++;
            }
            num++;
            /*System.out.println(temp.pre.val);
            System.out.println(temp.val);
            System.out.println(temp.pre.pre.val);
            System.out.println("======");*/
            temp=temp.next;
        }
        result[temp.val]=deck[nn];
        return result;

    }

    public void shellSort(int[] deck) {
        int n = deck.length / 2;

        while (n > 0) {
            for (int x = n; x < n * 2; x++) {
                for (int y = x; y < deck.length; y += n) {
                    int val = deck[y];
                    int index = y - n;

                    while (index >= 0 && deck[index] > val) {
                        deck[index + n] = deck[index];
                        index -= n;
                    }
                    deck[index + n] = val;

                }
            }
            n /= 2;
        }
    }
}
```