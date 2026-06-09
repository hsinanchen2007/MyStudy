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
      if()
      if(head.next==null){
       return new int[head.val];
      }
      int[] last = reversePrint(head.next);
      Integer[] la = new Integer[last.length];
      for(int i=0;i<last.length;i++){
        la[i] = Integer.valueOf(last[i]);

      }
      List<Integer> tmp = new ArrayList<>(Arrays.asList(la));
      tmp.add(head.val);
      Integer[] t = tmp.toArray(new Integer[tmp.size()]);
      int[] re =  new int[t.length];
      for(int i=0;i<t.length;i++){
        re[i]= t[i].intValue();
      }
      return re;

    }
}


// class Solution {
//     public int[] reversePrint(ListNode head) {
//       if(head==null){
//         return new int[]{};
//       } 

//       List<Integer> tmp = restack(head,new ArrayList<Integer>());
//       int[] re = new int[tmp.size()];
//       for(int i=0;i<tmp.size();i++){
//         re[i]= tmp.get(i);
//       }
//       return re;
//     }


//     public static List<Integer> restack(ListNode node,List<Integer> a){
//       if(node.next==null){
//         a.add(node.val);
//         return a;
//       }
//       List<Integer> now = restack(node.next,a);
//       now.add(node.val);
//       return now;

//     }    
// } 





























```