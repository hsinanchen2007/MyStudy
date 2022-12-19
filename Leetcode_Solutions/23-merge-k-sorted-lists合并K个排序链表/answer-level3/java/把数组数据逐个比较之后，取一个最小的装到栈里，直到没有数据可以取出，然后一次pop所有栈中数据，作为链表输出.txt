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
    public ListNode mergeKLists(ListNode[] lists) {

        /** build stack */
        Stack stack = new Stack();

        /** get the smallest into stack */
        boolean runFlag = true;

        /** remove null from  lists */
        List<ListNode> listsArray = removeNullList(lists);

        while (listsArray.size() > 0){

            Integer valueNum = 0;
            int tempMin = listsArray.get(0).val;

            for(int i = 0; i < listsArray.size(); i++){
                ListNode tempList = listsArray.get(i);
                if(tempMin > tempList.val){
                    tempMin = tempList.val;
                    valueNum = i;
                }
            }

            ListNode tempUpdateList = listsArray.get(valueNum);
            tempUpdateList = updateListNode(tempUpdateList);
            listsArray.set(valueNum, tempUpdateList);

            stack.push(tempMin);
            listsArray = removeNullArrayList(listsArray);
        }


        /** pop all element from stack */
        if(stack.isEmpty()){
            return null;
        }else{
            ListNode resultList = null;
            while (!stack.isEmpty()){
                int tempNum = (int)stack.pop();
                if(resultList == null){
                    resultList = new ListNode(tempNum);
                }else{
                    ListNode resultTempList = resultList;
                    resultList = new ListNode(tempNum);
                    resultList.next = resultTempList;
                }
            }
            return resultList;
        }
    }

    public static ListNode updateListNode(ListNode nodeTemp){
        if(null != nodeTemp.next){
            return nodeTemp.next;
        }else{
            return null;
        }
    }

    public static List<ListNode> updateArrayList(List<ListNode> lists){
        List<ListNode> listsArray = new ArrayList<>();
        for(ListNode tempListNode : lists){
            if(null != tempListNode.next){
                tempListNode = tempListNode.next;
                listsArray.add(tempListNode);
            }
        }
        return listsArray;
    }

    public static List<ListNode> removeNullArrayList(List<ListNode> lists){
        List<ListNode> listsArray = new ArrayList<>();
        for(ListNode tempListNode : lists){
            if(null != tempListNode){
                listsArray.add(tempListNode);
            }
        }
        return listsArray;
    }

    public static List<ListNode> removeNullList(ListNode[] lists){
        List<ListNode> listsArray = new ArrayList<>();
        for(ListNode tempListNode : lists){
            if(null != tempListNode){
                listsArray.add(tempListNode);
            }
        }
        return listsArray;
    }
}
```