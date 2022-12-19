### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        int size = 0;
        int maxSize = 0;
        int[] arr = new int[0];
        ArrayInfo arrayInfo = new ArrayInfo(arr, size, maxSize);
        arrayInfo = recurPrint(head, arrayInfo);
        return arrayInfo.getArr();
    }

    private static ArrayInfo recurPrint(ListNode node, ArrayInfo arrayInfo) {
        if (node == null) {
            return arrayInfo;
        }
        arrayInfo.setSize(arrayInfo.getSize() + 1);
        arrayInfo.setMaxSize(arrayInfo.getMaxSize() + 1);
        if (node.next != null) {
            arrayInfo = recurPrint(node.next, arrayInfo);
        } else {
            arrayInfo.setArr(new int[arrayInfo.getMaxSize()]);
            ;
        }

        arrayInfo.getArr()[arrayInfo.getMaxSize() - arrayInfo.getSize()] = node.val;
        arrayInfo.setSize(arrayInfo.getSize() - 1);
        return arrayInfo;
    }

        public static class ArrayInfo {

        private int[] arr;

        private int size;

        private int maxSize;

        public ArrayInfo(int[] arr, int size, int maxSize) {
            this.arr = arr;
            this.size = size;
            this.maxSize = maxSize;
        }

        public int[] getArr() {
            return arr;
        }

        public int getSize() {
            return size;
        }

        public int getMaxSize() {
            return maxSize;
        }

        public void setArr(int[] arr) {
            this.arr = arr;
        }

        public void setSize(int size) {
            this.size = size;
        }

        public void setMaxSize(int maxSize) {
            this.maxSize = maxSize;
        }
    }




}
```