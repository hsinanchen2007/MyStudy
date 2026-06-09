1. 假设有二进制数10101010，将其分为两部分1010101、0。
2. 假设1010101对应的十进制数是a，则10101010对应的十进制数是a*2+0.
3. 同理a也可这样计算得到   a=b*2+1;b是(101010)对应的十进制数
4. 所以有递推公式前面的    十进制数*2+最后一位二进制数
5. 抱歉表达能力不好
class Solution {
    public int getDecimalValue(ListNode head) {
        int num=0;
        ListNode cur=head;
        while(cur!=null){
            num=num*2+cur.val;
            cur=cur.next;
        }
        return num;
    }
}