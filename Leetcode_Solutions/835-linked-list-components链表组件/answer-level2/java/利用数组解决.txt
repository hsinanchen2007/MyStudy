思路非常顺畅
因为题目里告诉了我们，链表长度为N，那么内部节点就是0..N - 1
这也就保证了两个内容, 1)节点值不重复：2)节点值可以用数组来代替
所以整体的思路如下：
(1)求出当前链表的长度，这样我们就知道了有哪些节点
(2)新建数组posIndex，posIndex[i] = k 表示第i个节点出现在链表中的第k个位置
(3)新建一个isVisited数组，isVisited[m]表示我们访问了链表中的第m个位置，而m就是(2)中的posIndex[i]，基于此，我们可以知道我们访问了哪些位置。
(4)遍历isVisited，为了加以区分，我加上了一个len，如果len为0，则表示没有找到任何组件，如果len > 0，则表示这一段组件的长度为len，因此，符合实际情况的组件最小长度为1
(5)基于(4)中，我们增加一个count，一旦出现了isVisited[m] == false, 那么就判断len > 0, 如果两个条件同时成立，则count++;
(6)不要忘记循环结束后还可能有len > 0的情况存在，这是因为我们的组件极有可能从i..length - 1


```
        ListNode p = head;
        int N = 0;
        while(p != null){
            N++;
            p = p.next;
        }

        int[] posIndex = new int[N];

        p = head;
        int j = 0;
        while(p != null){
            posIndex[p.val] = j;
            j++;
            p = p.next;
        }

        boolean[] isVisited = new boolean[N];

        for(int g : G){
            isVisited[posIndex[g]] = true;
        }  

        int count = 0;
        int len = 0;
        for(int i = 0; i < N; i++){
            if(isVisited[i]) len++;
            else{
                if(len > 0)count++;
                len = 0;
            }
        }

        if(len > 0) count++;

        return count;
```
