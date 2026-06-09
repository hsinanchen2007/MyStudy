执行用时 : 2 ms, 在所有 Java 提交中击败了95.66%的用户
内存消耗 : 37.6 MB, 在所有 Java 提交中击败了85.61%的用户
先得到长度，然后从长度相等处开始比较。
测试用例的val相等，不代表node是相等的，所以是比较node不是比较val
```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode A = headA;
        ListNode B = headB;
        ListNode intersect = null;
        int lengthA = 0;
        int lengthB = 0;
        if(A == null || B == null){
            return null;
        }
        //计算长度
        while(headA != null || headB != null){
            if(headA != null){
                headA = headA.next;
                lengthA++;
            }
            if(headB != null){
                headB = headB.next;
                lengthB++;
            }
        }

            if(lengthA > lengthB){
                    int length = lengthA - lengthB;
                    for(int i = 0; i < length; i++){
                        A = A.next;
                }}else if(lengthA < lengthB){
                    int length = lengthB - lengthA;
                    for(int i = 0; i < length; i++){
                        B = B.next;
                }
            }
            while(A != null && B != null){
                if(intersect == null && A == B){
                    intersect = A;
                }else if(A.val != B.val){
                    intersect = null;
                }    
                A = A.next;
                B = B.next;
            }
        return intersect;
}
}/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode A = headA;
        ListNode B = headB;
        ListNode intersect = null;
        int lengthA = 0;
        int lengthB = 0;
        if(A == null || B == null){
            return null;
        }
        //计算长度
        while(headA != null || headB != null){
            if(headA != null){
                headA = headA.next;
                lengthA++;
            }
            if(headB != null){
                headB = headB.next;
                lengthB++;
            }
        }

            if(lengthA > lengthB){
                    int length = lengthA - lengthB;
                    for(int i = 0; i < length; i++){
                        A = A.next;
                }}else if(lengthA < lengthB){
                    int length = lengthB - lengthA;
                    for(int i = 0; i < length; i++){
                        B = B.next;
                }
            }
            while(A != null && B != null){
                if(intersect == null && A == B){
                    intersect = A;
                }else if(A.val != B.val){
                    intersect = null;
                }    
                A = A.next;
                B = B.next;
            }
        return intersect;
}
}/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode A = headA;
        ListNode B = headB;
        ListNode intersect = null;
        int lengthA = 0;
        int lengthB = 0;
        if(A == null || B == null){
            return null;
        }
        //计算长度
        while(headA != null || headB != null){
            if(headA != null){
                headA = headA.next;
                lengthA++;
            }
            if(headB != null){
                headB = headB.next;
                lengthB++;
            }
        }

            if(lengthA > lengthB){
                    int length = lengthA - lengthB;
                    for(int i = 0; i < length; i++){
                        A = A.next;
                }}else if(lengthA < lengthB){
                    int length = lengthB - lengthA;
                    for(int i = 0; i < length; i++){
                        B = B.next;
                }
            }
            while(A != null && B != null){
                if(intersect == null && A == B){
                    intersect = A;
                }else if(A.val != B.val){
                    intersect = null;
                }    
                A = A.next;
                B = B.next;
            }
        return intersect;
}
}```
