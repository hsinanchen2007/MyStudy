    //用双向链表，时间复杂度O(log(nm)),超时
    class Solution {
        public int lastRemaining(int n, int m) {
            //构造链表
            Node node = new Node(0);
            Node head = node;
            for(int i = 1; i < n; i++ ){
                Node newNode = new Node(i);
                newNode.prev = node;
                node.next = newNode;
                node = newNode;
            }
            Node tail = node;
            tail.next = head;
            head.prev = tail;
            //移除第m个节点
            while(head.next != null){
                for(int i = 0; i < m - 1; i++){
                    head = head.next;
                }
                head.prev.next = head.next;
                head.next.prev = head.prev;
                head.prev = null;
                Node tmp = head;
                head = head.next;
                tmp.next = null;
            }
            //最后只剩一个节点，就是结果
            return head.val;
        }
    }
    //链表节点
    class Node{
        int val;
        Node prev;
        Node next;
        Node(int val){
            this.val = val;
        }
    }
![f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg](https://pic.leetcode-cn.com/b88c57ec5fe95f1064c8ba63ff7ee4048a0704cc203090ebe0a0f204caf0bfed-f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg)

    //数学推论
    class Solution {
        public int lastRemaining(int n, int m) {

            //这是f(1,m)
            int result = 0;

            //开始求f(2,m),f(3,m).....f(n,m)
            for(int i = 2; i <= n; i++){

                result = (result + m) % i;

            }
            return  result;
        }
    }
    //f(n,m)为当有n个数时，每次淘汰第m个，最后剩下的一个
    //初始序列0，1，2，3......n-1
    //第一次淘汰k = (m - 1) % n
    //序列变成0, 1, 2, 3, .....k-1,k+1,....n
    //转移一下变成：k+1,k+2,......n,0,1,....k-1
    //这时候序列有n-1个，每次淘汰第m个，最后剩下一个是f(n-1,m)
    //如果知道f(n-1,m)和f(n,m)的关系，就能从f(1,m)推出f(2,m)，一直到f(n,m)
    //f(n-1,m)序列A是0，1，2，。。。。。。n-2
    //f(n,m)淘汰一个以后的序列B是k+1,k+2,......n,0,1,....k-1
    //序列A和序列B都是n-1个淘汰第m个，最后剩下同一个***位置***的数
    //序列A的数为x,序列B上的数为y
    //同一位置对应关系：y = (x + k + 1) % n,
    //最后剩下的数对应关系：f(n,m) = (f(n-1,m) + k + 1) % n
    //将k = (m - 1) % n代入，f(n,m) = (f(n-1,m) + m) % n
    //f(1,m) = 0  f(2,m) = (f(1,m) + m) % 2
    //一直推到f(n,m)